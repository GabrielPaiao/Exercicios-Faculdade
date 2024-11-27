// routes/logout.js
const express = require('express');
const router = express.Router();
const LogoutController = require('../controllers/LogoutController');

router.get('/', LogoutController.logout);  // Rota para processar logout

module.exports = router;
