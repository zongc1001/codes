/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let len1 = haystack.length, len2 = needle.length;
    if(len1 < len2) return -1;
    if(len2 === 0) return 0;
    for(let i = 0; i < len1 - len2 + 1; i++) {
        let is = true;
        for(let j = 0; j < len2; j++) {
            if(haystack[i + j] !== needle[j]) {
                is = false;
            }
        }
        if(is) {
            return i;
        }
    }
    return -1;
};