/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
  let stk = [];
  let res = 0;
  for(let i = 0; i < height.length; i++) {
    if(stk.length === 0) {
      stk.push(height[i]);
    } else if(height[i] > stk[0]) {
      for(let i = i - 1; i > 0; i++) {
        res += 
      }
    } else {
      stk.push(height[i]);
    }
  }
};

trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]);

