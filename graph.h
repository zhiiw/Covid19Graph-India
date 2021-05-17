//
// Created by zhiiw on 2021/5/16.
//

#ifndef COVID19GRAPH_INDIA_GRAPH_H
#define COVID19GRAPH_INDIA_GRAPH_H

#include "node.h"
#include <sstream>
#include <vector>
#include <cmath>
#define pi 3.1415926535897932384626433832795
#define EARTH_RADIUS 6378.137

class graph {
private:
    vector<node*> cities;
    int v;
    vector<vector<double>> a;

public:
    graph();
    explicit graph(int num);
    void init_distance();
    void add_edge(int i, int j, double weight);
    void add_city(node* city);
    void add_patient(const string& city_name);
    string to_string();
    string city_to_string();
    static double rad(double d);
    static double real_distance(double lat1, double lng1, double lat2, double lng2);
};

graph::graph() {
    v = 200;
    cities = vector<node*>(v);
    a = vector<vector<double>>(v);
    for (int i =0; i<v; i++) a[i] = vector<double>(v);
    for (int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            a[i][j] = 0;
        }
    }
}

graph::graph(int num) {
    v = num;

    a = vector<vector<double>>(v);
    for (int i =0; i<v; i++) a[i] = vector<double>(v);
    for (int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            a[i][j] = 0;
        }
    }
}

void graph::add_edge(int i, int j, double weight) {
    a[i][j] = a[j][i] = weight;
}

void graph::add_city(node* city){
    cities.push_back(city);
}

string graph::to_string()
{
    ostringstream os;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) os << a[i][j] << " ";
        os << endl;
    }
    return os.str();
}

string graph::city_to_string(){
    ostringstream os;
    for (int i = 0; i < v; i++){
        os << cities[i]->get_name() << " " << cities[i]->get_num() << endl;
    }

    return os.str();
}

void graph::add_patient(const string& city_name) {
    for(int i = 0; i < v; i++){
        if(cities[i]->get_name() == city_name){
            cities[i]->add_patient();
            break;
        }
    }
}

double graph::real_distance(double lat1, double lng1, double lat2, double lng2) {
    double a;
    double b;
    double radLat1 = rad(lat1);
    double radLat2 = rad(lat2);
    a = radLat1 - radLat2;
    b = rad(lng1) - rad(lng2);
    double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
    s = s * EARTH_RADIUS;

    return s;
}

double graph::rad(double d)
{
    return d * pi /180.0;
}

void graph::init_distance() {
    for(int i = 0; i < v - 1; i++){
        for(int j = i + 1; j < v; j++){
            double distance = real_distance(cities[i]->get_lat(), cities[i]->get_lng(),
                                            cities[j]->get_lat(), cities[j]->get_lng());
            add_edge(i, j, distance);
        }
    }
}
#endif //COVID19GRAPH_INDIA_GRAPH_H
