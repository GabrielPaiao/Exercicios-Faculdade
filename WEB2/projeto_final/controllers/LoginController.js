// controllers/LoginController.js
const User = require('../models/User'); // Supondo que você tenha um modelo de usuário
const bcrypt = require('bcrypt'); // Para comparar senhas

module.exports = {
  login: async (req, res) => {
    const { email, password } = req.body;
    
    try {
      const user = await User.findOne({ where: { email } });
      if (!user) {
        return res.status(400).json({ error: 'Usuário não encontrado' });
      }

      // Comparar a senha fornecida com a senha no banco de dados
      const match = await bcrypt.compare(password, user.password);
      if (!match) {
        return res.status(400).json({ error: 'Senha incorreta' });
      }

      // Criar sessão para o usuário
      req.session.userId = user.id;
      req.session.userEmail = user.email;

      // Redirecionar para a home ou página de simulações (baseado no parâmetro de redirecionamento)
      const redirectUrl = req.query.redirect || '/'; // Default para a home
      res.redirect(redirectUrl);
    } catch (error) {
      res.status(500).json({ error: 'Erro ao realizar login' });
    }
  },
};
