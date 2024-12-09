// config/database.js
const { Sequelize } = require('sequelize');
const sequelize = new Sequelize('phishing_simulator', 'user', 'password', {
    host: 'localhost',
    dialect: 'mysql',
    logging: false,
});

module.exports = sequelize;