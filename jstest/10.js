function insert(arr, item, index) {
    let res = new Array();
    if(index > arr.length) index = arr.length;
    
    for(let i = 0; i < index;i++) {
        res[i] = arr[i];
    }
    res[index] = item;
    for(let i = index; i < arr.length;i++) {
        res[i + 1] = arr[i];
    }
    return res;
}