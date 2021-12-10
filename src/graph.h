// bool isAdjacent - checks if two nodes are adjacent const

// vector adjacentVertices - gives a vector of all the adjacent nodes of a given node const

// map holds key as node and value as vector of adjacent edges (iterate through the edges to find which nodes are adjacent)

class Graph {
    public:
        Graph();
        void insertNode(std::string ride);
        void removeNode(std::string ride);
        void insertEdge(std::string ride1. std::string ride2);
        void removeEdge(std::string ride1, std::string ride2);

        bool isAdjacent(std::string ride1, std::string ride2) const;
        std::vector<std::string> getAdjacentVertices(std::string ride) const;

        std::vector<std::string> getVertices() const;
        size_t getNumEdges() const;
        size_t getNumNodes() const;
    private:
};