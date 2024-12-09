const { Model, DataTypes } = require('sequelize');
const sequelize = require('../config/database');

class Equipe extends Model {}

Equipe.init(
  {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    nomeEquipe: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    responsavel: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    contato: {
      type: DataTypes.STRING,
      allowNull: false,
    },
  },
  {
    sequelize,
    modelName: 'Equipe',
    tableName: 'equipes',
  }
);

module.exports = Equipe;
