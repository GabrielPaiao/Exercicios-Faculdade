const express = require('express');
const router = express.Router();
const Simulacao = require('../models/Simulacao');

// Rota GET para listar as simulações
router.get('/', (req, res) => {
  Simulacao.findAll()
    .then(simulacoes => {
      res.render('simulacoes/index', { simulacoes });
    })
    .catch(error => {
      console.error(error);
      res.status(500).send('Erro ao buscar simulações');
    });
});

// Rota POST para criar uma nova simulação
router.post('/', (req, res) => {
  const { tipo, descricao } = req.body;
  Simulacao.create({ tipo, descricao })
    .then(() => {
      res.redirect('/simulacoes');
    })
    .catch(error => {
      console.error(error);
      res.status(500).send('Erro ao criar simulação');
    });
});

// Outras rotas para editar, deletar, etc., também devem ser definidas da mesma maneira

module.exports = router;
