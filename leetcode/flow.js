/**
 * @flow
 */

type a = 1;

function cloneObject(obj) {
  const clone = {};

  Object.keys(obj).forEach(key => {
    clone[key] = obj[key];
  });

  return clone;
}

function cloneObject1(obj) {
  const clone = {};

  Object.keys(obj).forEach(key => {
    clone[key] = obj[key];
  });

  return ((clone: any): typeof obj); 
}


let a = cloneObject();
let b = cloneObject1();