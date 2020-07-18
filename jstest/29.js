function curryIt(fn) {

    let res1 = function (arg1) {
        let res2 = function (arg2) {
            let res3 = function (arg3) {
                return fn(arg1, arg2, arg3);
            }
            res3.length = 1;
            return res3;
        }
        res2.length = 1;
        return res2;
    }
    res1.length = 1;
    return res1;
}

var fn = function (a, b, c) { return a + b + c };
console.log(curryIt(fn)(1)(2)(3));