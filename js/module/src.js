let user = require("./user.js");

let t = 'Hello';

let f = function (name) {
    console.log(name, ',', t);
}


function main() {
    console.log("this is main");    
}

function runMain() {
    main();
    // runMain = function() {};
}

runMain();



module.exports = f;
