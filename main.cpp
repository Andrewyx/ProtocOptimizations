// #include "test.pb.h" // Include the generated nanopb header
#include "nano_test_pb/test.pb.h" // Include the generated nanopb header
// #include ""
// #include "test_subdir/subdir_test.pb.h"
#include <iostream>

int main() {
  auto lang = "C++";
  std::cout << "Hello and welcome to " << lang << "!\n";

  // Create a Geometry message
  Geometry geometry;
  // geometry.name("Triangle");
  // geometry.set_name("Triangle");
  // std::cout << geometry.name() << std::endl;
  // Set some values
  // geometry.points_count = 3;
  // geometry.add_points(1.0);
  // geometry.add_points(2.0);
  // geometry.add_points(3.0);
  // auto points = geometry.points();
  // for (int i = 0; i < std::size(points); i++) {
  //   std::cout << "i = " << i << std::endl;
  //   if (points[i]) {
  //     std::cout << "geometry.points()[i] = " << points[i] << std::endl;
  //   }
  // }

  return 0;
}