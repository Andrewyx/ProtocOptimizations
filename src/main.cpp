
#include <iostream>
#include <vector>
#include <stdexcept>

extern "C" {
#include "pb_encode.h"
#include "pb_decode.h"
#include "proto/simple.pb.h"
}

// Encode PowerFrame into vector
std::vector<uint8_t> encodeToVector(const PowerFrame& frame) {
    // First, measure encoded size
    pb_ostream_t sizestream = PB_OSTREAM_SIZING;
    if (!pb_encode(&sizestream, PowerFrame_fields, &frame)) {
        throw std::runtime_error("Failed to size PowerFrame: " + std::string(PB_GET_ERROR(&sizestream)));
    }

    size_t size = sizestream.bytes_written;
    std::vector<uint8_t> buffer(size);

    // Real encode into buffer
    pb_ostream_t stream =
        pb_ostream_from_buffer(static_cast<uint8_t*>(buffer.data()), buffer.size());

    if (!pb_encode(&stream, PowerFrame_fields, &frame)) {
        throw std::runtime_error("Failed to encode PowerFrame: " + std::string(PB_GET_ERROR(&stream)));
    }

    // Dump all bytes
    std::cout << "[encode] ";
    for (auto by : buffer) {
        printf("%02X ", by);
    }
    std::cout << "\nbytes written: " << stream.bytes_written << std::endl;

    return buffer;
}

// Decode PowerFrame from vector
bool decodeFromVector(const std::vector<uint8_t>& data, PowerFrame& frame) {
    frame = PowerFrame_init_zero;

    pb_istream_t stream =
        pb_istream_from_buffer(static_cast<const uint8_t*>(data.data()), data.size());

    if (!pb_decode(&stream, PowerFrame_fields, &frame)) {
        printf("pb_decode error: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    std::cout << "[decode] length=" << frame.length
              << " crc=" << frame.crc
              << " which_power_msg=" << frame.which_power_msg
              << std::endl;
    return true;
}

int main() {
    std::cout << "Hello nanopb demo!\n";

    // Prepare an input frame
    PowerFrame input = PowerFrame_init_zero;
    input.length = 42;
    input.crc = 1234;
    input.which_power_msg = PowerFrame_power_control_tag;

    // Encode to vector
    auto encoded = encodeToVector(input);

    // Decode back
    PowerFrame output;
    if (!decodeFromVector(encoded, output)) {
        return 1;
    }

    std::cout << "Done\n";
    return 0;
}
