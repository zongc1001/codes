'use strict';
function Xbonacci(s, n) {
    return s.length < n ? [s[0]].concat(Xbonacci( s.slice(1,s.push(s.reduce((x, y) => x + y))), n-1)) :s.slice(0,n) ;
}
console.log(Xbonacci([1,0,0,0,0,0,0,0,0,0], 0))