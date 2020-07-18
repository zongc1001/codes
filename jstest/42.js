/**
 * @returns {Boolean}
 * @param {String} str 
 */

function endsWithVowel(str) {
    let a = ['a', 'e', 'i', 'o', 'u'];
    let len = str.length;
    if (len > 0) {
        return a.find(n => n === str[len-1] || n.toLocaleUpperCase() === str[len-1] ) !== undefined;
    }
    return false;
}

console.log(endsWithVowel("fdasfaA"))