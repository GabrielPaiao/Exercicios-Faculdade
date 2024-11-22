// middlewares/authenticate.js
module.exports = {
    authenticate: (req, res, next) => {
      if (req.session && req.session.userId) {
        // Opcional: carregar o usuário e anexar à requisição
        // req.user = ... 
        next();
      } else {
        res.status(401).json({ error: 'Acesso não autorizado. Por favor, faça login.' });
      }
    },
  };
  