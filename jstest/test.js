let obj = {
    value: 1,
    inc : function () {
        this.value ++;
        return this.value;
    }
}

console.log(obj["inc"]());
