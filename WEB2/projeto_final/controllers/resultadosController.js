const Resultado = require('../models/Resultado');
const Simulacao = require('../models/Simulacao');
const Usuario = require('../models/Usuario');

// Função para listar todos os resultados
exports.index = async (req, res) => {
    try {
        const resultados = await Resultado.findAll({
            include: [
                { model: Simulacao, as: 'simulacao' },
                { model: Usuario, as: 'usuario' },
            ],
        });
        res.render('resultados/index', { resultados });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar resultados', details: error.message });
    }
};

// Função para criar um novo resultado
exports.create = async (req, res) => {
    try {
        const { simulacaoId, usuarioId, score, comentarios } = req.body;
        const resultado = await Resultado.create({
            simulacaoId,
            usuarioId,
            score,
            comentarios,
        });
        res.redirect('/resultados');  // Redireciona para a lista de resultados
    } catch (error) {
        res.status(500).json({ error: 'Erro ao criar resultado', details: error.message });
    }
};

// Função para detalhar um resultado
exports.show = async (req, res) => {
    try {
        const resultado = await Resultado.findByPk(req.params.id, {
            include: [
                { model: Simulacao, as: 'simulacao' },
                { model: Usuario, as: 'usuario' },
            ],
        });
        if (!resultado) {
            return res.status(404).json({ error: 'Resultado não encontrado' });
        }
        res.render('resultados/show', { resultado });
    } catch (error) {
        res.status(500).json({ error: 'Erro ao buscar resultado', details: error.message });
    }
};

// Função para atualizar um resultado
exports.update = async (req, res) => {
    try {
        const { simulacaoId, usuarioId, score, comentarios } = req.body;
        const resultado = await Resultado.findByPk(req.params.id);
        if (!resultado) {
            return res.status(404).json({ error: 'Resultado não encontrado' });
        }
        await resultado.update({ simulacaoId, usuarioId, score, comentarios });
        res.redirect(`/resultados/${req.params.id}`);
    } catch (error) {
        res.status(500).json({ error: 'Erro ao atualizar resultado', details: error.message });
    }
};

// Função para excluir um resultado
exports.delete = async (req, res) => {
    try {
        const resultado = await Resultado.findByPk(req.params.id);
        if (!resultado) {
            return res.status(404).json({ error: 'Resultado não encontrado' });
        }
        await resultado.destroy();
        res.redirect('/resultados');
    } catch (error) {
        res.status(500).json({ error: 'Erro ao excluir resultado', details: error.message });
    }
};
