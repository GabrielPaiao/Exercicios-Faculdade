// routes/auth.js
const express = require('express');
const router = express.Router();
const AuthController = require('../controllers/AuthController');

// Rota para registro
router.get('/register', (req, res) => {
  res.render('auth/register');  // Renderiza o formulário de registro
});
router.post('/register', AuthController.register);  // Processa o registro

// Rota para login
router.get('/login', (req, res) => {
  res.render('auth/login');  // Renderiza o formulário de login
});
router.post('/login', AuthController.login);  // Processa o login

// Rota para logout
router.get('/logout', AuthController.logout);  // Realiza o logout e redireciona

// Rota para obter o perfil do usuário autenticado
router.get('/profile', AuthController.getProfile);  // Exibe o perfil do usuário logado

module.exports = router;
