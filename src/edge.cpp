#include "edge.h"
#include "math.h"

// Adapted from https://www.geeksforgeeks.org/program-distance-two-points-earth/

double Edge::convertToRadians(double value) const {
    double one_degree = (M_PI) / 180;
    return (one_degree * value);
}

double Edge::calculateDistance() const {
    double first_latitude = first_->getLatitude();
    double first_longitude = first_->getLongitude();

    double second_latitude = second_->getLatitude();
    double second_longitude = second_->getLongitude();

    double first_latitude_ = convertToRadians(first_latitude);
    double first_longitude_ = convertToRadians(first_longitude);
    double second_latitude_ = convertToRadians(second_latitude);
    double second_longitude_ = convertToRadians(second_longitude);
    
    // Haversine Formula

    double dlong = second_longitude_ - first_longitude_;
    double dlat = second_latitude_ - first_latitude_;
 
    double ans = pow(sin(dlat / 2), 2) +
                     cos(first_latitude_) * cos(second_latitude_) *
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
    edge_weight_ = calculateDistance();
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