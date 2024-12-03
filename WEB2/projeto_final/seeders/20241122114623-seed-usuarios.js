module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Usuarios', [
      {
        nome: 'Carlos Alberto',
        email: 'usuario1@exemplo.com',
        cargo: 'Analista de TI',
        departamento: 'TI',
        senha: 'teste123',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        nome: 'Ana Souza',
        email: 'usuario2@exemplo.com',
        cargo: 'Gerente de Segurança',
        departamento: 'Segurança',
        senha: 'teste123',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Usuarios', null, {});
  },
};
