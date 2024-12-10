module.exports = (sequelize, DataTypes) => {
    const Equipe = sequelize.define('Equipe', {
        nome: { type: DataTypes.STRING, allowNull: false },
    });

    return Equipe;
};
