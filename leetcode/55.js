/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {
    let dest = new Array(nums.length);
    dest.fill(new Array(0));
    nums.forEach((x, i) => {
        for (let t = i + 1; t <= i + x && t < nums.length; t++) {
            dest[t].push(i);
        }
    });

    let visited = new Array(nums.length);
    visited.fill(false);    

    function find(cur) {
        
    }

    console.log(dest);
};

canJump([2,3,1,1,4]);