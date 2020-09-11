const p1 = new Promise(function (resolve, reject) {
    setTimeout(() => reject(new Error('fail')), 0)
})

const p2 = new Promise(function (resolve, reject) {
    setTimeout(() => resolve(p1), 1000)
})

p2.catch( x => {
    console.log(x);
})

let curTime = new Date().getTime();
while(new Date().getTime() - curTime < 500);
console.log(p2);
while(new Date().getTime() - curTime < 1000);
console.log(p2);
while(new Date().getTime() - curTime < 1000);
console.log(p2);
while(new Date().getTime() - curTime < 1000);
console.log(p2);
