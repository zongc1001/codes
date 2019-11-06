/**
 * 
 * @param {Array} arr 
 * @param {Number} item 
 */

function indexOf(arr, item) {
    if (arr.length === 0) return -1;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === item) {
            return i;
        }
    }
    
    return -1;
}

// let a = [3, 4, 5, 6, 3, 2];
// console.log(indexOf(a, 3));
