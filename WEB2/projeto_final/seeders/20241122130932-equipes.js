// seeds/equipeSeguranca.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('EquipesSeguranca', [
      {
        nome_equipe: 'Equipe A',
        responsavel: 'João Silva',
        contato: 'contato@exemplo.com',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        nome_equipe: 'Equipe B',
        responsavel: 'Maria Oliveira',
        contato: 'contato2@exemplo.com',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('EquipesSeguranca', null, {});
  },
};
