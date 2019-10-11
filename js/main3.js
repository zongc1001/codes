function recoverSecret(t) {
    var first = "";
    var noFirst = [];
    while(true)
    {
        noFirst = [];
        var nover = true;
        t.forEach(function(e) {
            if(e.length > 0) nover = false;
            for(var i = 1; i < e.length;i++) {
                if(!noFirst.includes(e[i])) {
                    noFirst.push(e[i]);
                }
            }
        }
        );
        var getted = false;
        for(let i = 0;i < t.length;i++) {
            if(t[i].length == 0) continue;
            if(!noFirst.includes(t[i][0])) {
                if(getted)
                    t[i].shift();
                else
                    first+= t[i].shift();
                getted = true;
            }
        }
        if(nover) break;
    }
    return first;
}
console.log(
    recoverSecret([  ['t', 'u', 'p'],  ['w', 'h', 'i'],  ['t', 's', 'u'],  ['a', 't', 's'],  ['h', 'a', 'p'],  ['t', 'i', 's'],  ['w', 'h', 's'] ])
)