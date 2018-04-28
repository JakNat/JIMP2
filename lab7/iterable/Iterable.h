//
// Created by bobo on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <memory>

using ::std::make_unique;
namespace utility {

//--------------------------------------------------------------------------------------//
    class IterableIterator {
    protected:

    public:

        virtual std::pair<int , std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const  = 0;
        ~IterableIterator() = default;

       // virtual std::unique_ptr<IterableIterator> ConstBegin() const = 0;




    };
//--------------------------------------------------------------------------------------//
    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
         std::pair<int , std::string> Dereference() const override ;
         IterableIterator &Next() override ;
         //bool NotEquals(const IterableIterator &other) override ;
         bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override ;
        ~ZipperIterator() = default;


    protected:
        std::vector<int>::const_iterator left_;
        std::vector<std::string>::const_iterator right_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;

    };
//--------------------------------------------------------------------------------------//
    class Zipper{

    };
//--------------------------------------------------------------------------------------//
    class IterableIteratorWrapper  {
    protected:

    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other) const ;
        std::pair<int, std::string> operator*() const ;
        IterableIteratorWrapper &operator++();
        std::unique_ptr<utility::IterableIterator> iterator_;
        //IterableIterator *iterator_;

    };

}

#endif //JIMP_EXERCISES_ITERABLE_H
