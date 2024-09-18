/*
GABRIEL PEREIRA PAIAO

Para calcular a área do retângulo, use a rota:
/calcula/retangulo/area?b=25.5&a=41

Para calcular o perímetro do retângulo, use a rota:
/calcula/retangulo/perimetro?b=25.5&a=41

Para calcular a área do triângulo, use a rota:
/calcula/triangulo/area?b=25.5&a=41

Para calcular o perímetro do triângulo, use a rota:
/calcula/triangulo/perimetro?l1=3&l2=4&l3=5
*/

const express = require('express');
const app = express();
const port = 3000;

function calcularAreaRetangulo(base, altura) {
  return base * altura;
}

function calcularPerimetroRetangulo(base, altura) {
  return 2 * (base + altura);
}

function calcularAreaTriangulo(base, altura) {
  return (base * altura) / 2;
}

function calcularPerimetroTriangulo(lado1, lado2, lado3) {
  return lado1 + lado2 + lado3;
}

app.get('/calcula/retangulo/:calculo', (req, res) => {
  const { b, a } = req.query;
  const base = parseFloat(b);
  const altura = parseFloat(a);

  if (isNaN(base) || isNaN(altura)) {
    return res.status(400).send('Parâmetros inválidos. Use ?b=valor&a=valor.');
  }

  if (req.params.calculo === 'area') {
    const area = calcularAreaRetangulo(base, altura);
    res.send(`A área do retângulo é ${area}.`);
  } else if (req.params.calculo === 'perimetro') {
    const perimetro = calcularPerimetroRetangulo(base, altura);
    res.send(`O perímetro do retângulo é ${perimetro}.`);
  } else {
    res.status(404).send('Cálculo não encontrado.');
  }
});

app.get('/calcula/triangulo/:calculo', (req, res) => {
  const { b, a, l1, l2, l3 } = req.query;
  const base = parseFloat(b);
  const altura = parseFloat(a);
  const lado1 = parseFloat(l1);
  const lado2 = parseFloat(l2);
  const lado3 = parseFloat(l3);

  if (req.params.calculo === 'area') {
    if (isNaN(base) || isNaN(altura)) {
      return res.status(400).send('Parâmetros inválidos. Use ?b=valor&a=valor.');
    }
    const area = calcularAreaTriangulo(base, altura);
    res.send(`A área do triângulo é ${area}.`);
  } else if (req.params.calculo === 'perimetro') {
    if (isNaN(lado1) || isNaN(lado2) || isNaN(lado3)) {
      return res.status(400).send('Parâmetros inválidos. Use ?l1=valor&l2=valor&l3=valor.');
    }
    const perimetro = calcularPerimetroTriangulo(lado1, lado2, lado3);
    res.send(`O perímetro do triângulo é ${perimetro}.`);
  } else {
    res.status(404).send('Cálculo não encontrado.');
  }
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
