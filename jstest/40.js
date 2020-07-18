/**
 * 
 * @param {String} str 
 */
function containsNumber(str) {
    let r = /\d+/g;
    let a = r.exec(str);
    // console.log(a);
    return a !== null ;

}

console.log(containsNumber("aaafd2a"));