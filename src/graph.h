#pragma once

#include <unordered_map>

// bool isAdjacent - checks if two nodes are adjacent const

// vector adjacentVertices - gives a vector of all the adjacent nodes of a given node const

// map holds key as node and value as vector of adjacent edges (iterate through the edges to find which nodes are adjacent)
#include "node.h"
#include "edge.h"

class Graph {
    public:
        Graph();
        void insertNode(double wait_time, double );
        //void removeNode(std::string ride);
        void insertEdge(Node* node1, Node* node2, double edgeWeight);
        //void removeEdge(std::string ride1, std::string ride2);

        bool isAdjacent(Node* ride1, Node* ride2) const;
        //std::vector<std::string> getAdjacentVertices(std::string ride) const;

        const std::vector<Node*> & getVertices() const;
        // size_t getNumEdges() const;
        // size_t getNumNodes() const;

        static Graph* readCSV(std::string filename);
    private:
        std::unordered_map<std::string, Node*> vertices;
        std::vector<Edge*> edges;
};