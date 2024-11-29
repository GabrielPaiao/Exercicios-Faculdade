// routes/auth.js
const express = require('express');
const router = express.Router();
const AuthController = require('../controllers/AuthController');

// Rota para exibir o formulário de registro
router.get('/register', (req, res) => {
  res.render('auth/register'); // Renderiza o formulário de registro
});

// Rota para processar o registro
router.post('/register', AuthController.register);

// Rota para exibir o formulário de login
router.get('/login', (req, res) => {
  res.render('auth/login'); // Renderiza o formulário de login
});

// Rota para processar o login
router.post('/login', AuthController.login);

// Rota de logout
router.get('/logout', AuthController.logout);  // Adicionando a rota de logout

module.exports = router;
