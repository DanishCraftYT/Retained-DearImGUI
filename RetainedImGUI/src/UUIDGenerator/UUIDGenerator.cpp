#include "UUIDGenerator.hpp"

std::string UUIDGenerator::generateUUID() {
    return boost::uuids::to_string(boost::uuids::random_generator()());
}
