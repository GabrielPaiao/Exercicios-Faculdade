// controllers/LogoutController.js

module.exports = {
    logout: (req, res) => {
      // Destruir a sessão do usuário
      req.session.destroy((err) => {
        if (err) {
          return res.status(500).json({ error: 'Erro ao realizar logout' });
        }
  
        // Redirecionar para a página inicial
        res.redirect('/');
      });
    },
  };
  