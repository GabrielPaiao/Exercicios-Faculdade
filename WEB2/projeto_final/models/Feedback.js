module.exports = (sequelize, DataTypes) => {
    const Feedback = sequelize.define('Feedback', {
        comentario: { type: DataTypes.STRING, allowNull: false },
    });

    Feedback.associate = (models) => {
        Feedback.belongsTo(models.Simulacao, { foreignKey: 'simulacaoId', as: 'simulacao' });
        Feedback.belongsTo(models.Usuario, { foreignKey: 'usuarioId', as: 'usuario' });
    };

    return Feedback;
};
