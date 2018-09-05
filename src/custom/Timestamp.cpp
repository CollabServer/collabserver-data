#include "collabdata/custom/Timestamp.h"

#include <cassert>

namespace collab {


int Timestamp::_effectiveID = 0;


// -----------------------------------------------------------------------------
// Intitialization
// -----------------------------------------------------------------------------

Timestamp::Timestamp(const int value) {
    _id     = Timestamp::_effectiveID;
    _time   = std::chrono::time_point<std::chrono::steady_clock>::min();
}

Timestamp::Timestamp(const TimePoint time) {
    _id     = Timestamp::_effectiveID;
    _time   = time;
}

Timestamp Timestamp::now() {
    Timestamp t = {0}; // Dev note: See constructor doc to understand {0}
    t._id       = Timestamp::_effectiveID;
    t._time     = std::chrono::steady_clock::now();
    return t;
}

void Timestamp::effectiveID(const int id) {
    Timestamp::_effectiveID = id;
}


// -----------------------------------------------------------------------------
// Operators overload
// -----------------------------------------------------------------------------

Timestamp& Timestamp::operator=(const int value) {
    // Dev note: see constructor note
    _id   = Timestamp::_effectiveID;
    _time = std::chrono::time_point<std::chrono::steady_clock>::min();
    return *this;
}

Timestamp& Timestamp::operator=(const Timestamp& other) {
    _id = other._id;
    _time = other._time;
    return *this;
}

bool operator==(const Timestamp& rhs, const Timestamp& lhs) {
    return (rhs._time == lhs._time) && (rhs._id == lhs._id);
}

bool operator!=(const Timestamp& rhs, const Timestamp& lhs) {
    return !(rhs == lhs);
}

bool operator>(const Timestamp& rhs, const Timestamp& lhs) {
    if(rhs._time == lhs._time) {
        assert(rhs._id != lhs._id);
        return rhs._id > lhs._id;
    }
    return rhs._time > lhs._time;
}

bool operator<(const Timestamp& rhs, const Timestamp& lhs) {
    if(rhs._time == lhs._time) {
        assert(rhs._id != lhs._id);
        return rhs._id < lhs._id;
    }
    return rhs._time < lhs._time;
}


} // End namespace


