#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
//Hi...
Weather::Weather(std::string nm, GPS loc) :
	station_nm(nm), my_loc(loc) {
}


string Weather::get_name() const{
	return station_nm;
}

int Weather::get_rating() const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

ostream& operator<<(ostream& os, const GPS& gps) {
	os << gps.latitude << gps.longitude;
	return os;
}
ostream& operator<<(ostream& os, const Weather& w) {
	int r = w.get_rating();
	os << w.station_nm << " : rating" << r;
	os << " My location is" << w.my_loc;
	return os;
}