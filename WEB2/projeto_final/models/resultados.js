// models/Resultado.js
module.exports = (sequelize, DataTypes) => {
  const Resultado = sequelize.define('Resultado', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
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
    usuarioId: {
      type: DataTypes.INTEGER,
      allowNull: false,
      references: {
        model: 'Usuarios',
        key: 'id',
      },
      onDelete: 'CASCADE',
    },
    status: {
      type: DataTypes.STRING,
      allowNull: false,
    },
  }, {
    tableName: 'Resultados',
    timestamps: true,
  });

  Resultado.associate = (models) => {
    Resultado.belongsTo(models.Simulacao, { foreignKey: 'simulacaoId', as: 'simulacao' });
    Resultado.belongsTo(models.Usuario, { foreignKey: 'usuarioId', as: 'usuario' });
  };

  return Resultado;
};
