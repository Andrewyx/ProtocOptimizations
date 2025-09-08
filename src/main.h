#pragma once

#include <iostream>
#include <vector>
#include "pb.h"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/simple.pb.h"


template <typename T>
std::vector<uint8_t> serializeToVector(const T& data)
{
    const pb_msgdesc_t* fields;
    int size;
    if (std::is_same<T, TbotsProto_PowerFrame>::value)
    {
        fields = TbotsProto_PowerFrame_fields;
        size   = TbotsProto_PowerFrame_size;
    }
    else if (std::is_same<T, TbotsProto_PowerPulseControl>::value)
    {
        fields = TbotsProto_PowerPulseControl_fields;
        size   = TbotsProto_PowerPulseControl_size;
    }
    else if (std::is_same<T, TbotsProto_PowerStatus>::value)
    {
        fields = TbotsProto_PowerStatus_fields;
        size   = TbotsProto_PowerStatus_size;
    }
    else
    {
        throw std::runtime_error("Unexpected type as argument");
    }

    std::vector<uint8_t> buffer(size);
    pb_ostream_t stream =
        pb_ostream_from_buffer(static_cast<uint8_t*>(buffer.data()), buffer.size());
    if (!pb_encode(&stream, fields, &data))
    {
        throw std::runtime_error(
            "Failed to encode PowerFrame msg to vector when converting nanopb to vector");
    }
    std::cout << "BYTES ENCODED: "<< stream.bytes_written << std::endl;
    return buffer;
}
