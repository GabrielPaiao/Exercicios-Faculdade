const express = require('express');
const session = require('express-session');
const bodyParser = require('body-parser');
const path = require('path');
const routes = require('./routes');
const sequelize = require('./config/database');
const { isAuthenticated } = require('./middlewares/authMiddleware'); // Middleware para controle de autenticação

const app = express();
const PORT = process.env.PORT || 3000;

// Middlewares
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Configuração de sessões
app.use(
  session({
    secret: 'chave-secreta',
    resave: false,
    saveUninitialized: true,
  })
);

// Configuração de EJS
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// Conectar ao banco e inicializar rotas após sucesso da conexão
sequelize.sync()
  .then(() => {
    console.log('Banco de dados sincronizado com sucesso.');

    // Configurar rotas com autenticação
    app.use('/api', isAuthenticated, routes);

    app.listen(PORT, () => {
      console.log(`Servidor rodando em http://localhost:${PORT}`);
    });
  })
  .catch((error) => {
    console.error('Erro ao conectar ao banco de dados:', error);
  });

// Middleware de tratamento de erros
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).json({ error: 'Algo deu errado no servidor!' });
});

module.exports = app;
