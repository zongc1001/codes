/**
 * @param {string} digits
 * @return {string[]}
 * @param {Array} nums
 * @returns {Array}
 */
'use strict'
var letterCombinations = function(digits) {
    if(digits.length === 0) return [];
    const table = [['a','b','c'],
                  ['d','e','f'],
                  ['g','h','i'],
                  ['j','k','l'],
                  ['m','n','o'],
                  ['p','q','r','s'],
                  ['t','u','v'],
                  ['w','x','y','z']];
    let arr = digits.split("").map(x=>Number(x)-2);
    
    let arg = arr.map(x=>table[x]);
    // console.log(arg, arg instanceof Array); // [ [ 'a', 'b', 'c' ] ] true
    // console.log(arg.flat(Infinity));
    return arg.length > 1 ? descartFn(arg) : arg[0];
};

var descartFn = function(nums) {
    let t = nums.reduce((a, b)=> {
        let m = a.map(item=> {
            return b.map(i=> {
                return [...item, i];
            });
        });
        let f = m.reduce((c, d)=> {
            return c.concat(d);
        });
        let n = f.map( x => x.reduce((a,b) => a.concat(b)));
        return n;
    })
    return t;
}

console.log( letterCombinations("23"));

