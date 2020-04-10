#include "ResourceManager.h"

namespace iru {
    inline ResourceManager::~ResourceManager() {
        for(auto &r : resources)
            delete r.second;
    }

    template<typename T>
    void ResourceManager::add(const std::string& name) {
        resources[name] = new T();
    }

    template<typename T>
    T* ResourceManager::get(const std::string& name) {
        return static_cast<T*>(resources[name]);
    }
}