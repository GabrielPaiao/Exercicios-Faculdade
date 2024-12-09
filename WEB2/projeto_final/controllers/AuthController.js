//controllers/AuthController.js
const bcrypt = require('bcrypt');
const { Usuario } = require('../models'); // Ajuste conforme o seu modelo de usuário

module.exports = {
  // Registrar um novo usuário
  register: async (req, res) => {
    const { nome, email, senha, cargo, departamento } = req.body;
    try {
        // Verificar se o email já está em uso
        const usuarioExistente = await Usuario.findOne({ where: { email } });
        if (usuarioExistente) {
            return res.status(400).json({ error: 'E-mail já está em uso.' });
        }

        // Criptografar a senha
        const senhaCriptografada = await bcrypt.hash(senha, 10);

        // Criar o novo usuário
        await Usuario.create({ nome, email, senha: senhaCriptografada, cargo, departamento });

        res.redirect('/auth/login'); // Redireciona para login após o registro
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: 'Erro ao registrar o usuário.' });
    }
},

  // Autenticar o usuário
  login: async (req, res) => {
    const { email, senha } = req.body;
    try {
      // Buscar o usuário pelo e-mail
      const usuario = await Usuario.findOne({ where: { email } });
      if (!usuario) {
        return res.status(401).json({ error: 'E-mail ou senha inválidos.' });
      }

      // Verificar a senha
      const senhaValida = await bcrypt.compare(senha, usuario.senha);
      if (!senhaValida) {
        return res.status(401).json({ error: 'E-mail ou senha inválidos.' });
      }

      // Salvar o ID do usuário na sessão
      req.session.userId = usuario.id;

      res.redirect('/'); // Redireciona para a página inicial após o login
    } catch (error) {
      console.error(error);
      res.status(500).json({ error: 'Erro ao fazer login.' });
    }
  },

  // Desconectar o usuário
  logout: (req, res) => {
    req.session.destroy((err) => {
      if (err) {
        console.error(err);
        return res.status(500).json({ error: 'Erro ao fazer logout.' });
      }

      res.redirect('/'); // Redireciona para a página de login após o logout
    });
  },
};
