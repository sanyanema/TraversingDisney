# CS225 Data Structures
## ag52-snema2-knagpu2-shreyap7
## Final Project Proposal

### Leading Questions
We are using the unofficial API library called wdwJS -- ​​https://github.com/zpocbob/wdwJS. The dataset provides information about various rides in Disney Theme Parks around the world, such as Disney California and Disney Paris. This information includes the individual ride wait times, the schedule for these rides, and which park the ride is located in. We are hoping to solve the specific problem of amusement park goers having to wait in long lines. By tracking wait times and the distance away a person is from a certain ride we can allow them to figure out what theme park they should go to at a certain time. We are hoping to produce a search tool, where the input is the current location at the park, and the output will be a list of suggested rides ranked using shortest wait time, distance from rides, and the ability to optimize the future ride order. To us, a successful project looks like a working search tool that can help users optimize their amusement park experience. Based on the user’s location in the park, we want to be able to provide them with their ideal and most optimized experience based on their location and wait time. 

### Dataset Acquisition and Processing
We will download our data by pulling from the github repository that it is stored in. Our data is stored in a github repository, and contains a Disney API. They have data for three parks available, and we will be using the DisneyWorld one. We will be installing an unofficial API library for accessing Disney park wait times, opening times and other information from the Disney API called wdwJS. We will be storing our data in a dictionary which will allow us to eventually process the keys and values of this dataset when we are using it to write our graph algorithms.
Our data is formatted into JSON files and we will be using BFS due to it using a queue data structure for finding the shortest path. BFS can be used to find a single source shortest path in an unweighted graph, because in BFS, we reach a vertex with minimum number of edges from a source vertex. We will handle these potential errors by searching and inputting data where we can, and factoring in special cases into our code. Also, we will do this by finding outliers in the data that are not realistic in the wait times and distance for the rides.
## Graph Algorithms

One of our graph algorithms will be **Dijkstra’s algorithm** to find the shortest path between a and b. It picks the unvisited vertex with the lowest distance, calculates the distance through it to each unvisited neighbor, and updates the neighbor’s distance if smaller. Mark visited (set to red) when done with neighbors. The runtime for this algorithm depends on the number of operations that are implemented. It can range from O(1) time to O(q) which is the number of vertices in the min-priority queue. We will be using this algorithm to find the shortest path in one of the five theme parks inside DisneyWorld to optimize a person’s trip during the day.

We will be using **BFS** to find the shortest path between where one is located and where that person would like to go, which is our graph traversal. For our two graph algorithms, the first one will be the pathways in each of the theme parks and the walk people take from one ride to another.

Our second graph algorithm is based on the timings that people wait for. Given a number that represents the amount of time an individual has at the theme park, we will generate a path for them to go to the maximum number of rides within their time constraint and generate a landmark path for them. We will use **Kruskal's algorithm** to do this. We will generate a minimum spanning tree that will help us understand which rides can be visited within the time constraint, utilizing the edge weight to accomplish this. We will use the distance between the two rides as the edge weights. For BFS, the inputs we are expecting are the pathways in each theme park, current location, and the wait times for the rides in the theme park.  For BFS, the outputs we are expecting are the distance between each ride and the current location which will be used to create an optimized path throughout the theme park. For the BFS algorithm the runtime or time complexity is O(V + E) when the adjacency list is used, and O(V^2) when the adjacency matrix is used, where V stands for vertices and E stands for edges. Considering that there are multiple ways to implement an algorithm, our target efficiency for our two graph algorithm is O(n).


## Timeline
# Data Acquisition: November 16th
Install library for accessing Disney park wait times, opening times and other information
# Data Processing: November 16th
Sort through data and store in dictionary
# Completion of Algorithm 1: November 27th
# Completion of Algorithm 2: Dec 1st
# Production of final deliverables: is due Dec 13
Development document (1 paragraph per week)
Final report (December 9th)
Edits due (December 5th before meeting)
Final presentation powerpoint  (December 5th)
Final presentation video (December 7th)
Make during weekly Tuesday meetings
