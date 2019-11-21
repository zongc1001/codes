function fizzBuzz(num) {
    let b1 = num % 3,
        b2 = num % 5;
    let r1 = "fizz",
        r2 = "buzz";
    if (isNaN(num) && num !== null) {
        return false;
    } else if (b1 === 0 && b2 === 0) {
        return r1 + r2;
    } else if (b1 === 0) {
        return r1;
    } else if (b2 === 0) {
        return r2;
    } else {
        return num;
    }

}