//
//  main.cpp
//  cs2final
//
//  Created by Bianca Amoako on 8/1/23.
//

#include <iostream>

class Shape {
public:
    Shape () {};
    virtual void draw () {
        std::cout << "shape" << std::endl;};
};
 
class Square : public Shape {
public:
    Square (): Shape() {};
    virtual void draw () {std::cout << "square" << std::endl;};
};
 
void foo(Shape x) {
    x.draw();
}
 
int main() {
    Shape *tbl[2];
    tbl[0] = new Shape();
    tbl[1] = new Square();
 
    foo(*tbl[1]);
    tbl[0]->draw();
    tbl[1]->draw();
    return 0;
}
