/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function (nums, r, c) {
  if (nums.length > 0 && nums[0].length > 0 && r > 0 && c > 0) {
    if (r * c === nums.length * nums[0].length) {
      let x, y, a, b;
      x = y = a = b = 0;
      const step = () => {
        y++;
        if (y >= nums[0].length) {
          y = 0;
          x++;
        }
        b++;
        if (b >= c) {
          b = 0;
          a++;
        }
      }
      let temp = r * c, res = [[]];
      while (temp--) {
        res[a][b] = nums[x][y];
        step();
      }
      return res;
    }
  } 
  return nums;
};