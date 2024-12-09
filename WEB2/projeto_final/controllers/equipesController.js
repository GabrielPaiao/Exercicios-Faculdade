// controllers/equipesController.js
const Equipe = require('../models/Equipe');

exports.index = async (req, res) => {
    try {
        const equipes = await Equipe.findAll();
        res.render('equipes/index', { equipes });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar equipes', details: error.message });
    }
};

exports.show = async (req, res) => {
    try {
        const equipe = await Equipe.findByPk(req.params.id);
        if (!equipe) {
            return res.status(404).json({ error: 'Equipe não encontrada' });
        }
        res.render('equipes/show', { equipe });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar a equipe', details: error.message });
    }
};

exports.create = async (req, res) => {
    try {
        const { nome, descricao } = req.body;
        const novaEquipe = await Equipe.create({ nome, descricao });
        res.redirect('/equipes');
    } catch (error) {
        res.status(500).json({ error: 'Erro ao criar equipe', details: error.message });
    }
};

exports.update = async (req, res) => {
    try {
        const { nome, descricao } = req.body;
        const equipe = await Equipe.findByPk(req.params.id);
        if (!equipe) {
            return res.status(404).json({ error: 'Equipe não encontrada' });
        }
        equipe.nome = nome;
        equipe.descricao = descricao;
        await equipe.save();
        res.redirect('/equipes');
    } catch (error) {
        res.status(500).json({ error: 'Erro ao atualizar equipe', details: error.message });
    }
};

exports.delete = async (req, res) => {
    try {
        const equipe = await Equipe.findByPk(req.params.id);
        if (!equipe) {
            return res.status(404).json({ error: 'Equipe não encontrada' });
        }
        await equipe.destroy();
        res.redirect('/equipes');
    } catch (error) {
        res.status(500).json({ error: 'Erro ao excluir equipe', details: error.message });
    }
};
