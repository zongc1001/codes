/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */

class Pattern {
    constructor(val, p = 0) {
        this.val = val;
        this.p = p;
        
    }
}

var isMatch = function(s, p) {
    let i = 0, j = 0, len1 = s.length, len2 = p.length;
    let res = true, numOfStar = 0;
    
    let pArr = new Array();
    for(let i = 0; i < len2; i++) {
        if(p[i] === '*') {
            pArr[pArr.length-1].p = 1;
            numOfStar ++;
        } else{
            pArr.push(new Pattern(p[i]));
        }
    }
    let matchEmpty = numOfStar * 2 === len2 || len2 === 0;
    // console.log(matchEmpty);
    if(len1 === 0) {
        return matchEmpty;
    }
    // console.log(pArr)
    let len3 = pArr.length;
    while(i < len1 && i < len3) {
        let cur = pArr[j];
        if(cur.val !== '.' && cur.val !== s[i]) {
            if(cur.p === 1) {
                j++;
            } else {
                return false;
                
            }
        } else if (cur.val === s[i] || cur.val == '.') {
            i++;
            if(cur.p !== 1) {
                j++;
            }
        }
    }
    return len1 === i && j > len3;

};
console.log(isMatch("", "t*f*g*"))