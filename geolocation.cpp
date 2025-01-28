#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;

// Function to calculate the geographic distance between two points using the Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2){
    double dLat = (lat2 - lat1) * M_PI / 180;
    double dLon = (lon2 - lon1) * M_PI / 180;

    lat1 = lat1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2); 
    double radius = 6378; // Earth's radius in kilometers
    double c = 2 * asin(sqrt(a));

    return radius * c;
}

// Function to find the closest location from two vectors of coordinates
void closest_distance(vector<pair<double, double>>& vector1, vector<pair<double, double>>& vector2){
    double min_distance = numeric_limits<double>::infinity();
    pair<double, double> closest_geo_location; 

    for (auto& location1 : vector1){
        for (auto& location2 : vector2){
            double dist = distance(location1.first, location1.second, location2.first, location2.second);
            if (dist < min_distance){
                min_distance = dist;
                closest_geo_location = location2;
            }
        }
    }

    cout << "The closest locations: (" << closest_geo_location.first << ", " << closest_geo_location.second << ")" << endl;
}

int main() {
    // Example usage
    vector<pair<double, double>> vector1 = {{40.7128, -74.0060}, {34.0522, -118.2437}};  // New York, Los Angeles
    vector<pair<double, double>> vector2 = {{51.5074, -0.1278}, {48.8566, 2.3522}};   // London, Paris
    closest_distance(vector1, vector2);
    return 0;
}
