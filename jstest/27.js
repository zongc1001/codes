function callIt(fn) {
    let args = Array.prototype.slice.apply(arguments);
    return fn.apply(null, args.slice(1));
}

let t = function (a , b) {
    return a + b;
}

console.log(callIt(t, 1, 2));


