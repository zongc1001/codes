/**
 * 
 * @param {String} arg 
 */

function sulution(arg) {
  if (arg[0] !== '"' || arg[arg.length - 1] !== '"') {
    return false;
  }
  let flag = true;
  let stk = [];
  let left = ['[', '{', '('];
  let right = [']', '}', ')'];

  

  arg.split('').forEach(x => {
    try {
      console.log(stk);
      if (x === '"') return;
      if (left.find(t => t === x) !== undefined) {
        stk.push(x);
      } else {
        if (stk[stk.length - 1] === x) {
          stk.pop();
        } else {
          throw new Error();
        }
      }
    } catch (error) {
      flag = false;
    }

  })
  if (stk.length > 0) return false;
  else return flag;

}

console.log(sulution('"{([]])}"'))