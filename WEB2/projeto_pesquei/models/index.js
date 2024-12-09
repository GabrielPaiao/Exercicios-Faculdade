const fs = require('fs');
const path = require('path');
const { Sequelize } = require('sequelize');
const sequelize = require('../config/database');

const models = {};

fs.readdirSync(__dirname)
  .filter((file) => file.indexOf('.') !== 0 && file !== 'index.js')
  .forEach((file) => {
    const model = require(path.join(__dirname, file));
    models[model.name] = model;
  });

// Configurar relacionamentos
const { Usuario, Simulacao, Resultado, Feedback, Equipe } = models;

Usuario.hasMany(Resultado, { foreignKey: 'usuarioId' });
Resultado.belongsTo(Usuario, { foreignKey: 'usuarioId' });

Simulacao.hasMany(Resultado, { foreignKey: 'simulacaoId' });
Resultado.belongsTo(Simulacao, { foreignKey: 'simulacaoId' });

Usuario.hasMany(Feedback, { foreignKey: 'usuarioId' });
Feedback.belongsTo(Usuario, { foreignKey: 'usuarioId' });

Simulacao.hasMany(Feedback, { foreignKey: 'simulacaoId' });
Feedback.belongsTo(Simulacao, { foreignKey: 'simulacaoId' });

Equipe.hasMany(Simulacao, { foreignKey: 'equipeId' });
Simulacao.belongsTo(Equipe, { foreignKey: 'equipeId' });

models.sequelize = sequelize;
models.Sequelize = Sequelize;

module.exports = models;
