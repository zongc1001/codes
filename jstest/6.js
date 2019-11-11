function truncate(arr) {
    let res = arr.slice();
    res.length -= (arr.length > 0);
    return res;
}

