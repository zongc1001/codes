/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function (n) {
    function recur() {
        let table = [1, 1, 2, 5];
        let resFunc = function (n) {
            if (n < table.length) {
                return table[n];
            } else {
                let res = 0;
                for (let i = 1; i <= n; i++) {
                    res += resFunc(i - 1) * resFunc(n - i);
                }
                table[n] = res;
                return res;
            }
        }
        return resFunc;
    }
    return recur()(n);
}


// console.log(numTrees(30)) ;