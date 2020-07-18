function useArguments() {
    let args = Array.prototype.slice.apply(arguments);
    return args.reduce((x, y) => x + y);
}

console.log(useArguments(1,2,3,4));