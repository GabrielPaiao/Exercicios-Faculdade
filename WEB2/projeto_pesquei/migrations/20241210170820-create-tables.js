module.exports = {
  up: async (queryInterface, Sequelize) => {
    // Criando a tabela 'equipes'
    await queryInterface.createTable('equipes', {
      id: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true,
      },
      nomeEquipe: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      responsavel: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      contato: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      createdAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
      updatedAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
    });

    // Criando a tabela 'usuarios'
    await queryInterface.createTable('usuarios', {
      id: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true,
      },
      nome: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      email: {
        type: Sequelize.STRING,
        allowNull: false,
        unique: true,
      },
      cargo: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      departamento: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      senha: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      createdAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
      updatedAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
    });

    // Criando a tabela 'simulacoes'
    await queryInterface.createTable('simulacoes', {
      id: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true,
      },
      usuarioId: {
        type: Sequelize.INTEGER,
        references: {
          model: 'usuarios',
          key: 'id',
        },
        allowNull: false,
      },
      equipeId: {
        type: Sequelize.INTEGER,
        references: {
          model: 'equipes',
          key: 'id',
        },
        allowNull: false,
      },
      dataSimulacao: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      descricao: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      tipoPhishing: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      objetivo: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      createdAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
      updatedAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
    });

    // Criando a tabela 'resultados'
    await queryInterface.createTable('resultados', {
      id: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true,
      },
      simulacaoId: {
        type: Sequelize.INTEGER,
        references: {
          model: 'simulacoes',
          key: 'id',
        },
        allowNull: false,
      },
      usuarioId: {
        type: Sequelize.INTEGER,
        references: {
          model: 'usuarios',
          key: 'id',
        },
        allowNull: false,
        onDelete: 'CASCADE', 
      },
      status: {
        type: Sequelize.STRING,
        allowNull: false,
      },
      dataResultado: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      createdAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
      updatedAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
    });
    

    // Criando a tabela 'feedbacks'
    await queryInterface.createTable('feedbacks', {
      id: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true,
      },
      usuarioId: {
        type: Sequelize.INTEGER,
        references: {
          model: 'usuarios',
          key: 'id',
        },
        allowNull: false,
      },
      simulacaoId: {
        type: Sequelize.INTEGER,
        references: {
          model: 'simulacoes',
          key: 'id',
        },
        allowNull: false,
      },
      dataFeedback: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      nota: {
        type: Sequelize.INTEGER,
        allowNull: false,
      },
      comentarios: {
        type: Sequelize.TEXT,
        allowNull: true,
      },
      createdAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
      updatedAt: {
        type: Sequelize.DATE,
        defaultValue: Sequelize.NOW,
      },
    });

    // Relacionamentos (para garantir integridade referencial no banco)
    await queryInterface.addConstraint('simulacoes', {
      fields: ['usuarioId'],
      type: 'foreign key',
      references: {
        table: 'usuarios',
        field: 'id',
      },
      onDelete: 'CASCADE',
    });

    await queryInterface.addConstraint('feedbacks', {
      fields: ['usuarioId'],
      type: 'foreign key',
      references: {
        table: 'usuarios',
        field: 'id',
      },
      onDelete: 'CASCADE',
    });

    await queryInterface.addConstraint('feedbacks', {
      fields: ['simulacaoId'],
      type: 'foreign key',
      references: {
        table: 'simulacoes',
        field: 'id',
      },
      onDelete: 'CASCADE',
    });

    await queryInterface.addConstraint('simulacoes', {
      fields: ['equipeId'],
      type: 'foreign key',
      references: {
        table: 'equipes',
        field: 'id',
      },
      onDelete: 'CASCADE',
    });
  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.dropTable('feedbacks');
    await queryInterface.dropTable('resultados');
    await queryInterface.dropTable('simulacoes');
    await queryInterface.dropTable('usuarios');
    await queryInterface.dropTable('equipes');
  },
};
