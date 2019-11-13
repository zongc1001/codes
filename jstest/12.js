/**
 * 
 * @param {Array} arr 
 */

function duplicates(arr) {
    let list = {},
        res = [];

    arr.forEach(x => {
        if (list[x]) {
            list[x] = false;
            res.push(x);

        } else  {
            list[x] = true;
        }
    });

    return res;
}

// console.log(duplicates([1, 2, 4, 4, 3, 3, 1, 5, 3]))