//
// Created by bobo on 01.04.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
namespace nets{

    class View {
    public:
        View();
        View(std::string text);
        ~View();
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;



    private:

        std::string text_;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
