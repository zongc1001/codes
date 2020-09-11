const table = Object.freeze([1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]);
/**
 * 
 * @param {number[]} arr 
 * @return {number}
 */
let cantor = function (arr) {

  let res = 0;
  arr.forEach((x, i) => {
    let small = 0;
    for (let t = i + 1; t < arr.length; t++) {
      if (arr[t] < x) {
        small++;
      }
    }
    res += small * table[arr.length - i - 1];
  })
  return res;
};


console.log(cantor([ 2, 3, 0, 4, 1 ]));


/**
 * @param {number} num
 * @param {number} size 需要排列的个数
 * @returns {number[]}
 */

let deContor = function (num, size) {
  let visited = new Array(size).fill(false);
  let res = [];
  while (size--) {
    let result = Math.floor(num / table[size]);
    num -= result * table[size];
    console.log(result, num)
    let temp = 0;
    let index = 0;
    while(temp < result) {
      if(!visited[index]) {
        temp++;
      } 
      index++
    }
    while(visited[index]) index++;
    visited[index] = true;
    console.log(visited)
    res.push(index);
  }
  return res;
}

console.log(deContor(61, 5));