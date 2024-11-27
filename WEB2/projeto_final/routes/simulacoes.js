// routes/simulacoes.js
const express = require('express');
const router = express.Router();
const SimulacaoController = require('../controllers/SimulacaoController');

// CRUD - Definindo as rotas de simulação
router.post('/', SimulacaoController.create);          // Criar Simulação
router.get('/', SimulacaoController.index);            // Listar todas as Simulações
router.get('/:id', SimulacaoController.show);         // Detalhar uma Simulação
router.put('/:id', SimulacaoController.update);       // Atualizar uma Simulação
router.delete('/:id', SimulacaoController.delete);     // Excluir uma Simulação

module.exports = router;
