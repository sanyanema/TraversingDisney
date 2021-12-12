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
  int minNumEdges = expectedNumNodes - 1;
  int maxNumEdges = expectedNumNodes * (expectedNumNodes - 1);
  REQUIRE( numNodes == expectedNumNodes );
  REQUIRE( numEdges >= minNumEdges );
  REQUIRE( numEdges <= maxNumEdges );
}

// ========================================================================
// Test: delete/destructor
// ========================================================================

TEST_CASE("Check to see if graph gets deleted.") {
  Graph* graph = Graph::readCSV("tests/test_disney_data.csv"); // need to add delete graph
  //graph->Graph::~Graph();
  int numNodes = graph->getNodes().size();
  int numEdges = graph->getEdges().size();
  REQUIRE( numNodes == 0 );
  REQUIRE( numEdges == 0 );
  delete graph;
}

// ========================================================================
// Test: Latitude-Longitude Distance Function Tests
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

  REQUIRE ( Approx(distance).epsilon(0.01) == 14137.9159003922 );
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


// BFS Tests

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

TEST_CASE("Produces the correct BFS for the entire dataset") {

}

TEST_CASE("BFS Constructor Works") {

}

TEST_CASE("BFS is able to add edges") {

}

TEST_CASE("BFS path works") {

}

// Dijikstra's Tests

TEST_CASE("Check to see if edgeWeight works") {

}

TEST_CASE("Check [helper function]") {

}

// Kruskal's Tests

TEST_CASE("Check to see if the list is non-decreasing in terms of their weight") {

}

TEST_CASE("Check to see if it makes sure to not form a cycle") {

}

TEST_CASE("Check to see if the resulting spanning tree has (V-1) edges") {
    // V means Vertices
}