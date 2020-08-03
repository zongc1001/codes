/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function (nums) {
    let len = nums.length;
    if (len === 1) return true;
    let dest = new Array(0);
    for (let i = 0; i < len; i++) {
        dest[i] = new Array(0);
    }
    nums.forEach((x, i) => {
        for (let t = i + 1; t <= i + x && t < len; t++) {
            console.log("dd: ", t, i);
            dest[t].push(i);
        }
    });
    for (let i = len - 1; i >= 0; i--) {
        let x = nums[i];
        for (let t = i + 1; t <= i + x && t < len; t++) {
            console.log("dd: ", t, i);
            dest[t].push(i);
        } 
    }


    let visited = new Array(len);
    visited.fill(false);
    let stk = [];
    stk.push(len - 1);
    while (stk.length > 0) {
        let cur = stk.pop();
        visited[cur] = true;
        for (let i = 0; i < dest[cur].length; i++) {
            let temp = dest[cur][i];
            // console.log(temp);
            if (temp === 0) {
                return true;
            } else if (!visited[temp]) {
                stk.push(temp);
            }
        }
    }
    return false;
};

console.log(canJump([3, 0, 8, 2, 0, 0, 1]));