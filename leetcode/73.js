/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function (matrix) {
  if (matrix.length === 0) return matrix;
  let columnFlag = false;
  for (let i = 0; i < matrix.length; i++) {
    if (matrix[i][0] === 0) {
      columnFlag = true;
      break;
    }
  }
  let rowFlag = false;
  for (let i = 0; i < matrix[0].length; i++) {
    if (matrix[0][i] === 0) {
      rowFlag = true;
      break;
    }
  }
  for (let i = 1; i < matrix.length; i++) {
    for (let j = 1; j < matrix[0].length; j++) {
      if (matrix[i][j] === 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  for (let i = 1; i < matrix.length; i++) {
    if (matrix[i][0] === 0) {
      for (let j = 1; j < matrix[0].length; j++) {
        matrix[i][j] = 0;
      }
    }
  }
  for (let i = 1; i < matrix[0].length; i++) {
    if (matrix[0][i] === 0) {
      for (let j = 1; j < matrix.length; j++) {
        matrix[j][i] = 0;
      }
    }
  }




  if (columnFlag) {
    for (let i = 0; i < matrix.length; i++) {
      matrix[i][0] = 0;
    }
  }
  if (rowFlag) {
    for (let j = 0; j < matrix[0].length; j++) {
      matrix[0][j] = 0;
    }
  }


};