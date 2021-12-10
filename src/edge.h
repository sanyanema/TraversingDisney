// getters first node and second node
// setters first node and second node
// setter for weight (distance from a to b), initially set it to -1
// distance function here

#include "node.h"

class Edge {
    public:
        Edge(); // set edgeWeight = -1 here initially
        Edge(Node first, Node second);
        double calculateDistance(); // call this in the constructor and set it equal to edgeWeight
        double getEdgeWeight();
    private:
        double edgeWeight;
        void convertToRadians(double value);
};