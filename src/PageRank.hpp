#pragma once
#include "AdjacencyList.hpp"
#include <map>
#include <string>
#include <vector>
#include <string>

/* Will perform insertion and mapping from website to integer here as
 * I will keep track of outgoing nodes to calculate the weigth. To perform
 * poweriterations I will perform a "dot product".
 */

/*
 * Class encapsulates the behavior of the PageRank algorithm by internally using an 
 * Adjacency List to store website graph.
 */
struct PageRank {

  PageRank();
  ~PageRank();

  // Will flip ordering to get inward adjacent vertex to facilite dot product.
  void insertEdge(std::string from, std::string to);

  void powerIterate(int n);

  void printRank();

  // Initialized the rank of each website to 1/V.
  void setDefaultRank();

  std::string getRankString();


private:
  std::map<std::string, int> webToVertexMapper{};
  std::vector<int> outLinksPerWeb{}; // Value of webToVertexMapper matches index
  std::vector<float> rank{}; // Rank also matches index of webToVertexMapper
  AdjacencyList adjList;
  int vertices = 0;
};
