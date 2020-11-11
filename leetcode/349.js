/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    // return nums1.filter(x => nums1)
    let table = {};
    nums1.forEach(x => {
        if(!table[x]) {
            table[x] = true;
        }
    })
    return nums2.filter(x => {
        if(table[x]) {
            table[x] = false;
            return true;
        } 
        return false;
    })
};