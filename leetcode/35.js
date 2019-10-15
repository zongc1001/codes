/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    
    let begin = 0, end = nums.length - 1;
    if (begin === end) {
        return (target > nums[0]) ? 1 : 0 ;
    } else if(target <= nums[begin]) {
        return begin;
    } else if(target > nums[end]) {
        return end + 1;
    }
    while(true) {
        let i = parseInt(( begin + end ) / 2) ;
        
        if(target === nums[i]) {
            return i;
        } else {
            if( end - begin === 1) {
                return target < nums[begin] ? begin : target > nums[end] ? end + 1 : end;
            } else if (end - begin > 1) {
                target > nums[i] ? begin = i : end = i;
            } 
        }
    }
};

console.log(searchInsert([1,3,5,6], 7))
