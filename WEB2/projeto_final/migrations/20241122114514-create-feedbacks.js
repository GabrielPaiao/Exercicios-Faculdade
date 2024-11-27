'use strict';
module.exports = {
  async up(queryInterface, Sequelize) {
    await queryInterface.createTable('Feedbacks', {
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
      nota: { type: Sequelize.FLOAT, allowNull: false },
      comentarios: { type: Sequelize.STRING },
      createdAt: { type: Sequelize.DATE, allowNull: false, defaultValue: Sequelize.fn('NOW') },
      updatedAt: { type: Sequelize.DATE, allowNull: false, defaultValue: Sequelize.fn('NOW') },
    });
  },
  async down(queryInterface, Sequelize) {
    await queryInterface.dropTable('Feedbacks');
  },
};
