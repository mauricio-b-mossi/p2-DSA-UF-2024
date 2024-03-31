#include "AdjacencyList.hpp"
#include <vector>

// Saving in reverse to facilitate rank calculation.
void AdjacencyList::insertEdge(int from, int to) {
  mp[from].push_back(to);
  if (mp.find(to) == mp.end()) {
    mp[to] = {};
  }
}

std::vector<int> AdjacencyList::getAdjacentVertices(int source) {
  return mp[source];
}

AdjacencyList::AdjacencyList(){};
AdjacencyList::~AdjacencyList(){};
