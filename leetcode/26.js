/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if(nums.length === 1) return 1;
    let k = 1;
    for(let i = 1; i < nums.length; i++) {
        // console.log(nums[i], nums[k])
        if(nums[i] !== nums[k-1]) {
            // console.log('dd')
            nums[k++] = nums[i];
        }
    }
    // console.log(k);
    return k;
};