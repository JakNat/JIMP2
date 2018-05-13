//
// Created by bobo on 01.05.18.
//


#include <iosfwd>
#include <sstream>
#include <functional>
#include <iostream>
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
{

    BuildingRepository repository{};
    Building
            b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
    Building b2{102, "B-2", {}};
    Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};
    std::stringstream out;
    JsonSerializer serializer{&out};

    repository.Add(b1);
    repository.Add(b2);
    repository.Add(c2);
    repository.StoreAll(&serializer);
  std::cout  <<  repository[103].value().Id();


    std::cout << out.str();
    return 0;
}