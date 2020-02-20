#include "fuzzycontroler.h"

#include <iostream>

FuzzyControler::FuzzyControler(){

}

void FuzzyControler::addRule(Rule rule){
    rules_list.push_back(rule);
}

float FuzzyControler::getOut(){
    float out = 0;
    std::list<RuleOutput> unique_rules_outputs_list;
    for (std::list<Rule>::iterator it=rules_list.begin(); it != rules_list.end(); ++it){
        // out += it->calculate_input() * it->getOutValue();
        //int32_t out = INT32_MIN;
        if(isObjectUnique(unique_rules_outputs_list, *it)){
            std::cout << "nie ma " << it->calculate_input() << "\n";
            unique_rules_outputs_list.push_back(RuleOutput(it->calculate_input(), it->getOutValue(), *it->getOutMembership()));
        }
    }

    int32_t weight = 0;
    for (std::list<RuleOutput>::iterator it=unique_rules_outputs_list.begin(); it != unique_rules_outputs_list.end(); ++it){
        weight += it->input_membership_value;
        out += it->input_membership_value * it->out_value;
    }
    out = out / weight;
    return out;
}

uint8_t FuzzyControler::isObjectUnique(std::list<RuleOutput> &unique_list, Rule object){
    for (std::list<RuleOutput>::iterator it=unique_list.begin(); it != unique_list.end(); ++it){
        if(it->out_membership == object.getOutMembership()){
            std::cout << "jest " << (int) object.calculate_input() << " old " << (int)it->input_membership_value;
          //  it->input_membership_value = object.calculate_input();
            it->input_membership_value = std::max(it->input_membership_value, object.calculate_input());
            std::cout << " max " <<(int) it->input_membership_value << "\n";
            return false;
        }
    }
    return true;
}

FuzzyControler::RuleOutput::RuleOutput(int32_t input_membership_value, int32_t out_value, Membership &out_membership){
    this->input_membership_value = input_membership_value;
    this->out_value = out_value;
    this->out_membership = &out_membership;
}
