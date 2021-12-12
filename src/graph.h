#pragma once

#include <unordered_map>
#include <iostream>

#include <fstream>
#include <sstream>


// bool isAdjacent - checks if two nodes are adjacent const

// vector adjacentVertices - gives a vector of all the adjacent nodes of a given node const

// map holds key as node and value as vector of adjacent edges (iterate through the edges to find which nodes are adjacent)
#include <string>
#include <vector>
#include "node.h"
#include "edge.h"

/**
* A base class for the graph 
*
* Each derived fucntion must maintain an ordering of rides longitude and laditude
*/
class Graph {
    public:
        /**
        * A forward iterator through a Graph
        */
        Graph();
        ~Graph();
        Graph(const Graph& other);

        /**
        * Equal operator is used to check the balance 
        *
        */
        const Graph& operator=(const Graph& other);


        /**
        * Will add and contruct a Node 
        * This will build it
        */
        void addNode(double wait_time, double latitude, double longitude, std::string name); 
        
        //void removeNode(std::string ride);

        /**
        * This will construct the edge and build it
        */
        void addEdge(Node* node1, Node* node2, double edge_weight);

        /**
        * This will constuct the edge
        */
        void addEdge(Node* node1, Node* node2);

        /**
        * checks if two nodes are adjacent to each other
        */
        bool isAdjacent(Node* ride1, Node* ride2) const; 

        //std::vector<std::string> getAdjacentVertices(std::string ride) const;
        const std::unordered_map<std::string, Node*> & getNodes() const;
        const std::vector<Edge*>& getEdges() const;
        // size_t getNumEdges() const;
        // size_t getNumNodes() const;

        static Graph* readCSV(std::string filename);

        void printNodes();

        Node* getNode(const std::string& name) const;
    private:
        std::unordered_map<std::string, Node*> vertices_;
        std::vector<Edge*> edges_;

        void _copy(const Graph& other);
        void _delete();
};