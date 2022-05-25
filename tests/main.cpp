#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "catch.hpp"
#include "jlib.hpp"

TEST_CASE("Validate add2") {
  INFO("Adding 2 and 3");
  REQUIRE(jlib::add2(2, 3) == 5);
}

TEST_CASE("Validate add3") {
  INFO("Adding 2, 4 and 3");
  REQUIRE(jlib::add3(2, 4, 3) == 9);
}