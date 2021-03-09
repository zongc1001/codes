/**
 * @param {string} s
 * @return {number[][]}
 */
var largeGroupPositions = function (s) {
  let curChar = ' ';
  let tempBegin = 0;
  let res = [];
  for (let i = 0; i < s.length ;i++) {
    if(s[i] !== curChar) {
      if(i - tempBegin >= 3) {
        res.push([tempBegin, i - 1]);
      }
      tempBegin = i;
      curChar = s[i];
    }
  }
  if(s.length - tempBegin >= 3) {
    res.push([tempBegin, s.length - 1]);
  }
  return res;
};