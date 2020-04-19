#include "irulan/system/Log.h"
#include <iostream>

namespace iru {
    Log defaultLog(std::cout);

    Log::~Log() {
        stream->flush();
    }

}