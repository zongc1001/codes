

var fac = function (n) {
    let res = 1;
    for (let i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
};


/**
* @param {number[]} nums
* @return {number[][]}
*/

var permute = function (nums) {
    let res = [];
    let len = res.length = fac(nums);
    let n = nums.length;
    for (let i = 0; i < res.length; i++) {
        res[i] = [];
    }

    let visited = new Array(n);
    visited.fill(false);
    console.log(visited);

    /**
    * @param {number[]} temp
    * @param {number} level 
    * @param {number[][]} res
    */
    let dfs = function (temp) {
        
    };

    //迭代列
    for (let j = 0; j < n; j++) {
        //迭代行
        for (let i = 0; i < len; i++) {

        }
    }


};

permute([1, 2, 3, 4, 5]);

