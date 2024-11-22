'use strict';
module.exports = {
  async up(queryInterface, Sequelize) {
    await queryInterface.createTable('Simulacoes', {
      id: { type: Sequelize.INTEGER, autoIncrement: true, primaryKey: true },
      descricao: { type: Sequelize.STRING, allowNull: false },
      tipoPhishing: { type: Sequelize.STRING, allowNull: false },
      objetivo: { type: Sequelize.STRING, allowNull: false },
      id_usuario: {
        type: Sequelize.INTEGER,
        references: { model: 'Usuarios', key: 'id' },
        onDelete: 'CASCADE',
      },
      createdAt: { type: Sequelize.DATE, allowNull: false, defaultValue: Sequelize.fn('NOW') },
      updatedAt: { type: Sequelize.DATE, allowNull: false, defaultValue: Sequelize.fn('NOW') },
    });
  },
  async down(queryInterface, Sequelize) {
    await queryInterface.dropTable('Simulacoes');
  },
};
