/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    
    let t = String('1');
    if(n === 1) return '1';
    else {
        let t = countAndSay(n - 1);
        let a = t.split('');
        let k = 0;
        let num = 0, ch = a[0];
        // console.log('a', a);
        a.forEach(e => {
            if(ch !== e) {
                a[k++] = num + '' + ch;
                num = 1;
                ch = e;
            } else {
                num++;
            }
        });
        a[k++] = num + '' + ch;
        a.length = k;
        return a.join('');
    }
};

// console.log(countAndSay(5));