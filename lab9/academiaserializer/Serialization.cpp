//
// Created by bobo on 01.05.18.
//

#include <iostream>
#include <functional>
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
    Building Building::value() {
        return *this;
    }
    int Building::Id() {
        return id_;
    }

    void Building::Serialize(Serializer *s) const {

        std::vector<std::reference_wrapper<const Serializable>> rooms2;
        for (int i = 0; i < rooms_.size() ; ++i) {
            rooms2.push_back(rooms_[i]);
        }

        s->Header("building");
        s->IntegerField("id",id_);
        s->StringField("name", name_);

        s->ArrayField("rooms",rooms2);
      //  s->ArrayField("rooms",roomsW_);
       // s->Array2Field("rooms",rooms_);


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
    class klmkl{

    };
    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const Serializable>> &value) {
///        out_.str().lenght();

        if(field_name == "buildings") {
            *out_ << "\""<< field_name << "\": [";
        }else{
            *out_ << ", \"" << field_name << "\": [";
        }
        JsonSerializer serializer{out_};
        int i = -1;
        for(const Serializable &base : value){
            i++;
            base.Serialize(&serializer);
          //  *out_ << i ;
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
        *out_ << "<" << field_name << ">";

        XmlSerializer serializer{out_};
        int i = -1;
        for(const Serializable &base : value){
            i++;
            base.Serialize(&serializer);

        }

        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }


///////////////////////////////////// repo
BuildingRepository::BuildingRepository() {}
BuildingRepository::BuildingRepository(academia::Building building) {
        Add(building);
    }
void BuildingRepository::StoreAll(academia::Serializer *serializer) const {
        serializer->Header("building_repository");

    std::vector<std::reference_wrapper<const Serializable>> rooms2;
    for (int i = 0; i < buildings.size() ; ++i) {
        rooms2.push_back(buildings[i]);
    }

    serializer->ArrayField("buildings",rooms2);

        serializer->Footer("building_repository");

    }

    void BuildingRepository::Add(academia::Building building) {
        buildings.push_back(building);
    }
    std::experimental::optional<Building> BuildingRepository::operator[](int id) const {
        for(auto x : buildings){
            if( x.id_ = id){
                return x;
            }
        }
    }
/*BuildingRepository::BuildingRepository(academia::Building building) {

        buildings.push_back(building);
    }


    BuildingRepository::BuildingRepository() {

    }
    Building BuildingRepository::operator[](int i) const {
        for(auto x : buildings){
            if (x.id_ == i ){
                return x;
            }
        }

    }
*/


}


