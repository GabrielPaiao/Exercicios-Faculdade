// seeds/resultados.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Resultados', [
      {
        simulacaoId: 1,  // ID de uma Simulação existente
        usuarioId: 1,    // ID de um Usuário existente
        status: 'Vulnerável',  // Status que pode ser 'Vulnerável', 'Seguro', etc.
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        simulacaoId: 2,  // ID de uma Simulação existente
        usuarioId: 2,    // ID de um Usuário existente
        status: 'Seguro',  // Status que pode ser 'Vulnerável', 'Seguro', etc.
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Resultados', null, {});
  },
};
