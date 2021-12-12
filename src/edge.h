#pragma once

class Node;

// getters first node and second node
// setters first node and second node
// setter for weight (distance from a to b), initially set it to -1
// distance function here
#include <string>
#include "node.h"

/**
* A base class for the Edge 
* Taking into account the different variables
*/
class Edge {
    public:
        /**
        * A forward iterator through a Edge
        * This has the setting of edgeWeight = -1 here initially 
        */
        Edge(); 
        /**
        * Constructor that intializes variables nodes and edge weight
        */
        Edge(Node* first, Node* second, double edge_weight);
        /**
        * This function sets the edgeWeight using the formula
        */
        Edge(Node* first, Node* second); 
        /**
        * Calls these variables in a constructor and set it equal to edgeWeight
        * Also checks 
        * The getIncident method gives you the edge case that comes out of a node which is ride
        * If riding the same ride again we add the edgeWeight 
        */
        double calculateDistance(Node* first, Node* second) const; 
        double getEdgeWeight() const;
        Node* getIncident(Node* first) const; 
        Node* getFirstNode() const;
        Node* getSecondNode() const;
    private:
        double edge_weight_;
        double convertToRadians(double value) const;
        Node* first_;
        Node* second_;
};