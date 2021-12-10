// test to see if our latitude and longitude function works, and check
// for edge cases

// test the BFS

#include "../catch/catch.hpp" 

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace cs225;

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
  PNG png(40, 40);
  Point startPoint(20, 20);
  BFS bfs(png, startPoint, 0.2);

  bfs.add( Point(2, 2) );
  bfs.add( Point(2, 3) );
  bfs.add( Point(2, 4) );

  REQUIRE( bfs.peek() == Point(20, 20) );
}

TEST_CASE("BFS maintains the BFS ordering", "[weight=0][part=1][part=1b]") {
  PNG png(40, 40);
  Point startPoint(20, 20);
  BFS bfs(png, startPoint, 0.2);

  bfs.add( Point(2, 2) );
  bfs.add( Point(2, 3) );
  bfs.add( Point(2, 4) );

  REQUIRE( bfs.pop() == Point(20, 20) );
  REQUIRE( bfs.pop() == Point(2, 2) );
  REQUIRE( bfs.pop() == Point(2, 3) );
  REQUIRE( bfs.pop() == Point(2, 4) );
}

TEST_CASE("Produces the correct BFS for the entire dataset") {

}

// Dijikstra's Tests

// Kruskal's Tests

TEST_CASE("Check to see if the list is non-decreasing in terms of their weight") {

}

TEST_CASE("Check to see if it makes sure to not form a cycle") {

}

TEST_CASE("Check to see if the resulting spanning tree has (V-1) edges") {
    // V means Vertices
}