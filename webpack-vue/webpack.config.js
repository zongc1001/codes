const path = require('path')

module.exports = {
    entry: path.join(__dirname, 'src/index.js'),
    output: {
        filename: path.join(__dirname, 'dist')
    }
}