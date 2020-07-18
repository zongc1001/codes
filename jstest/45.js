/**
 * 
 * @param {String} str 
 */
function isUSD(str) {
    let a = /^\$[1-9]\d{0,2}(,\d{3})*(\.\d{2})?$/;
    return a.test(str);
}