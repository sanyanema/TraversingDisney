#pragma once

class Node;

// getters first node and second node
// setters first node and second node
// setter for weight (distance from a to b), initially set it to -1
// distance function here
#include <string>
#include "node.h"

class Edge {
    public:
        Edge(); // set edgeWeight = -1 here initially
        Edge(Node* first, Node* second, double edge_weight);
        Edge(Node* first, Node* second); // this one sets edgeWeight using the formula
        double calculateDistance(Node* first, Node* second) const; // call this in the constructor and set it equal to edgeWeight
        double getEdgeWeight() const;
        Node* getIncident(Node* first) const; // gets you the edge that comes out of this node
        Node* getFirstNode() const;
        Node* getSecondNode() const;
    private:
        double edge_weight_;
        double convertToRadians(double value) const;
        Node* first_;
        Node* second_;
};