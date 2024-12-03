module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Feedbacks', [
      {
        simulacaoId: 1,
        usuarioId: 1,
        nota: 4.5,
        comentarios: 'O treinamento foi bom, mas faltou mais exemplos práticos.',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        simulacaoId: 2,
        usuarioId: 2,
        nota: 5,
        comentarios: 'Excelente, consegui identificar rapidamente os riscos.',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Feedbacks', null, {});
  },
};
