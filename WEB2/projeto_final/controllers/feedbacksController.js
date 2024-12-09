const Feedback = require('../models/Feedback');
const Usuario = require('../models/Usuario');
const Simulacao = require('../models/Simulacao');

// Função para listar todos os feedbacks
exports.index = async (req, res) => {
    try {
        const feedbacks = await Feedback.findAll({
            include: [
                { model: Usuario, as: 'usuario' },
                { model: Simulacao, as: 'simulacao' },
            ],
        });
        res.render('feedbacks/index', { feedbacks });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar feedbacks', details: error.message });
    }
};

// Função para criar feedback
exports.create = async (req, res) => {
    try {
        const { comentario, usuarioId, simulacaoId } = req.body;
        const feedback = await Feedback.create({
            comentario,
            usuarioId,
            simulacaoId,
        });
        res.redirect('/feedbacks');  // Redireciona para a lista de feedbacks
    } catch (error) {
        res.status(500).json({ error: 'Erro ao criar feedback', details: error.message });
    }
};

// Função para detalhar um feedback
exports.show = async (req, res) => {
    try {
        const feedback = await Feedback.findByPk(req.params.id, {
            include: [
                { model: Usuario, as: 'usuario' },
                { model: Simulacao, as: 'simulacao' },
            ],
        });
        if (!feedback) {
            return res.status(404).json({ error: 'Feedback não encontrado' });
        }
        res.render('feedbacks/show', { feedback });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar feedback', details: error.message });
    }
};

// Função para atualizar feedback
exports.update = async (req, res) => {
    try {
        const { comentario, usuarioId, simulacaoId } = req.body;
        const feedback = await Feedback.findByPk(req.params.id);
        if (!feedback) {
            return res.status(404).json({ error: 'Feedback não encontrado' });
        }
        await feedback.update({ comentario, usuarioId, simulacaoId });
        res.redirect(`/feedbacks/${req.params.id}`);
    } catch (error) {
        res.status(500).json({ error: 'Erro ao atualizar feedback', details: error.message });
    }
};

// Função para excluir feedback
exports.delete = async (req, res) => {
    try {
        const feedback = await Feedback.findByPk(req.params.id);
        if (!feedback) {
            return res.status(404).json({ error: 'Feedback não encontrado' });
        }
        await feedback.destroy();
        res.redirect('/feedbacks');
    } catch (error) {
        res.status(500).json({ error: 'Erro ao excluir feedback', details: error.message });
    }
};
