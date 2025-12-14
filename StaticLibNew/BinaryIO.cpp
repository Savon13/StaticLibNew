#include "BinaryIO.h"

namespace BinaryIO {
    std::vector<uint8_t> serializeInt32(int32_t value) {
        std::vector<uint8_t> out(sizeof(int32_t));
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&value);
        std::copy(ptr, ptr + sizeof(int32_t), out.begin());
        return out;
    }

    std::vector<uint8_t> serializeDouble(double value) {
        std::vector<uint8_t> out(sizeof(double));
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&value);
        std::copy(ptr, ptr + sizeof(double), out.begin());
        return out;
    }

    std::vector<uint8_t> serializeString(const std::string& value) {
        uint32_t size = static_cast<uint32_t>(value.size());
        std::vector<uint8_t> out(sizeof(uint32_t) + size);

        const uint8_t* sizePtr = reinterpret_cast<const uint8_t*>(&size);
        std::copy(sizePtr, sizePtr + sizeof(uint32_t), out.begin());
        std::copy(value.begin(), value.end(), out.begin() + sizeof(uint32_t));

        return out;
    }

    int32_t deserializeInt32(const std::vector<uint8_t>& data, size_t& offset) {
        int32_t value{};
        uint8_t* ptr = reinterpret_cast<uint8_t*>(&value);
        std::copy(data.begin() + offset, data.begin() + offset + sizeof(int32_t), ptr);
        offset += sizeof(int32_t);
        return value;
    }

    double deserializeDouble(const std::vector<uint8_t>& data, size_t& offset) {
        double value{};
        uint8_t* ptr = reinterpret_cast<uint8_t*>(&value);
        std::copy(data.begin() + offset, data.begin() + offset + sizeof(double), ptr);
        offset += sizeof(double);
        return value;
    }

    std::string deserializeString(const std::vector<uint8_t>& data, size_t& offset) {
        uint32_t size{};
        uint8_t* sizePtr = reinterpret_cast<uint8_t*>(&size);

        std::copy(data.begin() + offset, data.begin() + offset + sizeof(uint32_t), sizePtr);
        offset += sizeof(uint32_t);

        std::string value(size, '\0');
        std::copy(data.begin() + offset, data.begin() + offset + size, value.begin());
        offset += size;

        return value;
    }
}