const express = require('express');
const app = express();
const path = require('path');
const methodOverride = require('method-override');
const bodyParser = require('body-parser');
const session = require('express-session');

const expressLayouts = require('express-ejs-layouts');
app.use(expressLayouts);

// Configuração de view engine
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.set('layout', 'layouts/main');  // Defina o layout como 'layouts/main.ejs'

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride('_method'));
app.use(session({
  secret: 'secret-key',
  resave: false,
  saveUninitialized: true
}));

// Rotas
app.get('/', (req, res) => {
  res.render('index', { title: 'Home' });
});

// Rotas de Simulações
app.get('/simulacoes', (req, res) => {
  // Aqui você pega as simulações do banco de dados
  res.render('simulacoes/index', { simulacoes: simulacoesData });
});

app.get('/simulacoes/create', (req, res) => {
  res.render('simulacoes/create', { usuarios: usuariosData, equipes: equipesData });
});

// Outras rotas de simulações, feedbacks, equipes, etc...

// Iniciar o servidor
app.listen(3000, () => {
  console.log('Servidor rodando na porta 3000');
});
