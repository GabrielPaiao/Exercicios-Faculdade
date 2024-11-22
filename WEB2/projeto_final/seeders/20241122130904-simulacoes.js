// seeds/simulacaoPhishing.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Simulacoes', [
      {
        descricao: 'Simulação de Phishing com e-mail falso',
        tipo_phishing: 'E-mail',
        objetivo: 'Testar a resposta dos colaboradores',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        descricao: 'Simulação de Phishing com link malicioso',
        tipo_phishing: 'Link',
        objetivo: 'Verificar a interação com links maliciosos',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Simulacoes', null, {});
  },
};

