const { Model, DataTypes } = require('sequelize');
const sequelize = require('../config/database');

class Simulacao extends Model {}

Simulacao.init(
  {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    dataSimulacao: {
      type: DataTypes.DATE,
      allowNull: false,
    },
    descricao: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    tipoPhishing: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    objetivo: {
      type: DataTypes.STRING,
      allowNull: false,
    },
  },
  {
    sequelize,
    modelName: 'Simulacao',
    tableName: 'simulacoes',
  }
);

module.exports = Simulacao;
