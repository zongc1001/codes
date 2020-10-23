function Node(val, i) {
    this.val = val;
    this.i = i;
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {

    let que = [];
    let indexOfHead = -1;



    function push(val, index) {
        while (que.length - 1 >= 0 && que[que.length - 1].val < val) {
            que.pop();
        }

        if (que.length < k) {
            que.push(new Node(val, index));
        }
    }

    let res = [];
    for (let i = 0; i < k && i < nums.length; i++) {
        // console.log(i);
        push(nums[i], i);
    }
    if (que.length > 0) {
        res.push(que[0]);
    }
    for (let i = 1; i + k - 1< nums.length; i++) {

        while (que.length > 0 && que[0].i < i) {
            que.shift();
        }
        push(nums[i + k - 1], i + k - 1);
        res.push(que[0]);
    }

    return res.map(x => x.val);
};

// const newLocal = maxSlidingWindow([1, 2, 3, 4, 5], 3);
// console.log(newLocal);