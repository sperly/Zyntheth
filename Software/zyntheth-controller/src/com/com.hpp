#pragma once

#include <vector>
#include "valuecontainer.hpp"

class Com
{
 public:
    Com(ValueContainer &vc);
    void Send();

    template <typename SerializeType>
    static void Serialize(SerializeType const property, std::vector<uint8_t> &container_payload)
    {
        Serialize<SerializeType, SerializeType>(property, container_payload);
    }

    template <typename DeserializeType>
    static DeserializeType Deserialize(uint8_t const *data, uint8_t &startPos)
    {
        return Deserialize<DeserializeType, DeserializeType>(data, startPos);
    }

 private:
    ValueContainer &valueCon;

    void sendPacket();

    template <typename SerializeType, typename Data>
    static void Serialize(SerializeType const property, std::vector<uint8_t> &payload)
    {
        auto const length = sizeof(Data);
        for (uint8_t offset = 0; offset < length; ++offset)
        {
            uint8_t shift = ((length - offset) * 8) - 8;
            payload.emplace_back(static_cast<uint8_t>((static_cast<Data>(property) >> shift) & 0xff));
        }
    }

    template <typename DeserializeType, typename Data>
    static DeserializeType Deserialize(uint8_t const *data, uint8_t &startPos)
    {
        Data value           = 0;
        uint8_t const length = sizeof(Data);

        for (uint8_t offset = 0; offset < length; ++offset)
        {
            uint8_t shift       = ((length - offset) * 8) - 8;
            uint16_t currentPos = startPos + offset;
            value |= static_cast<Data>(data[currentPos] << shift);
        }
        startPos += length;
        return static_cast<DeserializeType>(value);
    }
};
