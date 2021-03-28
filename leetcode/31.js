function gene() {
  let res = [1, 1];
  const temp = (n) => {
    if (res[n] !== undefined) return res[n];
    res[n] = temp(n - 1) * n
    return res[n];
  }
  return temp;
}
const fact = gene();

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
  const len = nums.length;
  let conto = 0;
  nums.forEach((x, i) => {
    const multiple1 = len - i - 1;
    let multiple2 = x - 1;
    for (let t = 0; t < i; t++) {
      if (nums[t] < x) {
        multiple2--;
      }
    }
    conto += multiple1 * multiple2;
  })
  conto++;
  console.log(conto);
  if (conto === fact(len)) {
    for (let i = 0; i < len; i++) {
      nums[i] = i + 1;
    }
  } else {
    for (let i = len - 1; i >= 0; i--) {
      let fac = fact(i);
      nums[len - i - 1] = Math.floor(conto / fac);
      conto -= 
    }
  }

};

let t = [4, 3, 2, 1];
nextPermutation(t);
console.log(t);