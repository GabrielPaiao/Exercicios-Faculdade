const fs = require('fs');
const path = require('path');
const Sequelize = require('sequelize');
const sequelize = require('../config/database');

// Para importar todos os modelos automaticamente
const db = {};

fs.readdirSync(__dirname)
  .filter((file) => file !== 'index.js')  // Ignora o próprio arquivo 'index.js'
  .forEach((file) => {
    const model = require(path.join(__dirname, file))(sequelize, Sequelize.DataTypes);
    db[model.name] = model;  // Adiciona o modelo ao objeto db
  });

// Associar modelos entre si, caso existam relações
Object.keys(db).forEach((modelName) => {
  if (db[modelName].associate) {
    db[modelName].associate(db);  // Chama o método associate (se existir) para associar os modelos
  }
});

db.sequelize = sequelize;
db.Sequelize = Sequelize;

module.exports = db;
