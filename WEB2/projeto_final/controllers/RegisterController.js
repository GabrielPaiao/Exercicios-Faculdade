// controllers/RegisterController.js
const User = require('../models/User');
const bcrypt = require('bcrypt'); // Para criptografar a senha

module.exports = {
  register: async (req, res) => {
    const { name, email, password } = req.body;
    
    try {
      // Verificar se o usuário já existe
      const existingUser = await User.findOne({ where: { email } });
      if (existingUser) {
        return res.status(400).json({ error: 'Já existe um usuário com este e-mail' });
      }

      // Criptografar a senha
      const hashedPassword = await bcrypt.hash(password, 10);

      // Criar um novo usuário
      const newUser = await User.create({
        name,
        email,
        password: hashedPassword
      });

      // Redirecionar para o login ou home
      const redirectUrl = req.query.redirect || '/login';
      res.redirect(redirectUrl);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao realizar cadastro' });
    }
  },
};
