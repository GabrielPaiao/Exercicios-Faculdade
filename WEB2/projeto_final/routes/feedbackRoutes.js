// routes/feedbacks.js
const express = require('express');
const router = express.Router();
const FeedbackController = require('../controllers/feedbacksController');

// CRUD
router.post('/', FeedbackController.create);          // Criar Feedback
router.get('/', FeedbackController.index);            // Listar todos os Feedbacks
router.get('/:id', FeedbackController.show);         // Detalhar um Feedback
router.put('/:id', FeedbackController.update);       // Atualizar um Feedback
router.delete('/:id', FeedbackController.delete);     // Excluir um Feedback

module.exports = router;
