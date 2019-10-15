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
    
    let temp = divisor;
    let k = 1, tempk = 1;
    while(true) {
        if(dividend >= divisor) {
            console.log(divisor)
            dividend -= divisor;
            res += k;
            if( divisor < 0x3fffffff ) {
                k <<= 1;
                divisor <<= 1;
            }
        } else {
            if(k > 1) {
                k >>= 1;
                divisor >>= 1;
            } else if(k == 1){
                break;
            }
        }
    }
    if(flag && res > 0x7fffffff) res = 0x7fffffff;
    return flag ? res : -res;
};

// let a = 1;
// a << 1;
