var DataTypes = require("sequelize").DataTypes;
var _equipes = require("./equipes");
var _feedbacks = require("./feedbacks");
var _resultados = require("./resultados");
var _sequelizemeta = require("./sequelizemeta");
var _simulacoes = require("./simulacoes");
var _usuarios = require("./usuario");

function initModels(sequelize) {
  var equipes = _equipes(sequelize, DataTypes);
  var feedbacks = _feedbacks(sequelize, DataTypes);
  var resultados = _resultados(sequelize, DataTypes);
  var sequelizemeta = _sequelizemeta(sequelize, DataTypes);
  var simulacoes = _simulacoes(sequelize, DataTypes);
  var usuarios = _usuarios(sequelize, DataTypes);

  feedbacks.belongsTo(simulacoes, { as: "id_simulacao_simulaco", foreignKey: "id_simulacao"});
  simulacoes.hasMany(feedbacks, { as: "feedbacks", foreignKey: "id_simulacao"});
  resultados.belongsTo(simulacoes, { as: "id_simulacao_simulaco", foreignKey: "id_simulacao"});
  simulacoes.hasMany(resultados, { as: "resultados", foreignKey: "id_simulacao"});
  feedbacks.belongsTo(usuarios, { as: "id_usuario_usuario", foreignKey: "id_usuario"});
  usuarios.hasMany(feedbacks, { as: "feedbacks", foreignKey: "id_usuario"});
  resultados.belongsTo(usuarios, { as: "id_usuario_usuario", foreignKey: "id_usuario"});
  usuarios.hasMany(resultados, { as: "resultados", foreignKey: "id_usuario"});
  simulacoes.belongsTo(usuarios, { as: "id_usuario_usuario", foreignKey: "id_usuario"});
  usuarios.hasMany(simulacoes, { as: "simulacos", foreignKey: "id_usuario"});

  return {
    equipes,
    feedbacks,
    resultados,
    sequelizemeta,
    simulacoes,
    usuarios,
  };
}
module.exports = initModels;
module.exports.initModels = initModels;
module.exports.default = initModels;
