module.exports = {
  up: async (queryInterface, Sequelize) => {
    // Inserindo dados na tabela 'equipes'
    await queryInterface.bulkInsert('equipes', [
      {
        nomeEquipe: 'Equipe 1',
        responsavel: 'Responsável 1',
        contato: 'contato@equipe1.com',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        nomeEquipe: 'Equipe 2',
        responsavel: 'Responsável 2',
        contato: 'contato@equipe2.com',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);

    // Inserindo dados na tabela 'usuarios'
    await queryInterface.bulkInsert('usuarios', [
      {
        nome: 'Usuário 1',
        email: 'usuario1@dominio.com',
        cargo: 'Cargo 1',
        departamento: 'Departamento A',
        senha: 'senha123',  // Lembre-se de hashear a senha em um ambiente real
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        nome: 'Usuário 2',
        email: 'usuario2@dominio.com',
        cargo: 'Cargo 2',
        departamento: 'Departamento B',
        senha: 'senha456',  // Lembre-se de hashear a senha em um ambiente real
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);

    // Inserindo dados na tabela 'simulacoes'
    await queryInterface.bulkInsert('simulacoes', [
      {
        usuarioId: 1, // Correspondente ao Usuário 1
        equipeId: 1,  // Correspondente à Equipe 1
        dataSimulacao: new Date(),
        descricao: 'Simulação de Phishing 1',
        tipoPhishing: 'Phishing via email',
        objetivo: 'Treinar contra phishing',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        usuarioId: 2, // Correspondente ao Usuário 2
        equipeId: 2,  // Correspondente à Equipe 2
        dataSimulacao: new Date(),
        descricao: 'Simulação de Phishing 2',
        tipoPhishing: 'Phishing via SMS',
        objetivo: 'Sensibilizar sobre phishing',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);

    // Inserindo dados na tabela 'resultados'
    await queryInterface.bulkInsert('resultados', [
      {
        simulacaoId: 1,
        usuarioId: 1,
        status: 'Concluída',
        dataResultado: new Date(),
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        simulacaoId: 2, // Correspondente à Simulação 2
        usuarioId: 2,
        status: 'Concluída',
        dataResultado: new Date(),
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);

    // Inserindo dados na tabela 'feedbacks'
    await queryInterface.bulkInsert('feedbacks', [
      {
        usuarioId: 1, // Correspondente ao Usuário 1
        simulacaoId: 1, // Correspondente à Simulação 1
        dataFeedback: new Date(),
        nota: 5,
        comentarios: 'Muito boa a simulação, aprendi bastante!',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
      {
        usuarioId: 2, // Correspondente ao Usuário 2
        simulacaoId: 2, // Correspondente à Simulação 2
        dataFeedback: new Date(),
        nota: 4,
        comentarios: 'Simulação interessante, mas poderia ter mais exemplos.',
        createdAt: new Date(),
        updatedAt: new Date(),
      },
    ]);
  },

  down: async (queryInterface, Sequelize) => {
    // Revertendo as inserções feitas nas tabelas
    await queryInterface.bulkDelete('feedbacks', null, {});
    await queryInterface.bulkDelete('resultados', null, {});
    await queryInterface.bulkDelete('simulacoes', null, {});
    await queryInterface.bulkDelete('usuarios', null, {});
    await queryInterface.bulkDelete('equipes', null, {});
  },
};
