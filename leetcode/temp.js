function f(params) {
  Object.keys(params).forEach(x => {
    params[x] ?? delete params[x];
  });
}

let temp = {a: '', b: false, c: NaN, d: null, e: 1231}

f(temp);

console.log(temp);
