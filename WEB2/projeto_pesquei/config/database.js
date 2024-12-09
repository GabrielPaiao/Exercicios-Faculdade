const { Sequelize } = require('sequelize');

// Configurando a conexão com o banco de dados MySQL
const sequelize = new Sequelize('nome_do_banco', 'usuario', 'senha', {
  host: 'localhost',
  dialect: 'mysql',
  logging: false, // Desabilita logs no console
});

// Testando a conexão com o banco
sequelize.authenticate()
  .then(() => {
    console.log('Conexão com o banco de dados bem-suced!');
  })
  .catch((error) => {
    console.error('Erro ao conectar com o banco de dados:', error);
  });

module.exports = sequelize;
