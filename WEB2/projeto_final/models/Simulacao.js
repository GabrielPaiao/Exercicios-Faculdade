module.exports = (sequelize, DataTypes) => {
    const Simulacao = sequelize.define('Simulacao', {
        descricao: { type: DataTypes.STRING, allowNull: false },
        tipoPhishing: { type: DataTypes.STRING, allowNull: false },
        objetivo: { type: DataTypes.STRING, allowNull: false },
    });

    Simulacao.associate = (models) => {
        Simulacao.belongsTo(models.Usuario, { foreignKey: 'usuarioId', as: 'usuario' });
        Simulacao.belongsTo(models.Equipe, { foreignKey: 'equipeId', as: 'equipe' });
        Simulacao.hasMany(models.Resultado, { foreignKey: 'simulacaoId', as: 'resultados' });
    };

    return Simulacao;
};
