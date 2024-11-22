// controllers/AuthController.js
const { Usuario } = require('../models');
const bcrypt = require('bcrypt');

module.exports = {
  // Registro de usuário
  async register(req, res) {
    try {
      const { nome, email, cargo, departamento, senha } = req.body;

      // Verificar se o email já está em uso
      const existingUser = await Usuario.findOne({ where: { email } });
      if (existingUser) {
        return res.status(400).json({ error: 'Email já está em uso' });
      }

      // Criptografar a senha
      const hashedPassword = await bcrypt.hash(senha, 10);

      const usuario = await Usuario.create({
        nome,
        email,
        cargo,
        departamento,
        senha: hashedPassword,
      });

      // Iniciar sessão
      req.session.userId = usuario.id;

      res.status(201).json({ message: 'Usuário registrado com sucesso', usuario });
    } catch (error) {
      res.status(400).json({ error: 'Erro ao registrar usuário', details: error.message });
    }
  },

  // Login de usuário
  async login(req, res) {
    try {
      const { email, senha } = req.body;

      const usuario = await Usuario.findOne({ where: { email } });
      if (!usuario) {
        return res.status(400).json({ error: 'Credenciais inválidas' });
      }

      const isMatch = await bcrypt.compare(senha, usuario.senha);
      if (!isMatch) {
        return res.status(400).json({ error: 'Credenciais inválidas' });
      }

      // Iniciar sessão
      req.session.userId = usuario.id;

      res.status(200).json({ message: 'Login bem-sucedido', usuario });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao fazer login', details: error.message });
    }
  },

  // Logout de usuário
  async logout(req, res) {
    try {
      req.session.destroy(err => {
        if (err) {
          return res.status(500).json({ error: 'Erro ao encerrar sessão' });
        }
        res.clearCookie('connect.sid');
        res.status(200).json({ message: 'Logout bem-sucedido' });
      });
    } catch (error) {
      res.status(500).json({ error: 'Erro ao fazer logout', details: error.message });
    }
  },

  // Obter informações do usuário autenticado
  async getProfile(req, res) {
    try {
      const usuario = await Usuario.findByPk(req.session.userId, {
        attributes: { exclude: ['senha'] },
      });

      if (!usuario) {
        return res.status(404).json({ error: 'Usuário não encontrado' });
      }

      res.status(200).json(usuario);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao obter perfil', details: error.message });
    }
  },
};
