#include "BinaryFileHandler.h"
#include <fstream>

namespace BinaryIO {
    bool BinaryFileHandler::writeToFile(const std::string& path, const std::vector<uint8_t>& data) {
        std::ofstream out(path, std::ios::binary);
        if (!out) return false;
        out.write(reinterpret_cast<const char*>(data.data()), data.size());
        return true;
    }

    bool BinaryFileHandler::readFromFile(const std::string& path, std::vector<uint8_t>& data) {
        std::ifstream in(path, std::ios::binary | std::ios::ate);
        if (!in) return false;

        std::streamsize size = in.tellg();
        in.seekg(0);
        data.resize(static_cast<size_t>(size));
        in.read(reinterpret_cast<char*>(data.data()), size);

        return true;
    }
}