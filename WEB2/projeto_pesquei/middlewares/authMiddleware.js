const { isLoggedIn } = require('../controllers/authController');

module.exports = {
  requireLogin: (req, res, next) => {
    return isLoggedIn(req, res, next);
  }
};
