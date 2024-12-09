// Importando os controllers
const express = require('express');
const {
  usuarioController,
  simulacaoController,
  resultadoController,
  feedbackController,
  equipeController,
  authController, // Importando o authController
} = require('../controllers');

const router = express.Router();

// Rotas de Usuários
router.post('/usuarios', usuarioController.create);
router.put('/usuarios/:id', usuarioController.update);
router.get('/usuarios', usuarioController.list);
router.delete('/usuarios/:id', usuarioController.delete);

// Rotas de Simulações
router.post('/simulacoes', simulacaoController.create);
router.put('/simulacoes/:id', simulacaoController.update);
router.get('/simulacoes', simulacaoController.list);
router.delete('/simulacoes/:id', simulacaoController.delete);

// Rotas de Resultados
router.post('/resultados', resultadoController.create);
router.put('/resultados/:id', resultadoController.update);
router.get('/resultados', resultadoController.list);

// Rotas de Feedback
router.post('/feedbacks', feedbackController.create);
router.put('/feedbacks/:id', feedbackController.update);
router.get('/feedbacks', feedbackController.list);
router.delete('/feedbacks/:id', feedbackController.delete);

// Rotas de Equipes
router.post('/equipes', equipeController.create);
router.put('/equipes/:id', equipeController.update);
router.get('/equipes', equipeController.list);
router.delete('/equipes/:id', equipeController.delete);

// Rotas de Autenticação
router.post('/login', authController.login);
router.post('/logout', authController.logout);

module.exports = router;
