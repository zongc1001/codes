function functionFunction(str) {
    let t = function(s) {
        return str + ", " + s;
    }
    return t;
}

console.log(functionFunction("sfdasf")("fadfads")("lalalla"));