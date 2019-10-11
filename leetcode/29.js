/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    let res = 0;
    let flag = (dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0);
    dividend = Math.abs(dividend);
    divisor = Math.abs(divisor);

    while((dividend -= divisor) >= 0) {
        res++;
    }
    return flag ? res : -res;
};