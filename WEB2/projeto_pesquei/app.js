const express = require('express');
const session = require('express-session');
const bodyParser = require('body-parser');
const path = require('path');
const routes = require('./routes');
const ejsLayouts = require('express-ejs-layouts');

const app = express();
const PORT = process.env.PORT || 3000;

// Middlewares
app.use(express.static(path.join(__dirname, 'public')));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Configuração de sessões
app.use(
  session({
    secret: 'admin',
    resave: false,
    saveUninitialized: true,
    cookie: { secure: false, maxAge: 15 * 60 * 1000 } //sessao termina em 15 minutos
  })
);

// Configuração de EJS
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.use(ejsLayouts);
app.locals.layout = 'layout';
app.set('layout', 'layout'); // Define o layout padrão

app.use((req, res, next) => {
  res.locals.title = 'Pesquei'; // Define um valor padrão para `title`
  next();
});

// Configurar rotas
app.use('/', routes);

app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});

// Middleware de tratamento de erros
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).json({ error: 'Algo deu errado no servidor!' });
});
