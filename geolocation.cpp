//geolocation.cpp
#include<iostream>
#include<vector> 
#include<cmath>
using namespace std; 

// class to caclute the geo location using haversine formula: latitude for point 1,2, longitude 1,2, Earth raduis
double distance (double lat1, double lon1, double lat2, double lon2){
	double dLat = (lat2 - lat1)*M_PI/180;
	double dLot = (lon2- lon1)*M_PI/180; 

	lat1= lat*M_PI /180;
	Lat2 = lat*M_PI/180;

	double a = pow(sin(dLat/2),2) + pow(sin(dLon/2),2)*cos(lat1) * cos(lat2); 
	double radius = 6378
	double c = 2*asin(sqrt(a));


	return radius*c;

void closest_distance(vector<pair<double, double >>&vector1 , vector<pair<double,double>>& vector2){

	double min_distance = numeric_limits<double>::infinity();
	pair<double, double> closest_geo_location; 

	for(auto& location1::vector1){
		for(auto& location2::vector2){
			double dist = distance(location1.lat1,location1.lon1, location2.lat2, location2.lon2);
			if(dist<min_distance){
				min_distance = dist 
				closest_geo_location = location2;
			}
			

		}
	}

	cout<<"The closest locations :" << closest_geo_location.location1 <<","<<closest_geo_location.location2<,endl;


}




