/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let a = 1, b = 2, c = 3;
    if(n <= 2) return n;
    while(n-- >= 3) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
};


console.log(climbStairs(4));
