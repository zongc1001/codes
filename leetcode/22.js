/**
 * @param {number} n
 * @return {string[]}
 */


var generateParenthesis = function (n) {
    let res = [];
    backTrack(res, "", 0, 0, n);
    return res;
};
/**
 * @param {Array} res
 * @param {string} cur
 * @param {pos} number
 */


var backTrack = function (res, cur, open, close, max) {
    if (cur.length === max * 2) {
        res.push(cur);
        return;
    } else {
        if(open < max) {
            backTrack(res, cur + '(', open + 1, close, max);
        }
        if(close < open) {
            backTrack(res, cur + ')', open, close + 1, max)
        }
    }
}

console.log(generateParenthesis(3))