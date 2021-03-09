/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
  if(!nums || nums.length === 0) return [];
  let cur = nums[0];
  let res = new Array();
  res.push([cur, cur]);
  for (let i = 1; i< nums.length;i++) {
    if(nums[i] === nums[i - 1] + 1) {
      res[res.length -1][1] = nums[i];
    } else {
      res.push([nums[i], nums[i]]);
    }
  }
  return res.map(x => {
    if(x[0] === x[1]) {
      return `${x[0]}`;
    } else {
      return `${x[0]}->${x[1]}`;
    }
  })
};