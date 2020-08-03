/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {
    let len = nums.length;
    let max = 0;
    for (let i = 0; i < len; i++) {
        if (i <= max) {
            max = Math.max(max, i + nums[i]);
        } else {
            return false;
        }
    }
    return true;
};

// console.log(canJump([2,3,1,1,4]));