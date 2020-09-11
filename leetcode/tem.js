'use strict';
const a = {
    e: {
        c: 2
    }
}
Object.freeze(a.e);
a.e = {}
// a.e.c  = 1;
console.log(a.e.c)