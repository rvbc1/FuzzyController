#include <iostream>

#include "fuzzycontroler.h"
#include <membership.h>

using namespace std;

int main(){
    FuzzyControler* fuzzy_controler = new FuzzyControler();
    Membership *m = new Membership(Range(0, 100));
//    m->addPoint(Point(100,4));
//    m->addPoint(Point(1,1));
//    m->addPoint(Point(0,2));
//    m->addPoint(Point(5,3));
//    m->addPoint(Point(4,4));
//     m->addPoint(Point(-4,4));
//     m->addPoint(Point(100,8));
    m->print();
    return 0;
}
