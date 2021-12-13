#include "node.h"

Node::Node() {
    wait_time_ = 0;
    latitude_ = 0;
    longitude_ = 0;
    name_ = "";
}

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

const std::string& Node::getName() {
    return name_;
}

const std::vector<Edge*>& Node::getAdjacentEdges() {
    return edges_;
}

const std::vector<Node*>& Node::getAdjacentNodes() {
    return nodes_;
}

void Node::addAdjacentEdge(Edge* e) {
    edges_.push_back(e);
}

void Node::addAdjacentNode(Node* n) {
    nodes_.push_back(n);
}
