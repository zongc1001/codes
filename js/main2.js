"use strict";
function toCamelCase(s) {
   return "\"" + (s.search(/_|-/) >= 0 ?  s.split(/-|_/)[0].concat((s.split(/-|_/).slice(1).map(x=>x.replace(x[0],x[0].toUpperCase())).join(''))) : s) + "\"";
}

console.log(toCamelCase("The_Stealth_Warrior"))
console.log(toCamelCase(""))
console.log(toCamelCase("the-stealth-warrior"))
console.log(toCamelCase("A-B-C"))

