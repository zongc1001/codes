
let a = new Promise(function (resovle, reject) {
    setTimeout(() => {
        resovle("fdafa");
    }, 500);
}).then(res => {
    console.log("1", res);
    return res;
}).then(res => {
    console.log("2:", res);
})