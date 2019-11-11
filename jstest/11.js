function count(arr, item) {
    let count = 0;
    
    arr.forEach(element => {
        count += (element === item)
    });
    return count;
}