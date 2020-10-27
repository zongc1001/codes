/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    
    let temp = n;
    let table = [1, x];
    let res = 1;
    while(temp > 0) {
        
        table.push(table[table.length-1]**2);
        
        
        
        temp >>= 1;
        
    }
    

};

