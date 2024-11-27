const express = require('express');
const app = express();
const path = require('path');
const methodOverride = require('method-override');
const bodyParser = require('body-parser');
const session = require('express-session');
const expressLayouts = require('express-ejs-layouts');

// Middleware de autenticação
const authenticate = require('./middlewares/authenticate');

// Configuração de view engine
app.use(expressLayouts);
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.set('layout', 'layouts/main');

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride('_method'));
app.use(session({
  secret: 'secret-key', // Modifique para algo mais seguro em produção
  resave: false,
  saveUninitialized: true,
  cookie: { secure: false }  // Se estiver usando HTTPS, defina como true
}));

// Middleware para passar o userId para as views
app.use((req, res, next) => {
  res.locals.userId = req.session.userId;  // Torna userId disponível nas views
  next();
});

// Simulação de dados (para testes)
const simulacoesData = [
  { id: 1, tipo: 'Phishing por E-mail', descricao: 'Simulação de ataque por e-mail' },
  { id: 2, tipo: 'Phishing por SMS', descricao: 'Simulação de ataque por SMS' },
];

// Rotas principais
app.get('/', (req, res) => {
  res.render('index', { title: 'Home' });
});

// Importar e registrar rotas
const authRoutes = require('./routes/auth');  // Rota de autenticação (login, register, logout)
const simulacoesRoutes = require('./routes/simulacoes');
const equipesRoutes = require('./routes/equipes');
const feedbacksRoutes = require('./routes/feedback');
const resultadosRoutes = require('./routes/resultados');
const usuariosRoutes = require('./routes/usuarios');

// Definindo rotas de autenticação
app.use('/auth', authRoutes);  // Rota para login, register e logout

// Definindo as rotas para outras funcionalidades
// O middleware de autenticação é adicionado para garantir que o usuário esteja logado
app.use('/simulacoes', authenticate, simulacoesRoutes);  
// app.js
app.use('/equipes', authenticate, equipesRoutes);
app.use('/feedbacks', authenticate, feedbacksRoutes);
app.use('/resultados', authenticate, resultadosRoutes);
app.use('/usuarios', authenticate, usuariosRoutes);

// Iniciar o servidor
app.listen(3000, () => {
  console.log('Servidor rodando na porta 3000');
});
