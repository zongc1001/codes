let a = [3,3,2,2,4,3,4,5,3,4,2,2,2,2,4,2,2,3,2,3,4,3,2,3,3,2,2,1,2,2]
let b = [5,10,14,18,24,30,3,6,13,20,22,29,2,8,15,17,25,28,1,7,11,16,21,26,4,9,12,19,23,27];
let arr = new Array(5);

for(let i = 0; i < 5;i++) {
    let temp = 0;
    for(let j = 0; j < 6;j++) {
        temp += a[b[i*6 + j]-1];
    }
    arr[i] = temp;
}
console.log(a.length, b.length)
console.log(arr)
