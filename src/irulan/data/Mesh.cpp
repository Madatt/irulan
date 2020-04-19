#include "irulan/data/Mesh.h"
#include "irulan/system/Log.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace iru {
    auto splitFace(const std::string& t_str) {
        std::vector<std::string> vec;

        size_t pos = 0;
        auto end = t_str.find('/');
        while (end != std::string::npos) {
            vec.push_back(t_str.substr(pos, end - pos));
            pos = end + 1;
            end = t_str.find('/', pos);
        }
        vec.push_back(t_str.substr(pos));
        return vec;
    }


    void Mesh::loadObj(const std::string& path) {
        vertices.clear();
        std::vector<Vector3f> pos;
        std::vector<Vector2f> posTex;
        std::vector<Vector3f> norm;

        defaultLog() << "[Mesh] Loading model from file: " << path << "\n";

        std::ifstream file(path);
        std::string line, c, f;
        float x, y, z;
        while (std::getline(file, line)) {
            std::istringstream buff(line);
            buff >> c;
            if (c == "v") {
                buff >> x >> y >> z;
                pos.emplace_back(x, y, z);
            } else if (c == "vt") {
                buff >> x >> y;
                posTex.emplace_back(x, y);
            } else if (c == "vn") {
                buff >> x >> y >> z;
                norm.emplace_back(x, y, z);
            } else if (c == "f") {
                for (int i = 0; i < 3; i++) {
                    buff >> f;
                    auto vec = splitFace(f);
                    vertices.emplace_back(
                            pos[std::stoi(vec[0]) - 1],
                            posTex[std::stoi(vec[1]) - 1],
                            norm[std::stoi(vec[2]) - 1]
                    );
                }
            }
        }

        defaultLog() << "[Mesh] Loaded model: " << vertices.size()/3 << " tris\n";
    }
}