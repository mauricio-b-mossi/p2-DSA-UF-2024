#pragma once
#include <unordered_map>
#include <vector>

/* Only need the insert and retriveAdjacent functionality
 * to perform page rank. This is because will insert edges,
 * and retrieve inwardAdjacent vertices to perform power iterations.
 */
struct AdjacencyList {

  AdjacencyList();
  ~AdjacencyList();

  void insertEdge(int from, int to);
  std::vector<int> getAdjacentVertices(int source);

private:
  std::unordered_map<int, std::vector<int>> mp{};
};
