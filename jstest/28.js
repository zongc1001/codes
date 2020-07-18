function partialUsingArguments(fn) {
    let args = Array.prototype.slice.apply(arguments, [1]);
    let result = function () {
        let arg = Array.prototype.slice.apply(arguments);
        return fn.apply(null, args.concat(arg));
    }
    return result;
}

function a() {
    Array.prototype.slice.apply(arguments).forEach(x=>{
        console.log(x);
    });
}

let t = partialUsingArguments(a, 2, 3);
t(5, 56)