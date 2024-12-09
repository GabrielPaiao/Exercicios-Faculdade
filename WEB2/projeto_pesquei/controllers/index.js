const { Usuario, Simulacao, Resultado, Feedback, Equipe } = require('../models');
const bcrypt = require('bcrypt');

// Controllers
const usuarioController = {
  // Criar Usuário
  create: async (req, res) => {
    try {
      const { nome, email, cargo, departamento, senha } = req.body;
      const hashedPassword = await bcrypt.hash(senha, 10);
      const novoUsuario = await Usuario.create({
        nome,
        email,
        cargo,
        departamento,
        senha: hashedPassword,
        dataCadastro: new Date(),
      });
      res.status(201).json(novoUsuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar usuário.' });
    }
  },

  // Editar Usuário
  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { nome, email, cargo, departamento } = req.body;
      const usuario = await Usuario.findByPk(id);

      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado.' });
      }

      await usuario.update({ nome, email, cargo, departamento });
      res.status(200).json(usuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar usuário.' });
    }
  },

  // Consultar Usuários
  list: async (req, res) => {
    try {
      const usuarios = await Usuario.findAll({ include: Simulacao });
      res.status(200).json(usuarios);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar usuários.' });
    }
  },

  // Excluir Usuário
  delete: async (req, res) => {
    try {
      const { id } = req.params;
      const usuario = await Usuario.findByPk(id);

      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado.' });
      }

      await usuario.destroy();
      res.status(200).json({ message: 'Usuário excluído com sucesso.' });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir usuário.' });
    }
  },
};

const authController = {
  login: async (req, res) => {
    try {
      const { email, senha } = req.body;

      const usuario = await Usuario.findOne({ where: { email } });

      if (!usuario) {
        return res.status(401).json({ error: 'Usuário não encontrado.' });
      }

      const senhaValida = await bcrypt.compare(senha, usuario.senha);

      if (!senhaValida) {
        return res.status(401).json({ error: 'Senha inválida.' });
      }

      req.session.usuarioId = usuario.id;

      res.status(200).json({ message: 'Login bem-sucedido.', usuario });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao tentar fazer login.' });
    }
  },

  logout: (req, res) => {
    req.session.destroy((err) => {
      if (err) {
        return res.status(500).json({ error: 'Erro ao sair da sessão.' });
      }
      res.status(200).json({ message: 'Logout bem-sucedido.' });
    });
  },
};

const simulacaoController = {
  create: async (req, res) => {
    try {
      const { dataSimulacao, descricao, tipoPhishing, objetivo, idEquipe } = req.body;
      const novaSimulacao = await Simulacao.create({
        dataSimulacao,
        descricao,
        tipoPhishing,
        objetivo,
        equipeId: idEquipe,
      });
      res.status(201).json(novaSimulacao);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar simulação.' });
    }
  },

  // Atualizar Simulação
  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { dataSimulacao, descricao, tipoPhishing, objetivo, idEquipe } = req.body;

      const simulacao = await Simulacao.findByPk(id);

      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada.' });
      }

      await simulacao.update({ dataSimulacao, descricao, tipoPhishing, objetivo, equipeId: idEquipe });
      res.status(200).json(simulacao);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar simulação.' });
    }
  },

  // Excluir Simulação
  delete: async (req, res) => {
    try {
      const { id } = req.params;
      const simulacao = await Simulacao.findByPk(id);

      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada.' });
      }

      await simulacao.destroy();
      res.status(200).json({ message: 'Simulação excluída com sucesso.' });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir simulação.' });
    }
  },
};


const resultadoController = {
  create: async (req, res) => {
    try {
      const { idSimulacao, idUsuario, status, dataResultado } = req.body;
      const novoResultado = await Resultado.create({
        simulacaoId: idSimulacao,
        usuarioId: idUsuario,
        status,
        dataResultado,
      });
      res.status(201).json(novoResultado);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar resultado.' });
    }
  },

  // Atualizar Resultado
  update: async (req, res) => {
    try {
      const { id } = req.params;
      const { status, dataResultado } = req.body;

      const resultado = await Resultado.findByPk(id);

      if (!resultado) {
        return res.status(404).json({ error: 'Resultado não encontrado.' });
      }

      await resultado.update({ status, dataResultado });
      res.status(200).json(resultado);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar resultado.' });
    }
  },
};

const feedbackController = {
  create: async (req, res) => {
    try {
      const { idUsuario, idSimulacao, dataFeedback, nota, comentarios } = req.body;
      const novoFeedback = await Feedback.create({
        usuarioId: idUsuario,
        simulacaoId: idSimulacao,
        dataFeedback,
        nota,
        comentarios,
      });
      res.status(201).json(novoFeedback);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar feedback.' });
    }
  },
};

const equipeController = {
  create: async (req, res) => {
    try {
      const { nomeEquipe, responsavel, contato } = req.body;
      const novaEquipe = await Equipe.create({ nomeEquipe, responsavel, contato });
      res.status(201).json(novaEquipe);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao criar equipe.' });
    }
  },
};

module.exports = {
  usuarioController,
  simulacaoController,
  resultadoController,
  feedbackController,
  equipeController,
  authController,
};
