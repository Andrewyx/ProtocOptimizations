#include "main.h"

bool decode(const std::vector<uint8_t>& data, TbotsProto_PowerFrame& frame)
{
  pb_istream_t stream =
      pb_istream_from_buffer(data.data(), data.size());
  if (!pb_decode_nullterminated(&stream, &TbotsProto_PowerFrame_msg, &frame))
  {
    return false;
  }
  return true;
}



int main() {
  std::string lang = "C++";
  std::cout << "Hello and welcome to " << lang << "!\n";
  TbotsProto_PowerFrame input_frame = TbotsProto_PowerFrame_init_default;
  auto bytes = serializeToVector(input_frame);

  TbotsProto_PowerFrame output_frame = TbotsProto_PowerFrame_init_default;

  if (!decode(bytes, output_frame))
  {
    std::cout << "Failed to decode!" << std::endl;
  }
  else
  {
    std::cout << "Decoded!" << output_frame.crc << std::endl;
  }
  return 0;
}