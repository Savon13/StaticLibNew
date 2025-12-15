#pragma once
#ifndef BINARY_FILE_HANDLER_H
#define BINARY_FILE_HANDLER_H

#include <string>
#include <vector>
#include <cstdint>
#include "BinaryIOExport.h"

namespace BinaryIO {
    class BINARYIO_API BinaryFileHandler {
    public:
        bool writeToFile(const std::string& path, const std::vector<uint8_t>& data);
        bool readFromFile(const std::string& path, std::vector<uint8_t>& data);
    };
}

#endif