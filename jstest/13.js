function square(arr) {
    let res = [];
    arr.forEach(element => {
        res.push(Math.pow( element, 2));
    });
    return res;
}