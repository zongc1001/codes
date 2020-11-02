function sum(...rest) {
    // console.log(rest);
    let nums = rest;
    if(rest.length === 0) return 0;
    let newSum = function(...rest) {
        if(rest.length > 0) {
            nums = nums.concat(rest);
            return newSum;
        } else {
            return nums.reduce((a, b) => a + b);
        }
    }
    return newSum;
}

console.log(sum());