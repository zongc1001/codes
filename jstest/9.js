function concat(arr1, arr2) {
    let res = arr1.slice(), k = arr1.length;
    for(let i = 0; i < arr2.length; i++) {
        res[k++] = arr2[i];
    }
    return res;
}