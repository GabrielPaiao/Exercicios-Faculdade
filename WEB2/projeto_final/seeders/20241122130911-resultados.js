// seeds/resultadoSimulacao.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('ResultadosSimulacao', [
      {
        id_simulacao: 1,
        id_usuario: 1,
        status: 'Vulnerável',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        id_simulacao: 2,
        id_usuario: 2,
        status: 'Seguro',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('ResultadosSimulacao', null, {});
  },
};
