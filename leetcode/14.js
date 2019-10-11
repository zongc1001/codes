/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    return strs.length > 1 ? strs.reduce(function(x,y){
        let k = 0;
        while(k < x.length && k < y.length && x[k] == y[k]) k++;
        return x.slice(0,k);
    }) : (strs[0] || "");
};

console.log(longestCommonPrefix(["", ""]))

