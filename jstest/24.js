/**
 * 
 * @param {Array} arr 
 * @param {Function} fn 
 */
function makeClosures(arr, fn) {
    let res = [];
    arr.forEach((x, i) => {
        res.push(function () {
            return fn(arr[i]);
        })
    })

    return res;
}



