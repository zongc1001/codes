/**
 * 
 * @param {Object} obj 
 */


function iterate(obj) {
    let name, res = [];
    for(name in obj) {
        if(obj.hasOwnProperty(name)) {
            res.push(name + ": " + obj[name]);
        }
    }
    return res;
}

var C = function() {this.foo = 'bar'; this.baz = 'bim';}; 
C.prototype.bop = 'bip'; 
console.log(iterate(new C()));
