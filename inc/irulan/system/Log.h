#ifndef IRULAN_LOG_H
#define IRULAN_LOG_H

#include <ostream>
#include <string>

namespace iru {
    class Log {
    public:
        Log(std::ostream& stream) : stream(&stream) {};
        ~Log();

        std::ostream& operator()(){return *stream;};

    private:
        std::ostream* stream;
    };


    extern Log defaultLog;
}

#endif //IRULAN_LOG_H
