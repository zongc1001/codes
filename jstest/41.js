/**
 * 
 * @param {String} str 
 */
function containsRepeatingLetter(str) {
    let reg = /([a-zA-Z]{1})\1/g;
    let a = reg.exec(str);
    // console.log(a);
    return a !== null && a !== undefined;
}

console.log(containsRepeatingLetter("rAAr"));