class Point extends HTMLElement {
  x: number;
  y: number;
  constructor(x: number, y: number) {
    super();
    this.x = x;
    this.y = y;
  }
}


interface Rect {
  width: string;
  height: string;
  (fasd, adsfa): void;
}

type a = Rect & Point;

class T extends Point implements  Rect {
  width: string;
  height: string;
  
}

class T1 implements Point, Rect {
  x: number;
  y: number;
  width: string;
  height: string;
  constructor(): void;
}

function func123(arg1: a): void {
  console.log(arg1);
}
const temp = new T(1,2)
func123(new T(1,2));