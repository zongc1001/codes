/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function (s, p) {
    let lenS = s.length, lenP = p.length;
    let memory = new Array(lenS + 1);
    for (let i = 0; i <= lenS; i++) {
        memory[i] = new Array(lenP + 1);
    }
    memory.forEach(x => x.fill(false));
    memory[0][0] = true;
    // console.log("memory: ", memory);
    recur(0, 0);
    // console.log("memory after recur: ", memory);
    function inRange(r, c) {
        return r >= 0 && r <= lenS && c >= 0 && c <= lenP;
    }

    function recur(row, col) {
        if (inRange(row, col + 1) && !memory[row][col + 1] && p[col] === '*') {
            memory[row][col + 1] = true;
            recur(row, col + 1);
        }
        if (inRange(row + 1, col) && !memory[row + 1][col] && p[col - 1] === '*') {
            memory[row + 1][col] = true;
            recur(row + 1, col);
        }
        if (inRange(row + 1, col + 1) && !memory[row + 1][col + 1]) {
            if (p[col] === '*' || p[col] === '?' || p[col] === s[row]) {
                memory[row + 1][col + 1] = true;
                recur(row + 1, col + 1);
            }
        }
    }
    return memory[lenS][lenP];
};

console.log(isMatch("a", "*?*"));