// config/database.js
const { Sequelize } = require('sequelize');

const sequelize = new Sequelize({
  dialect: 'mysql', 
  host: 'localhost',
  username: 'root', 
  password: 'admin',
  database: 'pesquei',  
  logging: false,  
});

// Testa a conexão
sequelize.authenticate()
  .then(() => {
    console.log('Conexão bem-sucedida com o banco de dados!');
  })
  .catch((err) => {
    console.error('Erro ao conectar ao banco de dados:', err);
  });

module.exports = sequelize;
