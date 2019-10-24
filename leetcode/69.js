/**
 * 实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * @param {number} x
 * @return {number}
 */

var mySqrt = function(x) {
    if(x === 0) return 0;
    if(x <= 3) return 1;
    let front = 2,
        back = parseInt(x / 2 + 1);
    while(true) {
        let temp = parseInt((front + back) / 2);
        if(x >= temp * temp && x <= (temp + 1) * (temp + 1)) {
            return x === (temp + 1) * (temp + 1) ? temp + 1: temp;
        } else if (x < temp * temp){
            back = temp;
        } else if (x > (temp +1 ) * (temp + 1) ) {
            front = temp + 1;
        }
    }
};
// console.log(mySqrt(90));