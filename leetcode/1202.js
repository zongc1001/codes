/**
 * @param {string} s
 * @param {number[][]} pairs
 * @return {string}
 */
var smallestStringWithSwaps = function (s, pairs) {
  let len = s.length;
  let arr = new Array(len);
  for (let i = 0; i < len; i++) {
    arr[i] = i;
  }
  let rank = new Array(len);
  rank.fill(1);
  function find(num) {
    let que = [];
    while(arr[num] != num) {
      que.push(num);
      num = arr[num];
    }
    que.forEach(x => {
      arr[x] = num;
    })
    return num;
  }

  function merge(a, b) {
    let [afar, bfar] = [find(a), find(b)];
    if(rank[afar] < )
  }
  


  pairs.forEach(x => {
    let [a, b] = x;
    let [afar, bfar] = [find(a), find(b)];
    if(rank[afar] > rank[bfar]) {
      arr[b] = find(a);
    }
    arr[b] = find(a);
  })

};