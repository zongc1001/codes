/**
 * @param {number[]} height
 * @return {number}
 */
'use strict'
var maxArea = function(height) {
    var len = height.length;
    var stk = new Array();
    var ans = 0;
    function Num(p, h) {
        this.p = p;
        this.h = h;
    }
    for(let i = 0; i < len;i++) {
        if(stk.length === 0)
            stk.push(new Num(i, height[i]));
        else {
            if(height[i] < stk[stk.length-1].h) {
                stk.forEach(function(temp){
                    let tempAns = Math.min(temp.h, height[i]) * (i - temp.p);
                    ans = Math.max(ans, tempAns);
                });
            } else {
                stk.push(new Num(i, height[i]));
            }
        }
    }
    // console.log(stk.length, ans)
    for(let i = stk.length-1; i > 0;i--) {

        stk.slice(0,i).forEach(function(x){
            // console.log(i)
            ans = Math.max(ans, Math.min(x.h, stk[i].h) * (stk[i].p - x.p));
        })
    }
    return ans;



};

console.log(maxArea([1,8,6,2,5,4,8,3,7]))

