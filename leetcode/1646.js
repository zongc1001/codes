/**
 * @param {number} n
 * @return {number}
 */
var getMaximumGenerated = function (n) {

    function returnGet() {
        let arr = [0, 1];
        return function get(n) {
            if (arr[n] !== undefined) return arr[n];
            let i = n & 1 ? Math.floor((n - 1) / 2) : Math.floor(n / 2) - 1;
            let temp = get(i) + get(i + 1);
            arr[n] = temp;
            console.log(n, temp);
            return temp;
        }
    }
    

    return returnGet()(n);
};

console.log(getMaximumGenerated(7));
