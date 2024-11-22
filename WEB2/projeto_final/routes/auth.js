// routes/auth.js
const express = require('express');
const router = express.Router();
const AuthController = require('../controllers/AuthController');

// Rotas de autenticação
router.post('/register', AuthController.register);   // Registro
router.post('/login', AuthController.login);         // Login
router.post('/logout', AuthController.logout);       // Logout
router.get('/profile', AuthController.getProfile);   // Obter perfil do usuário

module.exports = router;
