// models/equipes.js
module.exports = (sequelize, DataTypes) => {
  const Equipes = sequelize.define('Equipes', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    nome: {
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
  }, {
    tableName: 'Equipes',
    timestamps: true,
  });

  Equipes.associate = (models) => {
    Equipes.hasMany(models.Simulacoes, { foreignKey: 'equipeId', as: 'simulacoes' });
  };  

  return Equipes;
};
