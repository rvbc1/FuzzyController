#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <range.h>
#include <point.h>
#include <list>

class Membership{
public:
    Membership(Range range);

    void addPoint(Point point);
    void print();

    std::list<Point> getPointList();
private:
    Range* range;

    std::list<Point> points_list;
};

#endif // MEMBERSHIP_H
