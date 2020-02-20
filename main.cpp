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

    Membership *out_n = new Membership(Range(0, 150), Range(-10, 10));
    out_n->addPoint(Point(0, -10));
    Membership *out_z = new Membership(Range(0, 150), Range(-10, 10));
    out_z->addPoint(Point(0, 0));
    Membership *out_p = new Membership(Range(0, 150), Range(-10, 10));
    out_p->addPoint(Point(0, 10));

    //m->print();

    //cout << (int)m->getValue(49);

//    for(int i = 0; i < 150; i+=4){
//        cout << (int)low->getValue(i) << "\t";
//    }

//    cout << endl;

//    for(int i = 0; i < 150; i+=4){
//        cout << (int)mid->getValue(i) << "\t";
//    }

//    cout << endl;

//    for(int i = 0; i < 150; i+=4){
//        cout << (int)high->getValue(i) << "\t";
//    }

//    cout << endl;

    int32_t in1, in2;
    in1 = 36;
    in2 = 36;
    int32_t o1 = 0;

    Rule *r1 = new Rule();
    r1->addInput(in1, *low);
    r1->addInput(in2, *mid);
    r1->addOutput(o1, *out_z);

    Rule *r2 = new Rule();
    r2->addInput(in1, *low);
    r2->addInput(in2, *low);
    r2->addOutput(o1, *out_z);

    Rule *r3 = new Rule();
    r3->addInput(in1, *mid);
    r3->addInput(in2, *mid);
    r3->addOutput(o1, *out_z);

    Rule *r4 = new Rule();
    r4->addInput(in1, *mid);
    r4->addInput(in2, *low);
    r4->addOutput(o1, *out_p);


    fuzzy_controler->addRule(*r1);
    fuzzy_controler->addRule(*r2);
    fuzzy_controler->addRule(*r3);
    fuzzy_controler->addRule(*r4);


    cout <<  fuzzy_controler->getOut() << endl;
    in1 = 40;
    in2 = 45;
    cout <<  fuzzy_controler->getOut() << endl;

    Range r(50, 70);
    return 0;
}
