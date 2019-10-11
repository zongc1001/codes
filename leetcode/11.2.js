var maxArea = function(height) {
    var res = 0, begin = 0, end = height.length-1;
    while(begin < end) {
        
        res = Math.max(res, Math.min(height[begin], height[end]) * (end - begin));
        height[begin] < height[end] ? begin++ : end--;
    }
    return res;
}

console.log(maxArea([1,3,2,5,25,24,5]))