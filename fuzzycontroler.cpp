#include "fuzzycontroler.h"

#include <iostream>

FuzzyControler::FuzzyControler(){

}

void FuzzyControler::addRule(Rule rule){
    rules_list.push_back(rule);
}

int32_t FuzzyControler::getOut(){
    int32_t out = 0;
    for (std::list<Rule>::iterator it=rules_list.begin(); it != rules_list.end(); ++it){
        out += it->calculate_input() * it->getOutValue();
    }
    return out;
}
