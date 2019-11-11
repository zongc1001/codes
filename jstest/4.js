function removeWithoutCopy(arr, item) {
    let k = 0;
    arr.forEach(element => {
        if(element !== item) {
            arr[k++] = element;
        }
    });
    arr.length = k;
    return arr;
}