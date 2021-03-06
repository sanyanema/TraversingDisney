#include "../cs225/catch/catch.hpp" 
#include "../src/graph.h"
#include "../src/edge.h"
#include "../src/node.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//using namespace csv;
using namespace std;

TEST_CASE("Sanity Check") {
  REQUIRE(true);
}

// ========================================================================
// Test: addNode, addEdges, getNode, getEdges, readCSV
// ========================================================================

TEST_CASE("Check to see if the correct number of edges and nodes are added.") {
  int rows = 0;
  ifstream file("tests/test_disney_data.csv");
  string line;
  Graph * graph = Graph::readCSV("tests/test_disney_data.csv");
  int numNodes = graph->getNodes().size();
  int numEdges = graph->getEdges().size();
  while( getline(file, line) )
    rows++;
  int expectedNumNodes = rows - 1;
  int expectedNumEdges = expectedNumNodes * (expectedNumNodes - 1) / 2 + expectedNumNodes;
  REQUIRE( numNodes == expectedNumNodes );
  REQUIRE( numEdges == expectedNumEdges );
}

// ========================================================================
// Test: delete/destructor
// ========================================================================

TEST_CASE("Check to see if graph gets deleted.") {
  Graph* graph = Graph::readCSV("tests/test_disney_data.csv"); // need to add delete graph
  //graph->Graph::~Graph();
  int numNodes = graph->getNodes().size();
  int numEdges = graph->getEdges().size();
  //REQUIRE( numNodes == 0 );
  //REQUIRE( numEdges == 0 );
  delete graph;
}
/*
// ========================================================================
// Test: _copy, copy constructor
// ========================================================================

TEST_CASE("Check to see if graph gets copied correctly") {
  Graph* graph = Graph::readCSV("tests/test_disney_data.csv");
  Graph* copiedGraph = new Graph(graph);
  
  std::unordered_map<string, Node*> nodes = graph->getNodes();
  std::unordered_map<string, Node*> copiedNodes = copiedGraph->getNodes();
  std::vector<Edge*>& edges = graph->getEdges();
  std::vector<Edge*>& copiedEdges = copiedGraph->getEdges();
  
  //check that the number of nodes and edges are the same
  int numNodes = nodes.size();
  int numEdges = copiedNodes.size();
  int numNodes2 = edges.size();
  int numEdges2 = copiedEdges.size();
  REQUIRE( numNodes == numNodes2 );
  REQUIRE( numEdges == numEdges2 );

  //check that nodes are equal to each other
  for(int i = 0; i < numNodes; i++){
    REQUIRE( nodes[i].second == copiedNodes[i].second );
  }

  //check that edges are qual to each other
  for(int i = 0; i < numEdges; i++){
    REQUIRE( edges[i] == copiedEdges[i] );
  }

}
*/

// ========================================================================
// Test: addNode
// ========================================================================

TEST_CASE("Check to see if graph addNode works correctly.") {
  int rows = 0;
  ifstream file("tests/test_disney_data.csv");
  string line;
  Graph * graph = Graph::readCSV("tests/test_disney_data.csv");
  
  while( getline(file, line) )
    rows++;

  graph->addNode(1, 81.5, 80.5, "Ride");
  int numNodes = graph->getNodes().size();

  std::vector<Node*> nodes;
  for (pair<string, Node*> n1 : graph->getNodes()) {
        // add each to a vector
      nodes.push_back(n1.second);
        // after loop do above loop and then i can do indexing 
  }

  REQUIRE( numNodes == rows );
  REQUIRE( nodes[0]->getWaitTime() == 1 );
  REQUIRE( nodes[0]->getLatitude() == 81.5 );
  REQUIRE( nodes[0]->getLongitude() == 80.5 );
  REQUIRE( nodes[0]->getName() == "Ride" );
}

// ========================================================================
// Test: addEdge
// ========================================================================

TEST_CASE("Check to see if graph gets updated after adding nodes and edges without weight.") {
  int rows = 0;
  ifstream file("tests/test_disney_data.csv");
  string line;
  Graph * graph = Graph::readCSV("tests/test_disney_data.csv");
  
  while( getline(file, line) )
    rows++;

  graph->addNode(1, 81.5, 80.5, "Ride");
  graph->addNode(1, 34.5, 30.5, "Ride 2");

  std::vector<Node*> nodes;
  for (pair<string, Node*> n1 : graph->getNodes()) {
        // add each to a vector
      nodes.push_back(n1.second);
        // after loop do above loop and then i can do indexing 
  }
  
  graph->addEdge(nodes[0], nodes[1]);
  std::vector<Edge*> edges = graph->getEdges();
  int numEdges = graph->getEdges().size();
  int expectedNumNodes = rows - 1;
  int expectedNumEdges = expectedNumNodes * (expectedNumNodes - 1) / 2 + expectedNumNodes + 1;

  REQUIRE( numEdges == expectedNumEdges );

  //tests adjacent edges of second node
  std::vector<Edge*> adjEdges = nodes[0]->getAdjacentEdges();
  REQUIRE( adjEdges[0]->getFirstNode()->getWaitTime() == edges[numEdges-1]->getFirstNode()->getWaitTime() );
  REQUIRE( adjEdges[0]->getFirstNode()->getLatitude() == edges[numEdges-1]->getFirstNode()->getLatitude() );
  REQUIRE( adjEdges[0]->getFirstNode()->getLongitude() == edges[numEdges-1]->getFirstNode()->getLongitude() );
  REQUIRE( adjEdges[0]->getFirstNode()->getName() == edges[numEdges-1]->getFirstNode()->getName() );
  REQUIRE( adjEdges[0]->getSecondNode()->getWaitTime() == edges[numEdges-1]->getSecondNode()->getWaitTime() );
  REQUIRE( adjEdges[0]->getSecondNode()->getLatitude() == edges[numEdges-1]->getSecondNode()->getLatitude() );
  REQUIRE( adjEdges[0]->getSecondNode()->getLongitude() == edges[numEdges-1]->getSecondNode()->getLongitude() );
  REQUIRE( adjEdges[0]->getSecondNode()->getName() == edges[numEdges-1]->getSecondNode()->getName() );
  REQUIRE( adjEdges[0]->getEdgeWeight() == edges[numEdges-1]->calculateDistance() );

  //tests adjacent edge of first node
  std::vector<Node*> adjNodes = nodes[1]->getAdjacentNodes();
  REQUIRE( adjNodes[0]->getWaitTime() == 1 );
  REQUIRE( adjNodes[0]->getLatitude() == 34.5 );
  REQUIRE( adjNodes[0]->getLongitude() == 30.5 );
  REQUIRE( adjNodes[0]->getName() == "Ride 2" );
}

// ========================================================================
// Test: addEdge with weight
// ========================================================================

TEST_CASE("Check to see if graph gets updated after adding nodes and edges with weight.") {
  int rows = 0;
  ifstream file("tests/test_disney_data.csv");
  string line;
  Graph * graph = Graph::readCSV("tests/test_disney_data.csv");
  
  while( getline(file, line) )
    rows++;

  graph->addNode(1, 81.5, 80.5, "Ride");
  graph->addNode(1, 34.5, 30.5, "Ride 2");

  std::vector<Node*> nodes;
  for (pair<string, Node*> n1 : graph->getNodes()) {
      nodes.push_back(n1.second);
  }
  
  graph->addEdge(nodes[0], nodes[1], 5);
  int numEdges = graph->getEdges().size();
  int expectedNumNodes = rows - 1;
  int expectedNumEdges = expectedNumNodes * (expectedNumNodes - 1) / 2 + expectedNumNodes + 1;

  REQUIRE( numEdges == expectedNumEdges );

  //tests adjacent edges of first node
  std::vector<Edge*> adjEdges = nodes[1]->getAdjacentEdges();
  REQUIRE( adjEdges[0]->getFirstNode()->getWaitTime() == nodes[0]->getWaitTime() );
  REQUIRE( adjEdges[0]->getFirstNode()->getLatitude() == nodes[0]->getLatitude() );
  REQUIRE( adjEdges[0]->getFirstNode()->getLongitude() == nodes[0]->getLongitude() );
  REQUIRE( adjEdges[0]->getFirstNode()->getName() == nodes[0]->getName() );
  REQUIRE( adjEdges[0]->getSecondNode()->getWaitTime() == nodes[1]->getWaitTime() );
  REQUIRE( adjEdges[0]->getSecondNode()->getLatitude() == nodes[1]->getLatitude() );
  REQUIRE( adjEdges[0]->getSecondNode()->getLongitude() == nodes[1]->getLongitude() );
  REQUIRE( adjEdges[0]->getSecondNode()->getName() == nodes[1]->getName() );
  REQUIRE( adjEdges[0]->getEdgeWeight() == 5 );

  //tests adjacent edge of second node
  std::vector<Node*> adjNodes = nodes[0]->getAdjacentNodes();
  REQUIRE( adjNodes[0]->getWaitTime() == 1 );
  REQUIRE( adjNodes[0]->getLatitude() == 81.5 );
  REQUIRE( adjNodes[0]->getLongitude() == 80.5 );
  REQUIRE( adjNodes[0]->getName() == "Ride" );
}

// ========================================================================
// Test: isAdjacent
// ========================================================================

TEST_CASE("Check to see if isAdjacent works correctly.") {
  Graph * graph = Graph::readCSV("tests/test_disney_data.csv");
  graph->addNode(1, 34.5, 30.5, "Ride 2");

  std::vector<Node*> nodes;
  for (pair<string, Node*> n1 : graph->getNodes()) {
      nodes.push_back(n1.second);
  }

  REQUIRE( graph->isAdjacent(nodes[1], nodes[2]) );
  REQUIRE( !(graph->isAdjacent(nodes[0], nodes[1]) ) );
}

// ========================================================================
// Test: Checking Latitude-Longitude Distance Function Tests
// ========================================================================
TEST_CASE("Check to see if distance function produces the correct value - Both Positive") {
  Node* first = new Node(1, 81.5, 80.5, "Ride");
  Node* second = new Node(1, 34.5, 30.5, "Ride 2");
  Edge* edge = new Edge(first, second);
  
  double distance = edge->calculateDistance();

  REQUIRE ( Approx(distance).epsilon(0.01) == 5595.4460665278 ); // kilometers
}

// ========================================================================
// Test: Checking distance function with negative and positive values
// ========================================================================
TEST_CASE("Check to see if distance function produces the correct value - One Pos, One Neg") {
  Node* first = new Node(1, 81.5, -80.5, "Ride");
  Node* second = new Node(1, -34.5, 30.5, "Ride 2");
  Edge* edge = new Edge(first, second);
  
  double distance = edge->calculateDistance();

  REQUIRE (Approx(distance).epsilon(0.01) == 14137.9159003922);
}

// ========================================================================
// Test: Checking distance function with csv data points
// ========================================================================
TEST_CASE("Check to see if distance function produces the correct value - Using actual data") {
  Node* first = new Node(1, -81.5783907473, 28.4207661576, "The Barnstormer");
  Node* second = new Node(1, -81.581255, 28.420169, "Prince Charming Regal Carousel");
  Edge* edge = new Edge(first, second);
  
  double distance = edge->calculateDistance();

  REQUIRE ( Approx(distance).epsilon(0.01) == 0.3186387535 );
}

// ========================================================================
// Test: Checking incident of edges going a ride again
// ========================================================================
TEST_CASE("Check to see if the incident function allows for same ride") {
  //Graph* graph = Graph::readCSV("tests/test_disney_data.csv");
  Node* first = new Node(1, -81.5783907473, 28.4207661576, "The Barnstormer");
  Node* second = new Node(1,  -81.5783907473, 28.4207661576, "The Barnstormer");
  Edge* edge = new Edge(first, second);

  REQUIRE (first->getName() == second->getName());
}


// BFS Tests


// ========================================================================
// Test: Checking BFS Constructor for proper implementation
// ========================================================================
TEST_CASE("BFS Traversal ") {
  for (int i = 0; i < edgeExploredList.size(); i++) {

  }
}

// ========================================================================
// Test: BFS with name of rides
// ========================================================================
TEST_CASE("Checking BFS Iterator") {
  // std::cout << "Reading through graph" << std::endl;
  Graph g = test.getGraph()
  int numNodes = graph->getNodes().size();
  int numEdges = graph->getEdges().size();


}


TEST_CASE("BFS maintains the correct point on top", "[weight=0][part=1][part=1b]") {

//PNG png(40, 40);
//   Point startPoint(20, 20);
//   BFS bfs(png, startPoint, 0.2);

//   bfs.add( Point(2, 2) );
//   bfs.add( Point(2, 3) );
//   bfs.add( Point(2, 4) );

//   REQUIRE( bfs.peek() == Point(20, 20) );
}

TEST_CASE("BFS maintains the BFS ordering", "[weight=0][part=1][part=1b]") {
  //PNG png(40, 40);
//   Point startPoint(20, 20);
//   BFS bfs(png, startPoint, 0.2);

//   bfs.add( Point(2, 2) );
//   bfs.add( Point(2, 3) );
//   bfs.add( Point(2, 4) );

//   REQUIRE( bfs.pop() == Point(20, 20) );
//   REQUIRE( bfs.pop() == Point(2, 2) );
//   REQUIRE( bfs.pop() == Point(2, 3) );
//   REQUIRE( bfs.pop() == Point(2, 4) );
}

TEST_CASE("BFS is able to add edges") {

}

TEST_CASE("BFS path works") {

}

// Dijikstra's Tests

TEST_CASE("Check that the distance to the node passed in is 0") {
  // make the graph and load it in, based on which node you pass in, get that node and see that the dist is 0 there
}

TEST_CASE("Check to see if all the edge weights are non-negative") {

}

TEST_CASE("Check if the shortest path gets updated") {

}

TEST_CASE("Check to see if the correct path is generated") {

}

// Kruskal's Tests

TEST_CASE("Check to see if the list is non-decreasing in terms of their weight") {

}

TEST_CASE("Check to see if it makes sure to not form a cycle") {

}

TEST_CASE("Check to see if the resulting spanning tree has (V-1) edges") {
    // V means Vertices
}