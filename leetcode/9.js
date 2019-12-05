/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let y = 0, temp = x;

    while(temp > 0) {
        y = y * 10 + temp % 10;
        temp = Math.floor(temp / 10);
    }
    

    return x === y;

};

// console.log(isPalindrome(121));