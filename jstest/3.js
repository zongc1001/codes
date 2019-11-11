function remove(arr, item) {
    let k = 0, res = new Array();
    arr.forEach(element => {
        if(element !== item) {
            res[k++] = element;
        }
    });
    return res;
}