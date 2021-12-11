#include "edge.h"

// Adapted from https://www.geeksforgeeks.org/program-distance-two-points-earth/

void Edge::convertToRadians(double value) {
    double one_degree = (M_PI) / 180;
    return (one_degree * value);
}

double Edge::calculateDistance(Node* first, Node* second) {
    double first_latitude = first.getLatitude();
    double first_longitude = first.getLongitude();

    double second_latitude = second.getLatitude();
    double second_longitude = second.getLongitude();
    
    // Haversine Formula

    double dlong = long2 - long1;
    double dlat = lat2 - lat1;
 
    double ans = pow(sin(dlat / 2), 2) +
                     cos(lat1) * cos(lat2) *
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