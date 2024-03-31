#include <iostream>

#include "PageRank.hpp"

using namespace std;

int main() {

  PageRank pr;

  int no_of_lines, power_iterations;
  string from, to;
  cin >> no_of_lines;
  cin >> power_iterations;
  for (int i = 0; i < no_of_lines; i++) {
    cin >> from;
    cin >> to;
    pr.insertEdge(from, to);
  }

  pr.setDefaultRank();

  pr.powerIterate(power_iterations);
  pr.printRank();
}
