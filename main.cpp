#include <iostream>

#include "fuzzycontroler.h"
#include <membership.h>
#include <rule.h>

using namespace std;

int main(){
    FuzzyControler* fuzzy_controler = new FuzzyControler();
    Range x_data_range(-100, 100);
    Membership *low = new Membership(x_data_range); // default y range is pro mille - (0, 1000)
    low->addPoint(*new Point(-100,100)); //point out of range is moved to range edge
    Point last_point (-20, 0);
    low->addPoint(last_point); // added point can be changed but cannont change order (fisrt point should be always first etc)
    // point list is sorted only at creating, order mishmash will destroy linear interpolation

    Membership *mid = new Membership(x_data_range);
    mid->addPoint(*new Point(-60,0));
    mid->addPoint(*new Point(-20,100));
    mid->addPoint(*new Point(20,100));
    mid->addPoint(*new Point(60,0));

    Membership *high = new Membership(x_data_range);
    high->addPoint(*new Point(20,0));
    high->addPoint(*new Point(100,100));


    Range y_data_out_range(-45,45);
    Membership *out_left_strong = new Membership(x_data_range, y_data_out_range);
    out_left_strong->addPoint(*new Point(0, -45)); //Out Membership sholud be singleton (only one point), It doesn't matter what value has x
    Membership *out_left = new Membership(x_data_range, y_data_out_range);
    out_left->addPoint(*new Point(0, -25));
    Membership *out_center = new Membership(x_data_range, y_data_out_range);
    out_center->addPoint(*new Point(0, 0));
    Membership *out_right = new Membership(x_data_range, y_data_out_range);
    out_right->addPoint(*new Point(0, 25));
    Membership *out_right_strong = new Membership(x_data_range, y_data_out_range);
    out_right_strong->addPoint(*new Point(0, 45));


    int32_t in1, in2;
    in1 = 0;
    in2 = 0;

    Rule *r1 = new Rule();
    r1->addInput(in1, *low);
    r1->addInput(in2, *mid);
    r1->addOutput(*out_right);

    Rule *r2 = new Rule();
    r2->addInput(in1, *low);
    r2->addInput(in2, *low);
    r2->addOutput(*out_right_strong);

    Rule *r3 = new Rule();
    r3->addInput(in1, *mid);
    r3->addInput(in2, *mid);
    r3->addOutput(*out_center);

    Rule *r4 = new Rule();
    r4->addInput(in1, *mid);
    r4->addInput(in2, *low);
    r4->addOutput(*out_right);


    Rule *r5 = new Rule();
    r5->addInput(in1, *mid);
    r5->addInput(in2, *high);
    r5->addOutput(*out_left);

    Rule *r6 = new Rule();
    r6->addInput(in1, *high);
    r6->addInput(in2, *mid);
    r6->addOutput(*out_left);

    Rule *r7 = new Rule();
    r7->addInput(in1, *high);
    r7->addInput(in2, *high);
    r7->addOutput(*out_left_strong);


    fuzzy_controler->addRule(*r1);
    fuzzy_controler->addRule(*r2);
    fuzzy_controler->addRule(*r3);
    fuzzy_controler->addRule(*r4);
    fuzzy_controler->addRule(*r5);
    fuzzy_controler->addRule(*r6);
    fuzzy_controler->addRule(*r7);

    in1 = -50;
    in2 = -45;

    cout <<  fuzzy_controler->getOut() << endl;
    in1 = 70;
    in2 = 55;
    cout <<  fuzzy_controler->getOut() << endl;

    return 0;
}
