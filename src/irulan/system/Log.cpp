#include "irulan/system/Log.h"
#include <iostream>

namespace iru {
    Log defaultLog(std::cout);

    Log::~Log() {
        stream->flush();
    }

    Log& Log::operator<<(const std::string& string) {
        *stream << string;
        return *this;
    }

    Log& Log::operator<<(const int& val) {
        *stream << val;
        return *this;
    }

    Log& Log::operator<<(const float& val) {
        *stream << val;
        return *this;
    }

    Log& Log::operator<<(const unsigned int& val) {
        *stream << val;
        return *this;
    }

}