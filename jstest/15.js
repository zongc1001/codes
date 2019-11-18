function functions(flag) {
    let getValue;
    if (flag) {
      getValue = function(){ return 'a'; }
    } else {
      getValue = function () { return 'b'; }
    }

    return getValue();
}