'use strict';
module.exports = {
  async up(queryInterface, Sequelize) {
    await queryInterface.createTable('Resultados', {
      id: { type: Sequelize.INTEGER, autoIncrement: true, primaryKey: true },
      usuarioId: {
        type: Sequelize.INTEGER,
        references: { model: 'Usuarios', key: 'id' },
        onDelete: 'CASCADE',
      },
      simulacaoId: {
        type: Sequelize.INTEGER,
        references: { model: 'Simulacoes', key: 'id' },
        onDelete: 'CASCADE',
      },      
      status: { type: Sequelize.STRING, allowNull: false },
      createdAt: { type: Sequelize.DATE, allowNull: false, defaultValue: Sequelize.fn('NOW') },
      updatedAt: { type: Sequelize.DATE, allowNull: false, defaultValue: Sequelize.fn('NOW') },
    });
  },
  async down(queryInterface, Sequelize) {
    await queryInterface.dropTable('Resultados');
  },
};
