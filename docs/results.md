## Overview
We were able to create a graph based on edges represented by the distance using longitude and latitude between two rides in the Disney theme park. We were able to successfully implement all of the deliverables we proposed such as BFS iterator,  Dijkstra's algorithm, and Kruskal's algorithm.

## Data Parsing
For data parsing, we inputted from a javascript json file from Github and converted it into a .csv file with each column representing a ride and all of it's charateristics. Because the data files were smaller, for testing, we decided to also include parameters for specifying the wait times for the rides as a factor. We wrote tests for majority of the functions in the files we have comparing the elements of the rides using a specificed input limit of our own test data set.

## Directed Graph Class
The graph class can be created by passing in a list of post structs, and methods like Dijikstra's shortest path algorithm and Kruskal's for a specific node that are implemented within this class. We tested the graph class constructor by checking for the existence of certain nodes that would be created given a list of rides in our dataset.

## Edge Class
An edge object is essentially a post struct recieved after parsing the data but translated to become a graph edge. The Edge class has public accessor methods to retrieve the following items, longituted, latitude, weight times. Also, a formula is made in calculate distnace that takes the coordinated from the first and second ride you are traveling between and converts it to miles.

## BFS iterator
For traversing the graph without weighting the edges, we used a Breadth First Search iterator. The Breadth First Search iterator takes in the starting subreddit as an input and will reach the end once all the nodes have been visited. The iterator also has a function to measure how far the current node is from the starting node. The runtime of Breadth First Search using an adjacency list with n nodes and e edges is O(n + e).

## Dijikstra's Shortest Path
We used Dijikstra’s Shortest Path algorithm to identify the shortest weighted path between two rides. Our ShortestPath method takes in three parameters: the start ride, the destination ride, and the weighting scheme that one wishes to use. Dijikstra’s algorithm only works without modification on positive/unsigned weights, so we only included those schemes that are strictly non-negative. Given a starting ride, Dijkstra’s will return the shortest path for each ride from that ride. This means that if we start at Ride 1, and want to go to Ride 3, there might be multiple paths. You could go from Ride 1 to Ride 5 to Ride 3, or Ride 1 to Ride 4 to Ride 3, and one of these will be the shortest. This can help the rider understand how to get to a certain ride the quickest way, if they only care about that specific ride.

The options for weighting scheme are as follows:

Runtime Complexity: O(E*log(V)), where E is the number of edges and V are the number of nodes 

## Kruskal's 
Kruskal’s also generates the shortest path given a specific starting node, however it attempts to provide the rider with the greatest number of rides while maintaining the shortest path. The use case for this is to generate a path that not only takes the least amount of time/distance, but also allows the rider to visit most of Disneyworld.

** Add more as is implemented

## Discoveries
We discovered that the implementations of Djikstra's and Kruskal's algoithm and how it can be applicable to real life, and
how it is so useful in terms of coming up with solutions such as how long it can take to get to a certain ride. We also learned how to work with a new and unexplored dataset and work with how the overall data can fit into a graph implementation. Often times, it is hard to piece together what CS applications can do in your daily life (or on vacation at Disneyworld) and writing this code base helped us discover this.