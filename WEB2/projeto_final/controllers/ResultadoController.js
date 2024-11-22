// controllers/ResultadoController.js
const { Resultado, Simulacao, Usuario } = require('../models');

module.exports = {
  // Criar um novo Resultado
  async create(req, res) {
    try {
      const { simulacaoId, usuarioId, status } = req.body;

      // Verificar se a Simulação existe
      const simulacao = await Simulacao.findByPk(simulacaoId);
      if (!simulacao) {
        return res.status(404).json({ error: 'Simulação não encontrada' });
      }

      // Verificar se o Usuário existe
      const usuario = await Usuario.findByPk(usuarioId);
      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado' });
      }

      // Verificar se já existe um Resultado para este Usuário e Simulação
      const existingResultado = await Resultado.findOne({
        where: { simulacaoId, usuarioId },
      });
      if (existingResultado) {
        return res.status(400).json({ error: 'Resultado já registrado para este Usuário e Simulação' });
      }

      const resultado = await Resultado.create({
        simulacaoId,
        usuarioId,
        status,
      });

      res.status(201).json(resultado);
    } catch (error) {
      res.status(400).json({ error: 'Erro ao criar resultado', details: error.message });
    }
  },

  // Listar todos os Resultados
  async index(req, res) {
    try {
      const resultados = await Resultado.findAll({
        include: [
          { model: Simulacao, as: 'simulacao', attributes: ['id', 'descricao'] },
          { model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] },
        ],
      });
      res.status(200).json(resultados);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar resultados', details: error.message });
    }
  },

  // Detalhar um Resultado específico
  async show(req, res) {
    try {
      const { id } = req.params;
      const resultado = await Resultado.findByPk(id, {
        include: [
          { model: Simulacao, as: 'simulacao', attributes: ['id', 'descricao'] },
          { model: Usuario, as: 'usuario', attributes: ['id', 'nome', 'email'] },
        ],
      });

      if (!resultado) {
        return res.status(404).json({ error: 'Resultado não encontrado' });
      }

      res.status(200).json(resultado);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao buscar resultado', details: error.message });
    }
  },

  // Atualizar um Resultado
  async update(req, res) {
    try {
      const { id } = req.params;
      const { simulacaoId, usuarioId, status } = req.body;

      const resultado = await Resultado.findByPk(id);
      if (!resultado) {
        return res.status(404).json({ error: 'Resultado não encontrado' });
      }

      // Se for atualizar simulacaoId
      if (simulacaoId) {
        const simulacao = await Simulacao.findByPk(simulacaoId);
        if (!simulacao) {
          return res.status(404).json({ error: 'Simulação não encontrada' });
        }
      }

      // Se for atualizar usuarioId
      if (usuarioId) {
        const usuario = await Usuario.findByPk(usuarioId);
        if (!usuario) {
          return res.status(404).json({ error: 'Usuário não encontrado' });
        }
      }

      // Atualizar os campos
      await resultado.update({
        simulacaoId: simulacaoId || resultado.simulacaoId,
        usuarioId: usuarioId || resultado.usuarioId,
        status: status || resultado.status,
      });

      res.status(200).json(resultado);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar resultado', details: error.message });
    }
  },

  // Excluir um Resultado
  async delete(req, res) {
    try {
      const { id } = req.params;
      const resultado = await Resultado.findByPk(id);
      if (!resultado) {
        return res.status(404).json({ error: 'Resultado não encontrado' });
      }

      await resultado.destroy();
      res.status(204).send();
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir resultado', details: error.message });
    }
  },
};
