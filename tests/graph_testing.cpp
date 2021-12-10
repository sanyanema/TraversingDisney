// test to see if our latitude and longitude function works, and check
// for edge cases

// test the BFS

#include "../catch/catch.hpp" 

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace cs225;

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
