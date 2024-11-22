// seeds/usuarios.js
module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.bulkInsert('Usuarios', [
      {
        email: 'usuario1@exemplo.com',
        cargo: 'Analista de TI',
        departamento: 'TI',
        nome: 'Carlos Alberto',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        email: 'usuario2@exemplo.com',
        cargo: 'Gerente de Segurança',
        departamento: 'Segurança',
        nome: 'Ana Souza',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.bulkDelete('Usuarios', null, {});
  },
};
