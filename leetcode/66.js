/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    let len = digits.length;
    digits[len - 1]++;
    for(let i = len - 1; i >= 1; i--) {
        if(digits[i] >= 10) {
            digits[i] -= 10;
            digits[i - 1] += 1;
        } else {
            break;
        }
    }
    if(digits[0] >= 10) {
        digits[0] -= 10;
        digits.unshift(1);
    }
    return digits;
};
