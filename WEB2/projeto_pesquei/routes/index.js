const express = require('express');
const sequelize = require('../config/database');

const {
  usuarioController,
  simulacaoController,
  resultadoController,
  feedbackController,
  equipeController,
  authController,
} = require('../controllers');
const { requireLogin } = require('../middlewares/authMiddleware');

const router = express.Router();

// Rota inicial - redireciona para login ou home
router.get('/', (req, res) => {
  console.log('Sessão na rota inicial:', req.session);
  if (req.session && req.session.usuarioId) {
    return res.redirect('/home'); // Redireciona para a home se autenticado
  }
  res.redirect('/login'); // Redireciona para o login se não autenticado
});

// Página Home
router.get('/home', requireLogin, (req, res) => {
  console.log('Sessão na home:', req.session);
  if (!req.session.usuarioNome) {
    return res.status(500).send('Erro: Nome do usuário não encontrado na sessão.');
  }
  res.render('home', { user: { nome: req.session.usuarioNome } });
});

// Rotas de Usuários
router.post('/usuarios', requireLogin, usuarioController.create);
router.put('/usuarios/:id', requireLogin, usuarioController.update);
router.get('/usuarios', requireLogin, usuarioController.renderListPage);
router.delete('/usuarios/:id', requireLogin, usuarioController.delete);
router.get('/usuarios/form', requireLogin, (req, res) => {
  res.render('users/form', { title: 'Cadastrar Novo Usuário', usuario: null });
});
router.get('/usuarios/form/:id', requireLogin, async (req, res) => {
  try {
    const { id } = req.params;

    // Consulta SQL para buscar o usuário diretamente pela ID
    const [usuario] = await sequelize.query(
      'SELECT * FROM Usuarios WHERE id = :id',
      {
        replacements: { id },
        type: sequelize.QueryTypes.SELECT, // Tipo de consulta (SELECT)
      }
    );

    if (!usuario) {
      return res.status(404).send('Usuário não encontrado.');
    }

    // Renderiza o formulário com os dados do usuário
    res.render('users/form', { title: 'Editar Usuário', usuario });
  } catch (error) {
    console.error('Erro ao carregar usuário para edição:', error);
    res.status(500).send('Erro ao carregar usuário.');
  }
});


// Rotas de Simulações
router.post('/simulacoes', simulacaoController.create);
router.put('/simulacoes/:id', simulacaoController.update);
router.get('/simulacoes', simulacaoController.renderListPage);
router.delete('/simulacoes/:id', simulacaoController.delete);

// Rotas de Resultados
router.post('/resultados', resultadoController.create);
router.put('/resultados/:id', resultadoController.update);
router.get('/resultados', resultadoController.renderListPage);

// Rotas de Feedback
router.post('/feedbacks', requireLogin, feedbackController.create);
router.put('/feedbacks/:id', requireLogin, feedbackController.update);
router.get('/feedbacks', requireLogin, feedbackController.renderListPage);
router.delete('/feedbacks/:id', requireLogin, feedbackController.delete);

// Rotas de Equipes
router.post('/equipes', requireLogin, equipeController.create);
router.put('/equipes/:id', requireLogin, equipeController.update);
router.get('/equipes', requireLogin, equipeController.renderListPage);
router.delete('/equipes/:id', requireLogin, equipeController.delete);
// Renderizar o formulário para criar uma equipe
router.get('/equipes/form', (req, res) => {
  const equipe = null; 
  res.render('teams/form', { equipe });
});
router.get('/equipes/form/:id', async (req, res) => {
  try {
      const id = req.params.id;
      const equipe = await sequelize.query('SELECT * FROM equipes WHERE id = :id', {
          replacements: { id },
          type: sequelize.QueryTypes.SELECT
      });
      res.render('teams/form', { equipe: equipe[0] }); // Passa a equipe encontrada
  } catch (error) {
      res.status(500).send('Erro ao carregar a equipe');
  }
});



// Rota para lidar com o envio do formulário
router.post('/equipes', async (req, res) => {
  const { nome, descricao } = req.body;

  try {
    // Inserir a nova equipe no banco de dados
    await sequelize.query(
      'INSERT INTO Equipes (nome, descricao) VALUES (:nome, :descricao)',
      { replacements: { nome, descricao } }
    );

    res.redirect('/equipes'); // Redirecionar para a lista de equipes
  } catch (err) {
    console.error('Erro ao criar equipe:', err);
    res.status(500).send('Erro ao criar equipe.');
  }
});

// Rotas de Autenticação
router.get('/login', (req, res) => res.render('auth/login')); // Página de login
router.post('/login', authController.login);
router.get('/logout', (req, res) => res.render('auth/login')); // Página de login
router.post('/logout', authController.logout);
router.get('/register', (req, res) => res.render('auth/register'));
router.post('/register', authController.register)

module.exports = router;
