//
// Created by bobo on 01.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


#include <string>
#include <vector>

namespace academia{
    class Serializer;
    class Serializable{
    public:
        Serializable();
        virtual void Serialize(Serializer* s) const = 0;
    };

    class Serializer{
    public:
         Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;

        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;

    };
    class JsonSerializer{

    };

    class Room : public Serializable{
    public:
        enum class Type{
            ALFA,
            CLASSROOM,
            LECTURE_HALL,
            COMPUTER_LAB,
        };
        Room(int id, std::string st, Type type);
        void Serialize(Serializer *s) const override;
        ~Room() = default;
    private:
        int id_;
        std::string st_;
        Type type_;
    };
    class Building{

    };



}


#endif //JIMP_EXERCISES_SERIALIZATION_H
