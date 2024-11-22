// models/Feedback.js
module.exports = (sequelize, DataTypes) => {
  const Feedback = sequelize.define('Feedback', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    usuarioId: {
      type: DataTypes.INTEGER,
      allowNull: false,
      references: {
        model: 'Usuarios',
        key: 'id',
      },
      onDelete: 'CASCADE',
    },
    simulacaoId: {
      type: DataTypes.INTEGER,
      allowNull: false,
      references: {
        model: 'Simulacoes',
        key: 'id',
      },
      onDelete: 'CASCADE',
    },
    nota: {
      type: DataTypes.FLOAT,
      allowNull: false,
    },
    comentarios: {
      type: DataTypes.TEXT,
      allowNull: true,
    },
  }, {
    tableName: 'Feedbacks',
    timestamps: true,
  });

  Feedback.associate = (models) => {
    Feedback.belongsTo(models.Usuario, { foreignKey: 'usuarioId', as: 'usuario' });
    Feedback.belongsTo(models.Simulacao, { foreignKey: 'simulacaoId', as: 'simulacao' });
  };

  return Feedback;
};
