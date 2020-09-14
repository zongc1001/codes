/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {

  let row = board.length;
  let col = board[0].length;

  let dir = [
    [-1, 0], [1, 0], [0, -1], [0, 1]
  ];

  let visited = new Array(row);
  for (let i = 0; i < visited.length; i++) {
    visited[i] = new Array(col).fill(false);
  }
  // console.log(visited);
  let index = 0;
  let res = false;
  for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
      if (word[index] === board[i][j]) {
        dfs(i, j);
        if (res) break;
      }
    }
    if (res) break;
  }
  return res;
  function dfs(i, j) {
    
    if (board[i][j] === word[index]) {
      if (index === word.length - 1) {
        res = true;
        return;
      }
      index++;
      visited[i][j] = true;
      dir.forEach(x => {
        let ii = x[0] + i;
        let jj = x[1] + j;
        if (ii >= 0 && ii < row && jj >= 0 && jj < col &&
          board[ii][jj] === word[index] && !visited[ii][jj] && !res) {
          dfs(ii, jj);
        }
      })
      index--;
      visited[i][j] = false;
    }
  }
};
