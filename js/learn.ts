
interface SearchFunc {
    (source: string, subString: string): boolean;
    (source: string, subString: number): number;
}

let a: SearchFunc = function (source: string, subString: number): boolean {
    console.log('fsadf');
    return true;
}

interface Counter {
    (start: number): string;
    interval: number;
    reset(): void;
}

function getCounter(): Counter {
    let counter = function (start: number) { } as Counter;
    counter.interval = 123;
    counter.reset = function () { };
    return counter;
}

let c = getCounter();
c(10);
c.reset();
c.interval = 5.0;