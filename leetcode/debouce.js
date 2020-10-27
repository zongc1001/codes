/**
 * 
 * @param {Function} func 
 * @param {Number} wait 
 * @param {Boolean} immediate 
 */
function debouce(func, wait = 50, immediate = true) {
    let timer = null, context, args;
    let later = () => setTimeout(() => {
        timer = null;
        if(!immediate) {
            func.apply(context, args);
            context = args = null;
        }
    }, wait);
    return function(...rest) {
        if(timer) {
            clearTimeout(timer);
            timer = later();
        } else {
            timer = later();
            if(immediate) {
                func.apply(this, rest);
            } else {
                context = this;
                args = rest;
            }
        }
    }
}