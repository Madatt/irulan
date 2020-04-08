#ifndef IRULAN_MESH_H
#define IRULAN_MESH_H

#include "Vertex.h"
#include <vector>
#include <string>

namespace iru {
    class Mesh {
    public:
        std::vector<Vertex> vertices;

        Mesh(){};

        void loadObj(const std::string& path);
    };
}

#endif //IRULAN_MESH_H
