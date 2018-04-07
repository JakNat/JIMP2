//
// Created by bobo on 06.04.18.
//

#ifndef JIMP_EXERCISES_DZIECKO_H
#define JIMP_EXERCISES_DZIECKO_H
using namespace std;
namespace parents {
    class Dziecko {
        friend class Rodzic;

    private:
        std::string name_;
        strng surname_;
        int age_;
        string school_;

    public:
        Dziecko();

        ~Dziecko();
        void przepiszDoInnejSzkoły(string school);
    };
}

#endif //JIMP_EXERCISES_DZIECKO_H
