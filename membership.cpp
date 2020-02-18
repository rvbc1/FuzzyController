#include "membership.h"
#include <algorithm>
#include <iostream>


Membership::Membership(Range range){
    this->range = &range;
}

void Membership::addPoint(Point point){
    for (std::list<Point>::iterator it=points_list.begin(); it != points_list.end(); ++it){
        if(it->getX() == point.getX()){
            return;
        } else if(it->getX() > point.getX()){
            points_list.insert(it, point);
            return;
        }
    }

    points_list.push_back(point);
}

void Membership::print(){
    for (std::list<Point>::iterator it=points_list.begin(); it != points_list.end(); ++it){
            std::cout << ' ' << (int)it->getX() << ' ' << (int)it->getY() << std::endl;
    }
}

std::list<Point> Membership::getPointList(){
    return points_list;
}
