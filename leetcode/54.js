/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
  if (matrix.length === 0 || matrix[0].length === 0) {
    return [];
  }
  let row = matrix.length;
  let col = matrix[0].length;
  let times = row * col;

  let res = [];
  let x = 0, y = -1;
  
  
  let next = (() => {
    let dir = [
      [0, 1], [1, 0], [0, -1], [-1, 0]
    ];
    let index = 0;
    let visited = new Array(row);
    for(let i = 0; i < visited.length;i++) {
      visited[i] = new Array(col).fill(false);
    }
    // console.log(visited);
    function ok(x, y) {
      return x >= 0 && x < row && y >= 0 && y < col;
    }

    return function () {
      let xx = x + dir[index][0];
      let yy = y + dir[index][1];

      if (ok(xx, yy) && !visited[xx][yy]) {
        x = xx;
        y = yy;
        
      } else {
        index++;
        if (index >= dir.length) {
          index = 0;
        }
        x = x + dir[index][0];
        y = y + dir[index][1];
      }
      visited[x][y] = true;
    }
  })();
  while (times--) {
    next();
    res.push(matrix[x][y]);
  }
  return res;
};

console.log(spiralOrder([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]))