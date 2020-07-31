/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
function isAlp(ch) {
    return /^[a-z]$/.test(ch);
}

var isMatch = function(s, p) {
    let a = p.split('*');
    let len = a;
    console.log(a);
};

isMatch("fdasfasd", "fad*fafad..adfa*.fasdf*");
