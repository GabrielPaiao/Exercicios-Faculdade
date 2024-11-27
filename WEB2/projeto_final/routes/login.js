// routes/login.js
const express = require('express');
const router = express.Router();
const LoginController = require('../controllers/LoginController');

router.post('/', LoginController.login);  // Rota para processar login

module.exports = router;
