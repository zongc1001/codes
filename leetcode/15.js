/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  let res = [];
  if (nums.length < 3) return res;


  nums = nums.sort((a, b) => a - b);
  // console.log(nums);
  let len = nums.length;
  let lastNum;
  for (let i = 0; i < len - 2; i++) {
    let left = i + 1, right = len - 1;
    if (nums[i] > 0) break;
    if(nums[i] === lastNum) {
      continue;
    } else{
      lastNum = nums[i];
    }
    

    while (left < right) {
      // console.log(left, right);
      let sum = nums[i] + nums[left] + nums[right];
      // console.log(sum);
      if (sum === 0) {
        res.push([nums[i], nums[left], nums[right]]);
        let temp = nums[left];
        while(nums[++left] === temp);
        temp = nums[right];
        while(nums[--right] === temp);
      } else if (sum < 0) {
        let temp = nums[left];
        while(nums[++left] === temp);
      } else if (sum > 0) {
        let temp = nums[right];
        while(nums[--right] === temp);
      }
    }
  }
  return res;
};

// let t = threeSum(arg);
// console.log(t);