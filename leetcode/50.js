let debug = false;
if (process.argv.length > 2) {
  debug = true;
}
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */

var myPow = function (x, n) {
  if (x === 1) return 1;
  if (n === 0) return 1;
  if (n < 0) {
    n = -n;
    x = 1 / x;
  }
  let table = [1, x];
  while (table.length - 1 <= n) {
    let pos = table.length - 1;
    let temp = table[pos];
    table[pos * 2] = temp * temp;
    if (debug) {
      console.log("table", table);
      console.log("temp * temp", temp * temp);
      
    }
  }
  if (debug) {
    console.log("table", table)

  }
  let res = 1;
  let pos = 1;
  while (n > 0) {
    if (n & 1) {
      res *= table[pos];
      if (debug) {
        console.log("table[pos]", table[pos]);

      }
    }
    if (debug) {
      console.log("pos", pos)

    }
    pos *= 2;
    n >>= 1;
  }
  return res;
};

console.log(myPow(2.00000, -2147483648));