function findAllOccurrences(arr, target) {
    let res = [];
    arr.forEach((element, index) => {
        if (element === target) res.push(index);
    });
    return res;
}
