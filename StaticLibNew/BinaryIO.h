#pragma once
#ifndef BINARY_IO_H
#define BINARY_IO_H

#include <cstdint>
#include <vector>
#include <string>

namespace BinaryIO {
    std::vector<uint8_t> serializeInt32(int32_t value);
    std::vector<uint8_t> serializeDouble(double value);
    std::vector<uint8_t> serializeString(const std::string& value);

    int32_t deserializeInt32(const std::vector<uint8_t>& data, size_t& offset);
    double deserializeDouble(const std::vector<uint8_t>& data, size_t& offset);
    std::string deserializeString(const std::vector<uint8_t>& data, size_t& offset);
}

#endif