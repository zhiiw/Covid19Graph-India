#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
#include "node.h"
#include "graph.h"

using namespace std;

using json = nlohmann::json;
int main(){

    json patients_json;
    json cities_json;
    vector<node*> city;
    string line;
    std::ifstream p(R"(patients.json)");
    std::ifstream c(R"(in.json)");
    p >> patients_json;
    c >> cities_json;

    cout << cities_json[165].at("city") << endl;
    cout << cities_json[186].at("lat") << endl;
    cout << cities_json[186].at("lng") << endl;
    int city_num = (int)cities_json.size();
    auto* matrix_graph = new graph(city_num);
    for(int i = 0; i < city_num; i++){
        string name = (string)cities_json[i].at("city");
        double lat = stod((string)cities_json[i].at("lat"));
        double lng = stod((string)cities_json[i].at("lng"));
        node* new_node = new node(name, 0, lat, lng);
        matrix_graph->add_city(new_node);
    }

    int patient_num = (int)patients_json.at("data").at("rawPatientData").size();
    for(int i = 0; i < patient_num; i++){
        string city_name = (string)patients_json.at("data").at("rawPatientData")[i].at("city");
        matrix_graph->add_patient(city_name);
    }
    matrix_graph->init_distance();
    cout << matrix_graph->to_string() << endl;
    cout << matrix_graph->city_to_string() << endl;
    matrix_graph->dfs_1("Port Blair");
    return 0;
}
