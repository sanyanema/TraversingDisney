#include "edge.h"
#include "math.h"

// Adapted from https://www.geeksforgeeks.org/program-distance-two-points-earth/

double Edge::convertToRadians(double value) const {
    double one_degree = (M_PI) / 180;
    return (one_degree * value);
}

double Edge::calculateDistance(Node* first, Node* second) const {
    double first_latitude = first->getLatitude();
    double first_longitude = first->getLongitude();

    double second_latitude = second->getLatitude();
    double second_longitude = second->getLongitude();
    
    // Haversine Formula

    double dlong = second_longitude - first_longitude;
    double dlat = second_latitude - first_latitude;
 
    double ans = pow(sin(dlat / 2), 2) +
                     cos(first_latitude) * cos(second_latitude) *
                     pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    double R = 6371;
     
    // Calculate the result
    ans = ans * R;
 
    return ans;
}

Edge::Edge() {
    edge_weight_ = -1;
}

Edge::Edge(Node* first, Node* second, double edge_weight) {
    first_ = first;
    second_ = second;
    edge_weight_ = edge_weight;
}

Edge::Edge(Node* first, Node* second) {
    first_ = first;
    second_ = second;
    edge_weight_ = calculateDistance(first_, second_);
}

double Edge::getEdgeWeight() const {
    return edge_weight_;
}

Node* Edge::getIncident(Node* node) const {
    if (node == second_) {
        return first_;
    } else {
        return second_;
    }
}

Node* Edge::getFirstNode() const {
    return first_;
}

Node* Edge::getSecondNode() const {
    return second_;
}