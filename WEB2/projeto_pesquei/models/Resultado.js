const { Model, DataTypes } = require('sequelize');
const sequelize = require('../config/database');

class Resultado extends Model {}

Resultado.init(
  {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    status: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    dataResultado: {
      type: DataTypes.DATE,
      allowNull: false,
    },
  },
  {
    sequelize,
    modelName: 'Resultado',
    tableName: 'resultados',
  }
);

module.exports = Resultado;
