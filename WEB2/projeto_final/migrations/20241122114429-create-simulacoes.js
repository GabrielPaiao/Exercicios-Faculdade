//migration create-simulacoes
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.createTable('Simulacoes', {
      id: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true,
      },
      descricao: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      tipoPhishing: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      objetivo: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      usuarioId: {
        type: Sequelize.INTEGER,
        allowNull: false,
        references: {
          model: 'Usuarios',
          key: 'id',
        },
        onDelete: 'CASCADE',
      },
      equipeId: {
        type: Sequelize.INTEGER,
        allowNull: false,
        references: {
          model: 'Equipes',
          key: 'id',
        },
        onDelete: 'CASCADE',
      },
      createdAt: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      updatedAt: {
        type: Sequelize.DATE,
        allowNull: false,
      },
    });
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.dropTable('Simulacoes');
  },
};
