const express = require('express');
const router = express.Router();
const UsuarioController = require('../controllers/UsuarioController');

// CRUD
router.post('/', UsuarioController.create); // Criar usuário
router.get('/', UsuarioController.index);  // Listar todos
router.get('/:id', UsuarioController.show); // Detalhar um usuário
router.put('/:id', UsuarioController.update); // Atualizar usuário
router.delete('/:id', UsuarioController.delete); // Excluir usuário

module.exports = router;
