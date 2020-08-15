typedef ManyOperation(int firstNo, int secondNo);
typedef Runner = void Function();
void run(Runner runner) => runner();
void main(List<String> args) {
  int add1(int x, int y) => x + y;

  var add2 = add1;
  var add3 = (x, y) => x + y;

  void afd() {
    print("fdaf");
    
  }


  run(afd);
}
