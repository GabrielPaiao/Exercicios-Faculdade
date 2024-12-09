const { Model, DataTypes } = require('sequelize');
const sequelize = require('../config/database');

class Feedback extends Model {}

Feedback.init(
  {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    dataFeedback: {
      type: DataTypes.DATE,
      allowNull: false,
    },
    nota: {
      type: DataTypes.INTEGER,
      allowNull: false,
    },
    comentarios: {
      type: DataTypes.TEXT,
      allowNull: true,
    },
  },
  {
    sequelize,
    modelName: 'Feedback',
    tableName: 'feedbacks',
  }
);

module.exports = Feedback;
