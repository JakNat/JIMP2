//
// Created by bobo on 01.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


#include <string>
#include <vector>
#include <sstream>
#include <experimental/optional>

namespace academia{
    class Serializer;
    class JsonSerializer;
    class XmlSerializer;
    class Room;


    class Serializable{
    public:
        Serializable();
        virtual void Serialize(Serializer* s) const = 0;
       // virtual void Serialize(JsonSerializer* s) const = 0;
      //  virtual void Serialize(XmlSerializer* s) const = 0;
    };


    class Room : public Serializable{
    public:
        enum class Type{
            CLASSROOM,
            LECTURE_HALL,
            COMPUTER_LAB,
        };
        std::string enumToString(Type v) const;
        Room(int id, std::string st, Type type);
        void Serialize(Serializer *s) const override;

        ~Room() = default;
    private:
        int id_;
        std::string st_;
        Type type_;
    };

    class Building : public Serializable{
    public:
        Building();
        Building(int, std::string, std::vector<Room>);
        void Serialize(Serializer *s) const override;
        Building value();
        int Id();



        int id_;
        std::string  name_;
        std::vector<Room> rooms_;
        std::vector<std::reference_wrapper<const Serializable>> roomsW_;

    };


    class BuildingRepository {
    private:
        std::vector<Building> buildings;
    public:
        BuildingRepository();
        ~BuildingRepository() = default;
        BuildingRepository(Building);
        void Add(Building);
        void StoreAll(Serializer *serializer) const;
        int Id();
        std::experimental::optional<Building> operator[](int i) const ;

    };
/////////////////////

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
    class JsonSerializer : public Serializer{
    private:
        int id_;
        std::string st_;
        academia::Room::Type type_;
        std::ostream *out_ ;
    public:
        JsonSerializer(std::ostream *out);
        void TypeField(const std::string &field_name, Room::Type type);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const Serializable>> &value) override;

        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };
    class XmlSerializer : public Serializer{
        private:
        int id_;
        std::string st_;
        academia::Room::Type type_;
        std::ostream *out_ ;
    public:
        XmlSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;



    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
