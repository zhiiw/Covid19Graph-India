//
// Created by 86183 on 2021/5/17.
//

#ifndef COVID19GRAPH_INDIA_NODE_H
#define COVID19GRAPH_INDIA_NODE_H

#include <iostream>
#include <utility>

using namespace std;

class node{
private:
    string city_name;
    int patients_num;
    double lat;
    double lng;

public:
    node();
    node(string, int, double, double);
    string get_name(){return city_name;};
    int get_num() const{return patients_num;};
    double get_lat() const{return lat;};
    double get_lng() const{return lng;};
    void add_patient(){patients_num++;};

};

node::node() {

}

node::node(string n, int num, double la, double ln) {
    city_name = std::move(n);
    patients_num = num;
    lat = la;
    lng = ln;
}

#endif //COVID19GRAPH_INDIA_NODE_H
