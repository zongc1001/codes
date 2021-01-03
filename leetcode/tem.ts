class Animal {

}
class Cat extends Animal {
  miao() {}
}

class Dog extends Animal{
  wang() {}
}
const cat = new Cat();

function fun1(arg1: Animal) {

}

function fun2(): Dog {
  return new Dog();
}

fun1(fun2());
