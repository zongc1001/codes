


function test(arg) {
    arg = Math.random(2);
    console.log(arg);
    setTimeout(() => {
        if (arg > 0.5) {
            resolve("成功");
        } else {
            reject("失败");
        }
    }, 500);

}

let t = new Promise(test);
t.then(resolve).catch(reject);