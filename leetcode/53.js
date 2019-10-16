/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    
    let begin = 0;
    let res = nums[0];
    let temp = nums[0];
    for(let i = 1; i < nums.length; i++) {
        if(nums[i] < 0) {
            res = Math.max(res, temp);
            if(temp < 0) {
                temp = nums[i];
                begin = i;
            } else {
                temp += nums[i];
            }
        } else {
            if(temp < 0) {
                temp = nums[i];
                begin = i;
            } else {
                temp += nums[i];
            }
        } 
    }
    res = Math.max(res, temp);

    return res;
};

// console.log(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]));