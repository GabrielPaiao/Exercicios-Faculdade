// routes/equipes.js
const express = require('express');
const router = express.Router();
const EquipeController = require('../controllers/equipesController');

// CRUD - Definindo as rotas de equipes
router.post('/', EquipeController.create);          // Criar Equipe
router.get('/', EquipeController.index);            // Listar todas as Equipes
router.get('/:id', EquipeController.show);          // Detalhar uma Equipe
router.put('/:id', EquipeController.update);        // Atualizar uma Equipe
router.delete('/:id', EquipeController.delete);     // Excluir uma Equipe

module.exports = router;
