// seeds/equipes.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Equipes', [
      {
        nome: 'Equipe A',
        responsavel: 'João Silva',
        contato: 'contato@exemplo.com',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        nome: 'Equipe B',
        responsavel: 'Maria Oliveira',
        contato: 'contato2@exemplo.com',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Equipes', null, {});
  },
};
