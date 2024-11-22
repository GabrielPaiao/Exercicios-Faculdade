// controllers/EquipeController.js
const { Equipe, Simulacao } = require('../models');

module.exports = {
  // Criar uma nova Equipe
  async create(req, res) {
    try {
      const { nome, responsavel, contato } = req.body;

      const equipe = await Equipe.create({
        nome,
        responsavel,
        contato,
      });

      res.status(201).json(equipe);
    } catch (error) {
      res.status(400).json({ error: 'Erro ao criar equipe', details: error.message });
    }
  },

  // Listar todas as Equipes
  async index(req, res) {
    try {
      const equipes = await Equipe.findAll({
        include: [
          { 
            model: Simulacao, 
            as: 'simulacoes', 
            attributes: ['id', 'descricao'] 
          },
        ],
      });
      res.status(200).json(equipes);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar equipes', details: error.message });
    }
  },

  // Detalhar uma Equipe específica
  async show(req, res) {
    try {
      const { id } = req.params;
      const equipe = await Equipe.findByPk(id, {
        include: [
          { 
            model: Simulacao, 
            as: 'simulacoes', 
            attributes: ['id', 'descricao'] 
          },
        ],
      });

      if (!equipe) {
        return res.status(404).json({ error: 'Equipe não encontrada' });
      }

      res.status(200).json(equipe);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao buscar equipe', details: error.message });
    }
  },

  // Atualizar uma Equipe
  async update(req, res) {
    try {
      const { id } = req.params;
      const { nome, responsavel, contato } = req.body;

      const equipe = await Equipe.findByPk(id);
      if (!equipe) {
        return res.status(404).json({ error: 'Equipe não encontrada' });
      }

      await equipe.update({
        nome: nome || equipe.nome,
        responsavel: responsavel || equipe.responsavel,
        contato: contato || equipe.contato,
      });

      res.status(200).json(equipe);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar equipe', details: error.message });
    }
  },

  // Excluir uma Equipe
  async delete(req, res) {
    try {
      const { id } = req.params;
      const equipe = await Equipe.findByPk(id);
      if (!equipe) {
        return res.status(404).json({ error: 'Equipe não encontrada' });
      }

      await equipe.destroy();
      res.status(204).send();
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir equipe', details: error.message });
    }
  },
};
