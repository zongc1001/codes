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
    let res = '';
    for(let i = 1; i <= len2; i++) {
        let output = carry;
        output += (a[len1 - i] === '1') + (b[len2 - i] === '1');
        if(output >= 2) {
            output -= 2;
            carry = true;
        }
        res.concat(output);
    }
    if(carry) {
        let i = len1 - len2 - 1;
        for(; i >= 0; i--) {
            let output = carry;
            output += (a[i] === 'i');
            if(output >= 2) {
                carry = true;
                output = 0;
                res.concat(output);
            } else break;
        }
    }
    if(a[0] === '0') return a.slice(1, a.length);
    else return a;
};
