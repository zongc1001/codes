function longestConsec(strarr, k) {
    let len = strarr.length;
    let i = 0, pos = 0;
    let max = 0;
    if(len == 0 || k > len || k <= 0)
        return "";
    else 
        for(i = len-k; i >= 0 ; i--) {
            let temp = strarr.slice(i, i+k).map(x => x.length).reduce((x,y)=>x+y);
            // console.log(strarr.slice(i, i +k))
            max = temp >= max ? (pos = i, temp) : max;
        }
    return strarr.slice(pos, pos+k).join('');
}
console.log(longestConsec(["zone", "abigail", "theta", "form", "libe", "zas"], 2));
console.log(longestConsec(["ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"], 1))
console.log(longestConsec([], 3))
console.log(longestConsec(["itvayloxrp","wkppqsztdkmvcuwvereiupccauycnjutlv","vweqilsfytihvrzlaodfixoyxvyuyvgpck"], 2))
console.log(longestConsec(["wlwsasphmxx","owiaxujylentrklctozmymu","wpgozvxxiu"], 2))
console.log(longestConsec(["zone", "abigail", "theta", "form", "libe", "zas"], -2) )
console.log(longestConsec(["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 3))
console.log(longestConsec(["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 15))
console.log(longestConsec(["it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz"], 0))
console.log( longestConsec(["a", "b", "c", "d"], 3))