#ifndef IRULAN_LOG_H
#define IRULAN_LOG_H

#include <ostream>
#include <string>

namespace iru {
    class Log {
    public:
        Log(std::ostream& stream): stream(&stream){};
        ~Log();

        Log& operator<<(const std::string& string);
        Log& operator<<(const int& val);
        Log& operator<<(const unsigned int& val);
        Log& operator<<(const float& val);

    private:
        std::ostream* stream;
    };


    extern Log defaultLog;
}

#endif //IRULAN_LOG_H
