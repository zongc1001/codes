let temp = [3, 100, 54, 6, 8, 9, 3];


/**
 * 
 * @param {number[]} arr 
 */
function makeHeap(arr) {
    let len = arr.length;
    for (let i = len - 1; i >= 0; i--) {
        let cur = i;
        let par = Math.ceil(cur / 2) - 1;
        if (arr[cur] < arr[par]) {
            [arr[cur], arr[par]] = [arr[par], arr[cur]];
        }

        while (true) {
            let child = -1;
            let left = cur * 2 + 1;
            let right = cur * 2 + 2;
            if (left < len && arr[left] < arr[cur]) {
                child = left;
            }
            if (right < len && arr[right] < arr[left] && arr[right] < arr[cur]) {
                child = right;
            }
            if(child !== -1) {
                [arr[cur], arr[child]] = [arr[child], arr[cur]];
                cur = child;
            } else {
                break;
            }
        }
    }
}

makeHeap(temp);
console.log(temp);

let a = 10, b = 99;
a ^= b;
b ^= a;
a ^= b;
console.log(a, b);