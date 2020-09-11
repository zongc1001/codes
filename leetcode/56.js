/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
  intervals = intervals.sort((x, y) => x[0] - y[0]);
  let res = [];
  intervals.reduce((x, y) => {
    if(x[1] <= y[0]) {
      
    }
  })
};