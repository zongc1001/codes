/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let res = new String("");

    let table = {
        1: "I", 5: "V", 10: "X", 50: "L",
        100: "C", 500: "D", 1000: "M"
    };
    for(let i = 3; i >= 0; i--) {
        let temp = Math.pow(10, i);
        while(num >= temp) {
            num -= temp;
            res += table[temp];
        }
        if(temp >= 10 && num >= temp / 10 * 9) {
            res += table[temp/10] + table[temp];
            num -= temp / 10 * 9;
        } else if(temp >= 10 && num >= temp / 2) {
            res += table[temp / 2];
            num -= temp / 2;
        } else if(temp >= 10 && num >= temp / 10 * 4) {
            res += table[temp / 10] + table[temp / 2];
            num -= temp / 10 * 4;
        }
    }
    return res;
};

console.log(intToRoman("3333"));
