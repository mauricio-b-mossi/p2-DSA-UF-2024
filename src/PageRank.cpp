#include "PageRank.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

/* Here we:
    - insert edge to AdjacencyList.
    - map website to ints.
    - count how many outward nodes per vertex.

Notes: The only time you need to be aware of the string representation of the
website is when converting to an integer and when converting an integer to a
string, for everything else the value of the string matches with the index of
the vectors.
 */
void PageRank::insertEdge(std::string from, std::string to) {

  auto query = webToVertexMapper.find(from);
  if (query == webToVertexMapper.end()) {
    webToVertexMapper[from] = vertices++;
    outLinksPerWeb.push_back(1);
  } else
    outLinksPerWeb[query->second]++;

  if (webToVertexMapper.find(to) == webToVertexMapper.end()) {
    webToVertexMapper[to] = vertices++;
    outLinksPerWeb.push_back(0);
  }

  // Reverting order as I want getAdjacentVertices to return inwards adjacent
  // vertices.
  adjList.insertEdge(webToVertexMapper[to], webToVertexMapper[from]);
}

void PageRank::setDefaultRank() {
  for (int i = 0; i < vertices; i++)
    rank.push_back(1.f / vertices);
}

void PageRank::powerIterate(int n) {
  for (int l = 1; l < n; l++) {

    float rankCopy[vertices]; // Took me a while to catch this.
    for (int i = 0; i < vertices; i++)
      rankCopy[i] = rank[i];

    for (int i = 0; i < vertices; i++) {
      float temp = 0;
      for (auto inwardsVertex : adjList.getAdjacentVertices(i)) {
        temp += rankCopy[inwardsVertex] *
                (1.f / outLinksPerWeb[inwardsVertex]); // Had an i, big mistake.
      }
      rank[i] = temp;
    }
  }
}

void PageRank::printRank() {
  // Map returns in order.
  for (auto el : webToVertexMapper) {
    std::cout << el.first << " " << std::fixed << std::setprecision(2)
              << rank[el.second] << std::endl;
  }
}

// Print in order
void PageRank::printOutlinks() {
  // Map returns in order.
  for (auto el : webToVertexMapper) {
    std::cout << el.first << " " << std::fixed << std::setprecision(2)
              << outLinksPerWeb[el.second] << std::endl;
  }
}

PageRank::PageRank(){};
PageRank::~PageRank(){};
