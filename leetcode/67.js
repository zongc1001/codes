/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

var addBinary = function(a, b) {
    let temp;
    if(a.length < b.length) {
        temp = a;
        a = b;
        b = temp;
    }
    a = '0' + a;
    let len1 = a.length, len2 = b.length;
    let carry = false;
    let res = new Array();
    let i;
    for(i = 1; i <= len1; i++) {
        let output = carry;
        output += (a[len1 - i] === '1') + (len2 - i >= 0 && (b[len2 - i] === '1'));
        if(output >= 2) {
            output -= 2;
            carry = true;
        } else {
            carry = false;
        }
        res.unshift(output);
    }
    if(res[0] === 0) res.shift();
    // console.log(res, carry);
    return res.join('');
    
};

// console.log(addBinary("10110101010111101",
//                                   "10101"));
//                 //               1010010
