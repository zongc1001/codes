// function deepClone(obj) {
//     let newObj = Array.isArray(obj) ? [] : {};
//     if (obj && typeof obj === "object") {
//         for (let i in obj) {
//             if (obj.hasOwnProperty(i)) {
//                 if (obj[i] && typeof obj[i] === "object") {
//                     newObj[i] = deepClone(obj[i]);
//                 } else {
//                     newObj[i] = obj[i];
//                 }
//             }
//         }
//     }
//     return newObj;
// }

function deepCopy(target, cache = new Set()) {
    console.log(cache)
    // 注意环引用
    if (
        (typeof target !== 'object' && target !== null) ||
        cache.has(target)
    ) {
        return target
    }
    if (Array.isArray(target)) {
        return target.map(t => {
            cache.add(t)
            return t
        })
    } else {
        // 遍历target的属性，包括以symbol为key的属性
        return [
            ...Object.keys(target),
            ...Object.getOwnPropertySymbols(target)
        ].reduce(
            (res, key) => {
                cache.add(target[key])
                res[key] = deepCopy(target[key], cache)
                return res
            },
            target.constructor !== Object ? Object.create(target.constructor.prototype) : {}
        ) // 继承
    }
}

let t = {
    a: {
        bb: 1,
        c: {
            a: 2,
            b: "fdsad",
        }
    }
}
t.a.f = t;
let a = deepCopy(t);
// let a = deepClone(t);
console.log(a);

// t[Symbol("a")] = "fdas";

// console.log(Object.getOwnPropertySymbols(t));


