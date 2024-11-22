// models/Usuario.js
module.exports = (sequelize, DataTypes) => {
  const Usuario = sequelize.define('Usuario', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    nome: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    email: {
      type: DataTypes.STRING,
      allowNull: false,
      unique: true,
    },
    cargo: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    departamento: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    senha: {
      type: DataTypes.STRING,
      allowNull: false,
    },
  }, {
    tableName: 'Usuarios',
    timestamps: true,
  });

  Usuario.associate = (models) => {
    Usuario.hasMany(models.Simulacao, { foreignKey: 'usuarioId', as: 'simulacoes' });
    Usuario.hasMany(models.Resultado, { foreignKey: 'usuarioId', as: 'resultados' });
    Usuario.hasOne(models.Feedback, { foreignKey: 'usuarioId', as: 'feedback' });
  };

  return Usuario;
};
