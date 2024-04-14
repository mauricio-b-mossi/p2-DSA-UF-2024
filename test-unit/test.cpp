//#include <iostream>
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//#include <sstream>
//
//#include "../src/PageRank.hpp"
//
//using namespace std;
//
//// See the following for an example of how to easily test your output.
//// This uses C++ "raw strings" and assumes your PageRank outputs a string with
////   the same thing you print.
//TEST_CASE("Example PageRank Output Test", "[example]") {
//  // the following is a "raw string" - you can write the exact input (without
//  //   any indentation!) and it should work as expected
//  string input = R"(7 2
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//  string expectedOutput = R"(facebook.com 0.20
//gmail.com 0.20
//google.com 0.10
//maps.com 0.30
//ufl.edu 0.20
//)";
//
//  std::stringstream ss(input);
//
//  PageRank pr;
//
//  int no_of_lines, power_iterations;
//  string from, to;
//  ss >> no_of_lines;
//  ss >> power_iterations;
//  for (int i = 0; i < no_of_lines; i++) {
//    ss >> from;
//    ss >> to;
//    pr.insertEdge(from, to);
//  }
//
//  pr.setDefaultRank();
//
//  pr.powerIterate(power_iterations);
//
//  REQUIRE(pr.getRankString() == expectedOutput);
//}
//
//TEST_CASE("Correct initialization of rank", "[trivial]") {
//  string input = R"(7 1
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//  string expectedOutput = R"(facebook.com 0.20
//gmail.com 0.20
//google.com 0.20
//maps.com 0.20
//ufl.edu 0.20
//)";
//
//  std::stringstream ss(input);
//
//  PageRank pr;
//
//  int no_of_lines, power_iterations;
//  string from, to;
//  ss >> no_of_lines;
//  ss >> power_iterations;
//  for (int i = 0; i < no_of_lines; i++) {
//    ss >> from;
//    ss >> to;
//    pr.insertEdge(from, to);
//  }
//
//  pr.setDefaultRank();
//
//  pr.powerIterate(power_iterations);
//
//  REQUIRE(pr.getRankString() == expectedOutput);
//}
//
///* Diagonal matrix if E performed,
// * for this case the Diagonal is 0
// * since self linkage is not possible*.
// * [0 0 1]     1*rank
// * [1 0 0] ->  1*rank
// * [0 1 0]     1*rank
// */
//TEST_CASE("Diagonal Matrix Multiplication 1.", "[trivial]") {
//
//  string input = R"(7 1000
//google.com gmail.com
//gmail.com maps.com
//maps.com google.com)";
//
//  string expectedOutput = R"(gmail.com 0.33
//google.com 0.33
//maps.com 0.33
//)";
//
//  std::stringstream ss(input);
//
//  PageRank pr;
//
//  int no_of_lines, power_iterations;
//  string from, to;
//  ss >> no_of_lines;
//  ss >> power_iterations;
//  for (int i = 0; i < no_of_lines; i++) {
//    ss >> from;
//    ss >> to;
//    pr.insertEdge(from, to);
//  }
//
//  pr.setDefaultRank();
//
//  pr.powerIterate(power_iterations);
//
//  REQUIRE(pr.getRankString() == expectedOutput);
//}
//
///* Diagonal matrix if E performed
// * [0 0.5 0.5]     (0.5 + 0.5)*rank
// * [0.5 0 0.5] ->  (0.5 + 0.5)*rank -> rank.
// * [0.5 0.5 0]     (0.5 + 0.5)*rank
// */
//TEST_CASE("Diagonal Matrix Multiplication 2.", "[trivial]") {
//
//  string input = R"(6 10000
//google.com gmail.com
//google.com maps.com
//gmail.com maps.com
//gmail.com google.com
//maps.com google.com
//maps.com gmail.com)";
//
//  string expectedOutput = R"(gmail.com 0.33
//google.com 0.33
//maps.com 0.33
//)";
//
//  std::stringstream ss(input);
//
//  PageRank pr;
//
//  int no_of_lines, power_iterations;
//  string from, to;
//  ss >> no_of_lines;
//  ss >> power_iterations;
//  for (int i = 0; i < no_of_lines; i++) {
//    ss >> from;
//    ss >> to;
//    pr.insertEdge(from, to);
//  }
//
//  pr.setDefaultRank();
//
//  pr.powerIterate(power_iterations);
//
//  REQUIRE(pr.getRankString() == expectedOutput);
//}
//
//TEST_CASE("Converging Page Rank", "[non-trivial]") {
//
//  string input = R"(7 10000
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//  string expectedOutput = R"(facebook.com 0.24
//gmail.com 0.18
//google.com 0.12
//maps.com 0.24
//ufl.edu 0.24
//)";
//
//  std::stringstream ss(input);
//
//  PageRank pr;
//
//  int no_of_lines, power_iterations;
//  string from, to;
//  ss >> no_of_lines;
//  ss >> power_iterations;
//  for (int i = 0; i < no_of_lines; i++) {
//    ss >> from;
//    ss >> to;
//    pr.insertEdge(from, to);
//  }
//
//  pr.setDefaultRank();
//
//  pr.powerIterate(power_iterations);
//
//  REQUIRE(pr.getRankString() == expectedOutput);
//}
//
//TEST_CASE("Self Reference 1 Entity", "[trivial]") {
//
//  string input = R"(3 10000
//google.com google.com
//google.com google.com
//gmail.com google.com)";
//
//  string expectedOutput = R"(gmail.com 0.00
//google.com 1.00
//)";
//
//  std::stringstream ss(input);
//
//  PageRank pr;
//
//  int no_of_lines, power_iterations;
//  string from, to;
//  ss >> no_of_lines;
//  ss >> power_iterations;
//  for (int i = 0; i < no_of_lines; i++) {
//    ss >> from;
//    ss >> to;
//    pr.insertEdge(from, to);
//  }
//
//  pr.setDefaultRank();
//
//  pr.powerIterate(power_iterations);
//
//  REQUIRE(pr.getRankString() == expectedOutput);
//}
