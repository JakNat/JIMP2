//
// Created by bobo on 06.04.18.
//

#include "Rodzic.h"
namespace parents{
Rodzic::Rodzic() {}
Rodzic::Rodzic(string name, string surname, int age, Dziecko kid) {
    name_ = name;
    surname_ = surname;
    age_ = age;
    kid_ = kid;
}
Rodzic::~Rodzic() {

}
}