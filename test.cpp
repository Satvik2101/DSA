#include <iostream>
using namespace std;
class Foo {
  public:
    int val;
    Foo(int v) : val(v) {}
    void x() { delete this; }
};
class Bar {
  public:
    int val;
    int val2;
    int val3;
    int val4;
    Bar(int v) : val(v), val2(v) {}
    void x() { delete this; }
};

int main() {
    Foo *f = new Foo(3);
    cout << f->val << " ";
    f->x();
    cout << f << " ";
    int *f2 = new int[30];
    f = new Foo(3);
    // f->x();
    cout << f2 << " " << f << " ";
}