/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let table = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                    'C': 100, 'D': 500, 'M': 1000};
    let len = s.length;
    let res = 0;
    for(let i = len - 1;i >= 0; i--) {
        res += table[s[i]];
        if(i > 0 && table[s[i-1]] < table[s[i]]) {
            res -= table[s[i-1]];
            i--;
        }
    }
    return res;
};

console.log(romanToInt("MCMXCIV"));