const express = require('express')
const app = express()

app.set('view engine', 'ejs')
app.use(express.urlencoded({ extended: true }))

app.get('/', (req, res) =>
{
    res.render('index')
})

app.post('/index', (req, res) => 
{
    const inteiro = req.body.inteiro
    let resultado = 1
    for (let i = 1; i <= inteiro; i++) 
    {
        resultado *= i;
    }
    res.send(`Fatorial de ${inteiro}: ${resultado}`)
    res.redirect(`/resposta?inteiro=${inteiro}&resultado=${resultado}`);
})

app.get('/resposta', (req, res) => 
{
    const inteiro = req.query.inteiro;
    const resultado = req.query.resultado;
    res.send(`Fatorial de ${inteiro}: ${resultado}`);
})

app.listen(80)