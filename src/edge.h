// getters first node and second node
// setters first node and second node
// setter for weight (distance from a to b), initially set it to -1
// distance function here

#include "node.h"

class Edge {
    public:
        Edge();
        Edge(Node first, Node second);
        double calculateDistance();
        double getEdgeWeight();
    private:
        double edgeWeight;
};