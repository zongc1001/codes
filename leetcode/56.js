/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
  intervals = intervals.sort((x, y) => x[0] - y[0]);
  intervals.push([Infinity, Infinity]);
  let res = [];
  intervals.reduce((x, y) => {
    if(y[0] > x[1]) {
      res.push(x);
      return y;
    } else {
      return [x[0], Math.max(y[1], x[1])];
    }
  });
  return res;
};

// let input = [[1,4],[2,3]];
// console.log(merge(input));