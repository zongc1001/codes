function count(start, end) {
    console.log(start);
    
    setInterval(() => {
        console.log(start++);
    }, 100);
}

function functions(flag) {
    let getValue ;
    if (flag) {
      getValue = function(){ return 'a'; }
    } else {
      getValue = function () { return 'b'; }
    }
    return getValue();
}

console.log(functions(true), functions(false));

