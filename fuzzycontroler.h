#ifndef FUZZYCONTROLER_H
#define FUZZYCONTROLER_H

#include <rule.h>

class FuzzyControler{
public:
    FuzzyControler();
    void addRule(Rule rule);
    int32_t getOut();
private:
    std::list<Rule> rules_list;
};

#endif // FUZZYCONTROLER_H
