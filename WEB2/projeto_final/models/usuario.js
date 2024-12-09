module.exports = (sequelize, DataTypes) => {
  const Usuario = sequelize.define('Usuario', {
      nome: { type: DataTypes.STRING, allowNull: false },
      email: { type: DataTypes.STRING, allowNull: false, unique: true },
      senha: { type: DataTypes.STRING, allowNull: false },
  });

  Usuario.associate = (models) => {
      Usuario.hasMany(models.Simulacao, { foreignKey: 'usuarioId', as: 'simulacoes' });
      Usuario.hasMany(models.Resultado, { foreignKey: 'usuarioId', as: 'resultados' });
      Usuario.hasMany(models.Feedback, { foreignKey: 'usuarioId', as: 'feedbacks' });
  };

  return Usuario;
};
