// controllers/simulacoesController.js
const Simulacao = require('../models/Simulacao');
const Usuario = require('../models/Usuario');
const Equipe = require('../models/Equipe');

exports.index = async (req, res) => {
    try {
        const simulacoes = await Simulacao.findAll({
            include: [
                { model: Usuario, as: 'usuario' },
                { model: Equipe, as: 'equipe' },
            ],
        });
        res.render('simulacoes/index', { simulacoes });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar simulações', details: error.message });
    }
};
