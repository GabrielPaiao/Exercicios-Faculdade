// seeds/feedbackTreinamento.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Feedbacks', [
      {
        id_simulacao: 1,
        id_usuario: 1,
        id_resultado: 1,
        nota: 4.5,
        comentarios: 'O treinamento foi bom, mas faltou mais exemplos práticos.',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        id_simulacao: 2,
        id_usuario: 2,
        id_resultado: 2,
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
