function captureThreeNumbers(str) {
    let t = /\d{3}/g;
    let a = t.exec(str);
    return a ? a[0] : false;
}

console.log(captureThreeNumbers("43"));