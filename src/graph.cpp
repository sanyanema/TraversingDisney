#include "graph.h"

using std::string;
using std::pair;

//number of rides
int count_g = 39;

//Graph Constructors
Graph::Graph() {
  /*  
    //new variable ??? was mat_t 
    vector<vector<double>> vec(???, vector<double> (???, NO_EDGE));
    vector<Vertex> vec_rides(???, Vertex());
    adjRides = vec;
    rides = vec_rides; //vec_air
    */
}
Graph::~Graph() {
     _delete();
}
//initializing graph sizes 
/*
Graph::Graph(int edgeSize){
    vector<vector<double>> vec(edgeSize, vector<double> (edgeSize, NO_EDGE));
    vector<Vertex> vec_rides(edgeSize, Vertex());   
    adjRides = vec;
    rides = vec_rides;
}
*/
Graph::Graph(const Graph& other) {
    _copy(other);
}

//see what is rhs 
const Graph& Graph::operator=(const Graph& rhs) {
    if (this != &rhs) {
        _delete();
        _copy(rhs);
    }
    return *this;
}

void Graph::_delete() {
    for (pair<string, Node*> v : vertices_) { 
        delete v.second;
    }
    for (Edge* e : edges_) {
        delete e;
    }
}

void Graph::_copy(const Graph& other) {
    for (pair<string, Node*> v : other.getNodes()) {
        Node* n = v.second;
        addNode(n->getWaitTime(), n->getLatitude(), n->getLongitude(), n->getName());
    }
    for (Edge* e : other.getEdges()) {
        addEdge(
            e->getFirstNode(), e->getSecondNode(), e->getEdgeWeight()
        );
    }
}

void Graph::addEdge(Node* first, Node* second, double edge_weight) {
    Edge* e = new Edge(first, second, edge_weight);
    edges_.push_back(e);

    first->addAdjacentEdge(e);
    second->addAdjacentEdge(e);

    first->addAdjacentNode(second);
    second->addAdjacentNode(first);
}

void Graph::addEdge(Node* first, Node* second) {
    Edge* e = new Edge(first, second);
    edges_.push_back(e);

    first->addAdjacentEdge(e);
    second->addAdjacentEdge(e);

    first->addAdjacentNode(second);
    second->addAdjacentNode(first);
}

const std::vector<Edge*>& Graph::getEdges() const {
    return edges_;
}

void Graph::addNode(double wait_time, double latitude, double longitude, std::string name) {
    Node* n = new Node(wait_time, latitude, longitude, name);
    vertices_.insert(std::make_pair(n->getRideName(), n));
}

Node* Graph::getNode(const std::string& name) const {
    auto it = vertices_.find(name);
    return it == vertices_.end() ? NULL : it->second;
}

//Don't know if needed but a getNode but if do implement here

bool Graph::isAdjacent(Node* first, Node* second) const {
    //location at both
    //true and false statements

    //checks bounds on input rides
    //still have to implement 

    // std::vector<Edge*> first_edges = first.getAdjacentEdges();
    // std::vector<Edge*> second_edges = second.geAdjacentEdges();

    std::vector<Node*> first_nodes = first->getAdjacentNodes();
    std::vector<Node*> second_nodes = second->getAdjacentNodes();

    // if you go through the list of adjacent nodes for the first node, and see that the second
    // node is in this list, that means that the two are adjacent to each other

    for (unsigned i = 0; i < first_nodes.size(); ++i) {
        if (first_nodes[i] == second) {
            return true;
        }
    }
    return false;
}
//call method in .h to get the distance between two points


const std::unordered_map<string, Node*> & Graph::getNodes() const {
    return vertices_;
}

Graph* Graph::readCSV(std::string filename) {
    Graph* graph = new Graph();

    std::ifstream infile(filename);
    std::string file_line;

    std::string ride_name, active_status, wait_time, status, longitude, latitude;

    if (infile.is_open()) {
        getline(infile, file_line);

        while (getline(infile, file_line)) {
            std::stringstream comma(file_line);

            getline(comma, ride_name, ',');
            getline(comma, active_status, ',');
            getline(comma, wait_time, ',');
            getline(comma, status, ',');
            getline(comma, longitude, ',');
            getline(comma, latitude, ',');

            //Node* n = new Node(s);
            graph->addNode(std::stod(wait_time), std::stod(latitude), std::stod(longitude), ride_name);
        }
    }

    // THERE'S A LINKER COMMAND ERROR HERE. 
    
    for (pair<string, Node*> n1 : graph->getNodes()) {
        for (pair<string, Node*> n2 : graph->getNodes()) {
            if (n1 != n2) {
                // add edge
                graph->addEdge(n1.second, n2.second); // calculate the distance

            } else {
                // self edge -- use wait time
                graph->addEdge(n1.second, n2.second, std::stod(wait_time));
            }
        }
    }

    return graph;
}

void Graph::printNodes() {
    for (auto node : vertices_) {
        std::cout << node.second->getName();
    }
}