// middlewares/authenticate.js
module.exports = (req, res, next) => {
  if (req.session && req.session.userId) {
    // Opcional: carregar o usuário e anexar à requisição
    // req.user = ...
    next();  // Passa para a próxima função, que seria o controlador
  } else {
    res.status(401).json({ error: 'Acesso não autorizado. Por favor, faça login.' });
  }
};
