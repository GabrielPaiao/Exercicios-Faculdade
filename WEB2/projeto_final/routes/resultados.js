// routes/resultados.js
const express = require('express');
const router = express.Router();
const ResultadoController = require('../controllers/ResultadoController');
const { authenticate } = require('../middlewares/authenticate'); // Middleware de autenticação

// Aplicar middleware de autenticação a todas as rotas
router.use(authenticate);

// CRUD
router.post('/', ResultadoController.create);          // Criar Resultado
router.get('/', ResultadoController.index);            // Listar todos os Resultados
router.get('/:id', ResultadoController.show);         // Detalhar um Resultado
router.put('/:id', ResultadoController.update);       // Atualizar um Resultado
router.delete('/:id', ResultadoController.delete);     // Excluir um Resultado

module.exports = router;
