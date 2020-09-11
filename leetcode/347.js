class Obj {
  constructor(value, count) {
    this.value = value;
    this.count = count;
  }

}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
  let table = {};
  let arr = [];
  nums.forEach(x => {
    let strX = x.toString();
    if (table[strX] !== undefined) {
      table[strX]++;
    } else {
      table[strX] = 1;
    }
  })
  Object.keys(table).forEach(x => {
    arr.push(new Obj(x, table[x]));
  });
  arr.sort((x, y) => y.count - x.count);
  // console.log(arr);
  // console.log(Object.values(arr));
  arr = arr.map(x => parseInt( x.value, 10));
  
  return arr.slice(0, k);
};

// console.log(topKFrequent([1, 1, 2, 2, 2, 2, 3], 2));