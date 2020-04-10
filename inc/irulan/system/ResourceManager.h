#ifndef IRULAN_RESOURCEMANAGER_H
#define IRULAN_RESOURCEMANAGER_H

#include "Resource.h"
#include <string>
#include <unordered_map>

namespace iru {
    class ResourceManager {
    public:
        ResourceManager(){};
        ~ResourceManager();

        template<typename T>
        void add(const std::string& name);

        template<typename T>
        T* get(const std::string& name);
    private:
        std::unordered_map<std::string, Resource*> resources;
    };
}

#include "ResourceManager.tpp"

#endif //IRULAN_RESOURCEMANAGER_H
