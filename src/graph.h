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

class Graph {
    public:
        Graph();
        void addNode(double wait_time, double latitude, double longitude, std::string name); // this will construct the node and build it
        //void removeNode(std::string ride);
        void addEdge(Node* node1, Node* node2, double edge_weight); // this will construct the egde and build it
        //void removeEdge(std::string ride1, std::string ride2);

        bool isAdjacent(Node* ride1, Node* ride2) const; // checks if two nodes are adjacent to each other
        //std::vector<std::string> getAdjacentVertices(std::string ride) const;

        const std::vector<Node*> & getNodes() const;
        // size_t getNumEdges() const;
        // size_t getNumNodes() const;

        static Graph* readCSV(std::string filename);
    private:
        std::unordered_map<std::string, Node*> vertices;
        std::vector<Edge*> edges;
};