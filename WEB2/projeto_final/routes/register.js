// routes/register.js
const express = require('express');
const router = express.Router();
const RegisterController = require('../controllers/RegisterController');

router.post('/', RegisterController.register);  // Rota para processar o cadastro

module.exports = router;
