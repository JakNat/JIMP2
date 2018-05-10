//
// Created by bobo on 01.05.18.
//

#include <iostream>
#include "Serialization.h"
using namespace std;
namespace academia{


    Serializable::Serializable() {}
    Serializer::Serializer(std::ostream *out) {}

    /////////// Room ///////////////////////
    Room::Room(int id, std::string st, academia::Room::Type type) {
        id_ = id;
        st_ = st;
        type_ = type;
    }
    std::string Room::enumToString(academia::Room::Type v) const {
        switch (v)
        {
            case academia::Room::Type::CLASSROOM:   return "CLASSROOM";
            case academia::Room::Type::LECTURE_HALL:   return "LECTURE_HALL";
            case academia::Room::Type::COMPUTER_LAB: return "COMPUTER_LAB";
            default:      return "[Unknown Room Type]";
        }
    }
    void Room::Serialize(academia::Serializer *s) const {
        s->Header("room");

        s->IntegerField("id",id_);
        s->StringField("name",st_);
        s->StringField("type",enumToString(type_));
        s->Footer("room");
    }

    ////////////// Building /////////////////
    Building::Building() : Serializable() {

    }
    Building::Building(int id, std::string name, std::vector<academia::Room> rooms) {
        id_= id;
        name_ = name;
        rooms_ = rooms;
    }

    void Building::Serialize(Serializer *s) const {
        s->Header("building");
        s->IntegerField("id",id_);
        s->StringField("name", name_);
        s->Array2Field("rooms",rooms_);

        s->Footer("building");
    }


    ////////////// Json ///////////////

    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {
    out_ = out;
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "\"" << field_name << "\": " << value << "";
    }
    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << ", \"" << field_name << "\": \"" << value << "\"";
    }
    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }
    void JsonSerializer::Footer(const std::string &object_name) {

        *out_ << "}";
    }
    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const Serializable>> &value) {
        *out_ << ", \"" << field_name << "\":";
    }
    void JsonSerializer::Array2Field(const std::string &field_name, const std::vector<academia::Room> &value) {
        *out_ << ", \"" << field_name << "\": [";

        JsonSerializer serializer{out_};
        for (int i = 0; i < value.size(); ++i) {
            value[i].Serialize(&serializer);
            if(i != value.size() - 1){
                *out_ << ", ";
            }
        }
        *out_ << "]";
    }
 ///////////////////   Xml  ////////////////////





    //////////////////////
    void JsonSerializer::DoubleField(const std::string &field_name, double value) {}
    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {}
    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {}

//





    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {
        out_ = out;
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {

    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const Serializable>> &value) {

    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

    void XmlSerializer::Array2Field(const std::string &field_name, const std::vector<Room> &value) {
        *out_ << "<" << field_name << ">";

        XmlSerializer serializer{out_};
        for (int i = 0; i < value.size(); ++i) {
            value[i].Serialize(&serializer);
        }
        *out_ << "<\\" << field_name << ">";
    }
}
