#include "node.h"

Node::Node() {}

Node::Node(int wait_time, double latitude, double longitude, std::string name) {
    wait_time_ = wait_time;
    latitude_ = latitude;
    longitude_ = longitude;
    name_ = name;

    // need a way to set the incident edges for this specific node
}

int Node::getWaitTime() {
    return wait_time_;
}

double Node::getLatitude() {
    return latitude_;
}

double Node::getLongitude() {
    return longitude_;
}

std::string Node::getName() {
    return name_;
}

const std::vector<Edge*> getEdges() {
    return edges_;
}

const std::vector<Node*> getNodes() {
    return nodes_;
}

void Node::addEdge(Edge* e) {
    edges_.push_back(e);
}

void Node::addNode(Node* n) {
    nodes_.push_back(n);
}