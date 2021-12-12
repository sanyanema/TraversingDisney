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

// ========================================================================
// Test: addNode, addEdges, getNode, getEdges, readCSV
// ========================================================================

TEST_CASE("Check to see if the correct number of edges and nodes are added.") {
  int rows = 0;
  ifstream file("data/disney_data.csv");
  string line;
  Graph graph = readCSV(disney_data.csv);
  int numNodes = graph.getNode().size();
  int numEdges = graph.getEdges().size();
  int expectedNumNodes = rows - 1;
  int expectedNumEdges = numNodes;
  while( getline(file, line) )
    rows++;
  REQUIRE( numNodes == expectedNumNodes );
  REQUIRE( numEdges == expectedNumEdges );
}

// ========================================================================
// Test: delete/destructor
// ========================================================================

TEST_CASE("Check to see if graph gets deleted.") {
  Graph* graph = Graph::readCSV("data/disney_data.csv");
  //graph->_delete();
  int numNodes = graph->getNodes().size();
  int numEdges = graph->getEdges().size();
  REQUIRE( numNodes == 0 );
  REQUIRE( numEdges == 0 );
}


// Latitude-Longitude Distance Function Tests
TEST_CASE("Check to see if distance function produces the correct value - Both Positive") {
  
}

TEST_CASE("Check to see if distance function produces the correct value - One Pos, One Neg") {

}

TEST_CASE("Check to see if distance function produces the correct value - Both Neg") {

}

TEST_CASE("Check to see if it recognizes out of bounds values") {

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