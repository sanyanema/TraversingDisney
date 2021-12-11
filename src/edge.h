#pragma once

class Node;

// getters first node and second node
// setters first node and second node
// setter for weight (distance from a to b), initially set it to -1
// distance function here

#include "node.h"

class Edge {
    public:
        Edge(); // set edgeWeight = -1 here initially
        Edge(Node* first, Node* second, double edge_weight);
        Edge(Node* first, Node* second); // this one sets edgeWeight using the formula
        double calculateDistance(Node* first_, Node* second_); // call this in the constructor and set it equal to edgeWeight
        double getEdgeWeight();
        Node* getIncident(Node* first); // gets you the edge that comes out of this node
        Node* getFirstNode();
        Node* getSecondNode();
    private:
        double edgeWeight;
        void convertToRadians(double value);
        Node* first;
        Node* second;
};