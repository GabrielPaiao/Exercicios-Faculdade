module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Simulacoes', [
      {
        descricao: 'Simulação de Phishing com e-mail falso',
        tipoPhishing: 'E-mail',
        objetivo: 'Testar a resposta dos colaboradores',
        usuarioId: 1, // ID de um usuário existente
        equipeId: 1, // ID de uma equipe existente
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        descricao: 'Simulação de Phishing com link malicioso',
        tipoPhishing: 'Link',
        objetivo: 'Verificar a interação com links maliciosos',
        usuarioId: 2, // ID de um usuário existente
        equipeId: 2, // ID de uma equipe existente
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
    
  },
  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Simulacoes', null, {});
  },
};
