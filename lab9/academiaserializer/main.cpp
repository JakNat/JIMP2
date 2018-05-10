//
// Created by bobo on 01.05.18.
//


#include <iosfwd>
#include <sstream>
#include "Serialization.h"

using namespace academia;

class Base {
public:
    virtual std::string foo() = 0;
};

class Derived : public Base {
public:
    std::string foo() override { return  "derived"; }
};
class BaseReferenceWrapper {
public:
    BaseReferenceWrapper(Base &base)
            : base_{&base} {}
    //zdefiniowany operator rzutujący na referencję
    //przez co typu można używać jak referencji
    operator Base&() {
        return *base_;
    }
private:
    Base *base_;
};
int main()
{   Room r1 {100167, "429", Room::Type::LECTURE_HALL};
    Room r2 {100168, "208", Room::Type::COMPUTER_LAB};
    Room r3 {100169, "216", Room::Type::COMPUTER_LAB};
    Building building {11, "C2", {r1, r2, r3}};
  //  std::vector<std::reference_wrapper<Base>> bases;
}