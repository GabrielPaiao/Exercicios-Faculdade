const { Usuario } = require('../models');
const bcrypt = require('bcrypt');

module.exports = {
  async create(req, res) {
    try {
      const { nome, email, cargo, departamento, senha } = req.body;
      const hashedPassword = await bcrypt.hash(senha, 10);
      const usuario = await Usuario.create({ nome, email, cargo, departamento, senha: hashedPassword });
      res.status(201).json(usuario);
    } catch (error) {
      res.status(400).json({ error: 'Erro ao criar usuário' });
    }
  },

  async index(req, res) {
    try {
      const usuarios = await Usuario.findAll();
      res.status(200).json(usuarios);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao listar usuários' });
    }
  },

  async show(req, res) {
    try {
      const usuario = await Usuario.findByPk(req.params.id);
      if (!usuario) return res.status(404).json({ error: 'Usuário não encontrado' });
      res.status(200).json(usuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao buscar usuário' });
    }
  },

  async update(req, res) {
    try {
      const { nome, email, cargo, departamento } = req.body;
      const usuario = await Usuario.findByPk(req.params.id);
      if (!usuario) return res.status(404).json({ error: 'Usuário não encontrado' });

      await usuario.update({ nome, email, cargo, departamento });
      res.status(200).json(usuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao atualizar usuário' });
    }
  },

  async delete(req, res) {
    try {
      const usuario = await Usuario.findByPk(req.params.id);
      if (!usuario) return res.status(404).json({ error: 'Usuário não encontrado' });

      await usuario.destroy();
      res.status(204).send();
    } catch (error) {
      res.status(500).json({ error: 'Erro ao excluir usuário' });
    }
  }
};
