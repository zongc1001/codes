/**
 * @param {string} s 
 * @return {boolean}
 * @param {char} a
 * @param {char} a
 * @return {boolean}
 */
var isValid = function(s) {
    let stk = new Array();
    if(s.length === 0) return true;
    // console.log(s.split(""));
    s.split("").forEach(x => {
        if(stk.length === 0) stk.push(x);
        else {
            // console.log(match(x, stk[stk.length-1]));
            // console.log(x, stk[stk.length-1])
            match(x, stk[stk.length-1]) || match(stk[stk.length-1], x) ? stk.pop() : stk.push(x);
            
        }

        // console.log(x, stk);
    });
    
    return stk.length === 0;
};

var match = function(a,b) {
    return (a==='(' && b===')') || (a==='[' && b===']') || (a==='{' && b==='}');
}


console.log(isValid("{[]}"));