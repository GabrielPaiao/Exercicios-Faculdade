module.exports = (sequelize, DataTypes) => {
    const Resultado = sequelize.define('Resultado', {
        status: { type: DataTypes.STRING, allowNull: false },
    });

    Resultado.associate = (models) => {
        Resultado.belongsTo(models.Simulacao, { foreignKey: 'simulacaoId', as: 'simulacao' });
        Resultado.belongsTo(models.Usuario, { foreignKey: 'usuarioId', as: 'usuario' });
    };

    return Resultado;
};
