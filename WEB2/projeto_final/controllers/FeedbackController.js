// controllers/FeedbackController.js
const { Feedback, Usuario, Simulacao } = require('../models');

module.exports = {
  // Criar um novo Feedback
  async create(req, res) {
    try {
      const { usuarioId, simulacaoId, nota, comentarios } = req.body;

      // Verificar se o Usuário existe
      const usuario = await Usuario.findByPk(usuarioId);
      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado' });
      }

      // Verificar se a Simulação existe
      const simulacao = await Simulacao.findByPk(simulacaoId);
      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada' });
      }

      // Verificar se já existe um Feedback para este Usuário e Simulação
      const existingFeedback = await Feedback.findOne({
        where: { simulacaoId, usuarioId },
      });
      if (existingFeedback) {
        return res.status(400).json({ error: 'Feedback já registrado para este Usuário e Simulação' });
      }

      const feedback = await Feedback.create({
        usuarioId,
        simulacaoId,
        nota,
        comentarios,
      });

      res.status(201).json(feedback);
    } catch (error) {
      res.status(400).json({ error: 'Erro ao criar feedback', details: error.message });
    }
  },

  // Listar todos os Feedbacks
  async index(req, res) {
    try {
      const feedbacks = await Feedback.findAll({
        include: [
          { model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] },
          { model: Simulacao, as: 'simulacao', attributes: ['id', 'descricao'] },
        ],
      });
      res.status(200).json(feedbacks);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar feedbacks', details: error.message });
    }
  },

  // Detalhar um Feedback específico
  async show(req, res) {
    try {
      const { id } = req.params;
      const feedback = await Feedback.findByPk(id, {
        include: [
          { model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] },
          { model: Simulacao, as: 'simulacao', attributes: ['id', 'descricao'] },
        ],
      });

      if (!feedback) {
        return res.status(404).json({ error: 'Feedback não encontrado' });
      }

      res.status(200).json(feedback);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao buscar feedback', details: error.message });
    }
  },

  // Atualizar um Feedback
  async update(req, res) {
    try {
      const { id } = req.params;
      const { usuarioId, simulacaoId, nota, comentarios } = req.body;

      const feedback = await Feedback.findByPk(id);
      if (!feedback) {
        return res.status(404).json({ error: 'Feedback não encontrado' });
      }

      // Se for atualizar usuarioId
      if (usuarioId) {
        const usuario = await Usuario.findByPk(usuarioId);
        if (!usuario) {
          return res.status(404).json({ error: 'Usuário não encontrado' });
        }
      }

      // Se for atualizar simulacaoId
      if (simulacaoId) {
        const simulacao = await Simulacao.findByPk(simulacaoId);
        if (!simulacao) {
          return res.status(404).json({ error: 'Simulação não encontrada' });
        }
      }

      // Atualizar os campos
      await feedback.update({
        usuarioId: usuarioId || feedback.usuarioId,
        simulacaoId: simulacaoId || feedback.simulacaoId,
        nota: nota !== undefined ? nota : feedback.nota,
        comentarios: comentarios || feedback.comentarios,
      });

      res.status(200).json(feedback);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar feedback', details: error.message });
    }
  },

  // Excluir um Feedback
  async delete(req, res) {
    try {
      const { id } = req.params;
      const feedback = await Feedback.findByPk(id);
      if (!feedback) {
        return res.status(404).json({ error: 'Feedback não encontrado' });
      }

      await feedback.destroy();
      res.status(204).send();
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir feedback', details: error.message });
    }
  },
};
