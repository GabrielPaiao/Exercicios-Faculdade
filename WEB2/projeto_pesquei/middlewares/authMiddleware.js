module.exports = {
  requireLogin: (req, res, next) => {
    if (req.session && req.session.usuarioId) {
      // Verifica se há uma sessão válida
      return next();
    }
    // Redireciona para a página de login se não estiver autenticado
    return res.redirect('/login');
  },
};
