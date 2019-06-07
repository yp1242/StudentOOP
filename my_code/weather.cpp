#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
//Hi...
Date::Date(int d, int m, int y) :day(d), month(m), year(y) {}

ostream& operator<<(ostream& os, const Date& date){
	os <<"Date: Day: "<<date.day << " Month: " << date.month << " Year: " << date.year << endl;
	return os;
}

ostream& operator<<(ostream& os, const WReading& wr) {
	os << wr.date;
	os << "Temperature: " << wr.temperature << " Humidity: " << wr.humidity << " Windspeed: " << wr.windspeed;
	os << endl;
	return os;

}

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

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const GPS& gps) {
	os << gps.latitude << gps.longitude;
	return os;
}
ostream& operator<<(ostream& os, const Weather& w) {
	os <<"Name: "<< w.get_name() << "; rating: " << w.get_rating() << "; Location: " << w.my_loc;
	os << endl;
	for (WReading wr : w.wreadings) {
		os << " " << wr << endl;
	}
	return os;
}