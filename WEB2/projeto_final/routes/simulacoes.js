// routes/simulacoes.js
const express = require('express');
const router = express.Router();
const SimulacaoController = require('../controllers/SimulacaoController');
const { authenticate } = require('../middlewares/authenticate'); // Middleware de autenticação

// Aplicar middleware de autenticação a todas as rotas
router.use(authenticate);

// CRUD
router.post('/', SimulacaoController.create);          // Criar Simulação
router.get('/', SimulacaoController.index);            // Listar todas as Simulações
router.get('/:id', SimulacaoController.show);         // Detalhar uma Simulação
router.put('/:id', SimulacaoController.update);       // Atualizar uma Simulação
router.delete('/:id', SimulacaoController.delete);     // Excluir uma Simulação

module.exports = router;
