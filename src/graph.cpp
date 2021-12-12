#include "graph.h"

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
/**
void Graph::_copy(const Graph& other) {
    for (pair<string, Node*> v : other.getVertices()) {
        addVertex(v.second->getAddress());
    }
    for (Edge* e : other.getEdges()) {
        addEdge(
            getVertex(e->getSource()->getAddress()),
            getVertex(e->getDestination()->getAddress()),
            e->getValue(), e->getGas(), e->getGasPrice()
        );
    }
}
*/

void Graph::addEdge(Node* first, Node* second, double edge_weight) {
    Edge* e = new Edge(first, second, edge_weight);
    edges_.push_back(e);

    soruce->addEdge(e);
    destination->addEdge(e);
}

void Graph::addNode(double wait_time, double latitude, double longitude, std::string name) {
    /*
    Node* n = new Node();
    nodes_.insert(make_pair(address, n));
    return n;
**/
    return addNode(wait_time, latitude, longitude, name);
}
void Graph::getNode() {
    /*
    auto it = node.find(address);
    return it == node_.end() ? NULL : it->second;
    **/
    return rides;
}

//Don't know if needed but a getNode but if do implement here

bool Graph::isAdjacent(Node* first, Node* second) const {
    //make the Nodes two unsigned longs
    unsigned long nFirst = (unsigned long) first;
    unsigned long nSecond = (unsigned long) second;

    //checks bounds on input rides
    //still have to implement 

    return false;
}
//call method in .h to get the distance between two points
double Graph::getEdgeWeight(Node* first, Node* second) {
        
        double distance = calculateDistance(first.latitude, first.longitude, second.latitude, second.longitude);
        return distance;
}

const std::vector<Node*> & getVertices() {
    static std::vector<Node*> placeholder;
    return placeholder;
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
    
    // for (Node* n1 : graph->getNodes()) {
    //     for (Node* n2 : graph->getNodes()) {
    //         if (n1 != n2) {
    //             // add edge
    //             graph->addEdge(n1, n2, 1.0); // calculate the distance
    //         } else {
    //             // self edge -- use wait time
    //             graph->addEdge(n1, n2, std::stod(wait_time));
    //         }
    //     }
    // }

    return graph;
}