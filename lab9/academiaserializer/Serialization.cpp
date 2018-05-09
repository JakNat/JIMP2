//
// Created by bobo on 01.05.18.
//

#include "Serialization.h"

namespace academia{
    Serializable::Serializable() {}
    Serializer::Serializer(std::ostream *out) {}
    Room::Room(int id, std::string st, academia::Room::Type type) {}

    void Room::Serialize(academia::Serializer *s) const {
        const int i = 4;
        const std::string r = "room";
        s->Header("room");
        s->IntegerField("room",5);
        s->StringField("room1","5");
        s->StringField("room2","13");
        s ->Footer("Footer");
    }
}