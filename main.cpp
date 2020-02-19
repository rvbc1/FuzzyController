#include <iostream>

#include "fuzzycontroler.h"
#include <membership.h>
#include <rule.h>

using namespace std;

int main(){
    FuzzyControler* fuzzy_controler = new FuzzyControler();
    Membership *low = new Membership(Range(0, 150));
    low->addPoint(Point(30,100));
    low->addPoint(Point(50,0));

    Membership *mid = new Membership(Range(0, 150));
    mid->addPoint(Point(30,0));
    mid->addPoint(Point(50,100));
    mid->addPoint(Point(100,100));
    mid->addPoint(Point(120,0));

    Membership *high = new Membership(Range(0, 150));
    high->addPoint(Point(100,0));
    high->addPoint(Point(120,100));

    Membership *out_n = new Membership(Range(0, 150));
    out_n->addPoint(Point(0, 0));
    Membership *out_z = new Membership(Range(0, 150));
    out_z->addPoint(Point(0, 1));
    Membership *out_p = new Membership(Range(0, 150));
    out_p->addPoint(Point(0, 2));

    //m->print();

    //cout << (int)m->getValue(49);

    for(int i = 0; i < 150; i+=4){
         cout << (int)low->getValue(i) << "\t";
    }

    cout << endl;

    for(int i = 0; i < 150; i+=4){
        cout << (int)mid->getValue(i) << "\t";
    }

    cout << endl;

    for(int i = 0; i < 150; i+=4){
        cout << (int)high->getValue(i) << "\t";
    }

    cout << endl;

    int32_t in1, in2;
    in1 = 36;
    in2 = 36;
    int32_t o1 = 0;

    Rule *r1 = new Rule();
    r1->addInput(in1, *low);
    r1->addInput(in2, *mid);
    r1->addOutput(o1, *out_z);
    fuzzy_controler->addRule(*r1);


    cout << (int) fuzzy_controler->getOut() << endl;
    in1 = 40;
    in2 = 40;
    cout << (int) fuzzy_controler->getOut() << endl;

    Range r(50, 70);
    return 0;
}
