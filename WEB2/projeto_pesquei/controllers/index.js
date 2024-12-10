const bcrypt = require('bcrypt');
const { Sequelize, DataTypes } = require('sequelize');
const sequelize = require('../config/database'); // Importe a instância do Sequelize se necessário

// Definindo as tabelas diretamente nos controllers
const Usuario = sequelize.define('Usuario', {
  nome: { type: DataTypes.STRING, allowNull: false },
  email: { type: DataTypes.STRING, allowNull: false, unique: true },
  cargo: { type: DataTypes.STRING },
  departamento: { type: DataTypes.STRING },
  senha: { type: DataTypes.STRING, allowNull: false }
}, 
);

const Simulacao = sequelize.define('Simulacoes', {
  dataSimulacao: { type: DataTypes.DATE, allowNull: false },
  descricao: { type: DataTypes.STRING },
  tipoPhishing: { type: DataTypes.STRING },
  objetivo: { type: DataTypes.STRING },
  equipeId: { type: DataTypes.INTEGER, references: { model: 'Equipes', key: 'id' } }
}, {
  freezeTableName: true // Evita a pluralização do nome da tabela
});

const Resultado = sequelize.define('Resultado', {
  simulacaoId: { type: DataTypes.INTEGER, references: { model: 'Simulacao', key: 'id' } },
  usuarioId: { type: DataTypes.INTEGER, references: { model: 'Usuario', key: 'id' } },
  status: { type: DataTypes.STRING },
  dataResultado: { type: DataTypes.DATE }
});

const Feedback = sequelize.define('Feedback', {
  usuarioId: { type: DataTypes.INTEGER, references: { model: 'Usuario', key: 'id' } },
  simulacaoId: { type: DataTypes.INTEGER, references: { model: 'Simulacao', key: 'id' } },
  dataFeedback: { type: DataTypes.DATE },
  nota: { type: DataTypes.INTEGER },
  comentarios: { type: DataTypes.STRING }
});

const Equipe = sequelize.define('Equipe', {
  nomeEquipe: { type: DataTypes.STRING },
  responsavel: { type: DataTypes.STRING },
  contato: { type: DataTypes.STRING }
});

// Controllers

const usuarioController = {
  renderListPage: (req, res) => {
    usuarioController.list()
      .then(usuarios => {
        res.render('users/index', { usuarios, title: 'Lista de Usuários' });
      })
      .catch(err => {
        console.error('Erro ao carregar usuários:', err);
        res.status(500).send('Erro ao carregar usuários');
      });
  },

  create: async (req, res) => {
    try {
      const { nome, email, cargo, departamento, senha } = req.body;
      const hashedPassword = await bcrypt.hash(senha, 10);
      const novoUsuario = await Usuario.create({
        nome,
        email,
        cargo,
        departamento,
        senha: hashedPassword,
        dataCadastro: new Date(),
      });
      res.status(201).json(novoUsuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar usuário.' });
    }
  },

  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { nome, email, cargo, departamento } = req.body;
      const usuario = await Usuario.findByPk(id);

      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado.' });
      }

      await usuario.update({ nome, email, cargo, departamento });
      res.status(200).json(usuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar usuário.' });
    }
  },

  list: async () => {
    try {
      const usuarios = await Usuario.findAll();
      return usuarios;
    } catch (error) {
      console.error('Erro ao listar usuários:', error);
      throw new Error('Erro ao listar usuários.');
    }
  },

  delete: async (req, res) => {
    try {
      const { id } = req.params;
      const usuario = await Usuario.findByPk(id);

      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado.' });
      }

      await usuario.destroy();
      res.status(200).json({ message: 'Usuário excluído com sucesso.' });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir usuário.' });
    }
  },
};

const authController = {
  isLoggedIn: (req, res, next) => {
    if (req.session && req.session.usuarioId) {
      return next();
    }
    return res.redirect('/login');
  },

  login: async (req, res) => {
    try {
      const { email, senha } = req.body;
      const usuario = await Usuario.findOne({ where: { email } });

      if (!usuario) {
        return res.status(401).send('Usuário não encontrado.');
      }

      const senhaValida = await bcrypt.compare(senha, usuario.senha);

      if (!senhaValida) {
        return res.status(401).send('Senha inválida.');
      }

      req.session.usuarioId = usuario.id;
      req.session.usuarioNome = usuario.nome;
      return res.redirect('/home');
    } catch (error) {
      console.error('Erro ao fazer login:', error);
      res.status(500).json({ error: 'Erro ao fazer login.' });
    }
  },

  logout: (req, res) => {
    req.session.destroy((err) => {
      if (err) {
        return res.status(500).send('Erro ao sair.');
      }
      res.redirect('/login');
    });
  },

  register: async (req, res) => {
    try {
      const { nome, email, cargo, departamento, senha } = req.body;

      const usuarioExistente = await Usuario.findOne({ where: { email } });
      if (usuarioExistente) {
        return res.status(400).send('Email já cadastrado.');
      }

      const senhaCriptografada = await bcrypt.hash(senha, 10);

      const novoUsuario = await Usuario.create({
        nome,
        email,
        cargo,
        departamento,
        senha: senhaCriptografada,
      });

      res.redirect('/login');
    } catch (error) {
      console.error('Erro ao registrar usuário:', error);
      res.status(500).json({ error: 'Erro ao registrar usuário.' });
    }
  },
};

const simulacaoController = {
  renderListPage: (req, res) => {
    Simulacao.findAll()
      .then(simulacoes => {
        res.render('simulations/index', { simulacoes });  // Correção aqui
      })
      .catch(err => {
        console.error('Erro ao carregar simulações:', err);
        res.status(500).send('Erro ao carregar simulações');
      });
  },
  
  create: async (req, res) => {
    try {
      const { dataSimulacao, descricao, tipoPhishing, objetivo, idEquipe } = req.body;
      const novaSimulacao = await Simulacao.create({
        dataSimulacao,
        descricao,
        tipoPhishing,
        objetivo,
        equipeId: idEquipe,
      });
      res.status(201).json(novaSimulacao);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar simulação.' });
    }
  },

  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { dataSimulacao, descricao, tipoPhishing, objetivo, idEquipe } = req.body;

      const simulacao = await Simulacao.findByPk(id);

      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada.' });
      }

      await simulacao.update({ dataSimulacao, descricao, tipoPhishing, objetivo, equipeId: idEquipe });
      res.status(200).json(simulacao);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar simulação.' });
    }
  },

  delete: async (req, res) => {
    try {
      const { id } = req.params;
      const simulacao = await Simulacao.findByPk(id);

      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada.' });
      }

      await simulacao.destroy();
      res.status(200).json({ message: 'Simulação excluída com sucesso.' });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir simulação.' });
    }
  },

  list: async (req, res) => {
    try {
      const simulacoes = await Simulacao.findAll();
      res.status(200).json(simulacoes);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar simulações.' });
    }
  },
};

const resultadoController = {
  //render index
  renderListPage: (req, res) => {
    resultadoController.list()
      .then(resultados => {
        res.render('results/index', { resultados });
      })
      .catch(err => {
        console.error('Erro ao carregar resultados:', err);
        res.status(500).send('Erro ao carregar resultados');
      });
  },

  create: async (req, res) => {
    try {
      const { idSimulacao, idUsuario, status, dataResultado } = req.body;
      const novoResultado = await Resultado.create({
        simulacaoId: idSimulacao,
        usuarioId: idUsuario,
        status,
        dataResultado,
      });
      res.status(201).json(novoResultado);
    } catch (error) {
      console.error('Erro ao criar resultado:', error);
      res.status(500).json({ error: 'Erro ao criar resultado.' });
    }
  },

  // Atualizar Resultado
  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { status, dataResultado } = req.body;

      const resultado = await Resultado.findByPk(id);
      if (!resultado) {
        return res.status(404).json({ error: 'Resultado não encontrado.' });
      }

      await resultado.update({ status, dataResultado });
      res.status(200).json(resultado);
    } catch (error) {
      console.error('Erro ao atualizar resultado:', error);
      res.status(500).json({ error: 'Erro ao atualizar resultado.' });
    }
  },

  // Listar todos os Resultados
  list: async () => {
    try {
      const resultados = await Resultado.findAll();
      return resultados;
    } catch (error) {
      console.error('Erro ao listar resultados:', error);
      throw new Error('Erro ao listar resultados.');
    }
  },
};

const feedbackController = {
  //render index
  renderListPage: (req, res) => {
    feedbackController.list()
      .then(feedbacks => {
        res.render('feedbacks/index', { feedbacks });
      })
      .catch(err => {
        console.error('Erro ao carregar feedbacks:', err);
        res.status(500).send('Erro ao carregar feedbacks');
      });
  },

  create: async (req, res) => {
    try {
      const { idUsuario, idSimulacao, dataFeedback, nota, comentarios } = req.body;
      const novoFeedback = await Feedback.create({
        usuarioId: idUsuario,
        simulacaoId: idSimulacao,
        dataFeedback,
        nota,
        comentarios,
      });
      res.status(201).json(novoFeedback);
    } catch (error) {
      console.error('Erro ao criar feedback:', error);
      res.status(500).json({ error: 'Erro ao criar feedback.' });
    }
  },

  // Atualizar Feedback
  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { nota, comentarios, dataFeedback } = req.body;

      const feedback = await Feedback.findByPk(id);
      if (!feedback) {
        return res.status(404).json({ error: 'Feedback não encontrado.' });
      }

      await feedback.update({ nota, comentarios, dataFeedback });
      res.status(200).json(feedback);
    } catch (error) {
      console.error('Erro ao atualizar feedback:', error);
      res.status(500).json({ error: 'Erro ao atualizar feedback.' });
    }
  },

  // Excluir Feedback
  delete: async (req, res) => {
    try {
      const { id } = req.params;
      const feedback = await Feedback.findByPk(id);

      if (!feedback) {
        return res.status(404).json({ error: 'Feedback não encontrado.' });
      }

      await feedback.destroy();
      res.status(200).json({ message: 'Feedback excluído com sucesso.' });
    } catch (error) {
      console.error('Erro ao excluir feedback:', error);
      res.status(500).json({ error: 'Erro ao excluir feedback.' });
    }
  },

  // Listar todos os Feedbacks
  list: async () => {
    try {
      const feedbacks = await Feedback.findAll();
      return feedbacks;
    } catch (error) {
      console.error('Erro ao listar feedbacks:', error);
      throw new Error('Erro ao listar feedbacks.');
    }
  },
};

const equipeController = {
  //render index
  renderListPage: (req, res) => {
    equipeController.list()
      .then(equipes => {
        res.render('teams/index', { equipes });
      })
      .catch(err => {
        console.error('Erro ao carregar equipes:', err);
        res.status(500).send('Erro ao carregar equipes');
      });
  },

  create: async (req, res) => {
    try {
      const { nomeEquipe, responsavel, contato } = req.body;
      const novaEquipe = await Equipe.create({ nomeEquipe, responsavel, contato });
      res.status(201).json(novaEquipe);
    } catch (error) {
      console.error('Erro ao criar equipe:', error);
      res.status(500).json({ error: 'Erro ao criar equipe.' });
    }
  },

  // Atualizar Equipe
  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { nomeEquipe, responsavel, contato } = req.body;

      const equipe = await Equipe.findByPk(id);
      if (!equipe) {
        return res.status(404).json({ error: 'Equipe não encontrada.' });
      }

      await equipe.update({ nomeEquipe, responsavel, contato });
      res.status(200).json(equipe);
    } catch (error) {
      console.error('Erro ao atualizar equipe:', error);
      res.status(500).json({ error: 'Erro ao atualizar equipe.' });
    }
  },

  // Excluir Equipe
  delete: async (req, res) => {
    try {
      const { id } = req.params;
      const equipe = await Equipe.findByPk(id);

      if (!equipe) {
        return res.status(404).json({ error: 'Equipe não encontrada.' });
      }

      await equipe.destroy();
      res.status(200).json({ message: 'Equipe excluída com sucesso.' });
    } catch (error) {
      console.error('Erro ao excluir equipe:', error);
      res.status(500).json({ error: 'Erro ao excluir equipe.' });
    }
  },

  // Listar todas as Equipes
  list: async () => {
    try {
      const equipes = await Equipe.findAll();
      return equipes;
    } catch (error) {
      console.error('Erro ao listar equipes:', error);
      throw new Error('Erro ao listar equipes.');
    }
  },
};

module.exports = {
  usuarioController,
  simulacaoController,
  resultadoController,
  feedbackController,
  equipeController,
  authController,
};
