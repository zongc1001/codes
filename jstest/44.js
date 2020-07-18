/**
 * 
 * @param {String} str 
 */
function matchesPattern(str) {
    return /^[1-9]\d{2}-[1-9]\d{2}-[1-9]\d{3}$/.test(str);
}