// controllers/SimulacaoController.js
const { Simulacao, Usuario, Resultado, Equipe } = require('../models');

module.exports = {
  // Criar uma nova Simulação
  async create(req, res) {
    try {
      const { descricao, tipoPhishing, objetivo, usuarioId, equipeId } = req.body;
      
      // Verificar se o Usuário existe
      const usuario = await Usuario.findByPk(usuarioId);
      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado' });
      }
      
      // Verificar se a Equipe existe
      const equipe = await Equipe.findByPk(equipeId);
      if (!equipe) {
        return res.status(404).json({ error: 'Equipe não encontrada' });
      }
      
      const simulacao = await Simulacao.create({
        descricao,
        tipoPhishing,
        objetivo,
        usuarioId,  // Associar ao Usuário
        equipeId,   // Associar à Equipe
      });
      
      res.status(201).json(simulacao);
    } catch (error) {
      res.status(400).json({ error: 'Erro ao criar simulação', details: error.message });
    }
  },

  // Listar todas as Simulações
  async index(req, res) {
    try {
      const simulacoes = await Simulacao.findAll({
        include: [
          { model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] },
          { model: Equipe, as: 'equipe', attributes: ['id', 'nome'] },
        ],
      });
      res.status(200).json(simulacoes);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar simulações', details: error.message });
    }
  },

  // Detalhar uma Simulação específica
  async show(req, res) {
    try {
      const { id } = req.params;
      const simulacao = await Simulacao.findByPk(id, {
        include: [
          { model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] },
          { model: Equipe, as: 'equipe', attributes: ['id', 'nome'] },
          { 
            model: Resultado, 
            as: 'resultados',
            include: [{ model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] }]
          },
        ],
      });

      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada' });
      }

      res.status(200).json(simulacao);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao buscar simulação', details: error.message });
    }
  },

  // Atualizar uma Simulação
  async update(req, res) {
    try {
      const { id } = req.params;
      const { descricao, tipoPhishing, objetivo, usuarioId, equipeId } = req.body;

      const simulacao = await Simulacao.findByPk(id);
      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada' });
      }

      // Verificar se o Usuário existe (se fornecido)
      if (usuarioId) {
        const usuario = await Usuario.findByPk(usuarioId);
        if (!usuario) {
          return res.status(404).json({ error: 'Usuário não encontrado' });
        }
      }

      // Verificar se a Equipe existe (se fornecido)
      if (equipeId) {
        const equipe = await Equipe.findByPk(equipeId);
        if (!equipe) {
          return res.status(404).json({ error: 'Equipe não encontrada' });
        }
      }

      await simulacao.update({
        descricao: descricao || simulacao.descricao,
        tipoPhishing: tipoPhishing || simulacao.tipoPhishing,
        objetivo: objetivo || simulacao.objetivo,
        usuarioId: usuarioId || simulacao.usuarioId,
        equipeId: equipeId || simulacao.equipeId,
      });

      res.status(200).json(simulacao);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar simulação', details: error.message });
    }
  },

  // Excluir uma Simulação
  async delete(req, res) {
    try {
      const { id } = req.params;
      const simulacao = await Simulacao.findByPk(id);
      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada' });
      }

      await simulacao.destroy();
      res.status(204).send();
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir simulação', details: error.message });
    }
  },
};
