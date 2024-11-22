// models/Simulacao.js
module.exports = (sequelize, DataTypes) => {
  const Simulacoes = sequelize.define('Simulacoes', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
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
    usuarioId: { // FK para Usuario
      type: DataTypes.INTEGER,
      references: {
        model: 'Usuarios',
        key: 'id',
      },
      onDelete: 'CASCADE',
    },
    equipeId: { // FK para Equipe
      type: DataTypes.INTEGER,
      references: {
        model: 'Equipes',
        key: 'id',
      },
      onDelete: 'CASCADE',
    },
  }, {
    tableName: 'Simulacoes',
    timestamps: true,
  });

  Simulacoes.associate = (models) => {
    Simulacoes.belongsTo(models.Usuario, { foreignKey: 'usuarioId', as: 'usuario' });
    Simulacoes.belongsTo(models.Equipe, { foreignKey: 'equipeId', as: 'equipe' });
    Simulacoes.hasMany(models.Resultado, { foreignKey: 'simulacaoId', as: 'resultados' });
    Simulacoes.hasMany(models.Feedback, { foreignKey: 'simulacaoId', as: 'feedbacks' });
  };

  return Simulacao;
};
