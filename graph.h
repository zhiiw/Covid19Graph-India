//
// Created by zhiiw on 2021/5/16.
//

#ifndef COVID19GRAPH_INDIA_GRAPH_H
#define COVID19GRAPH_INDIA_GRAPH_H
#include <stack>
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
    int edge;
    vector<vector<double>> a;
    void dfsUtil(int start,int end);
public:
    graph();
    explicit graph(int num);
    void init_distance();
    void add_edge(int i, int j, double weight);
    void add_city(node* city);
    void add_patient(const string& city_name, const string& district_name, const string& state_name);
    void dfs_1(string cityName);
    void dfs_2(string highRiskCity,string lowRiskCity);
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
    edge++;
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
void graph::dfsUtil(int start, int endPoint) {
    int set[100],min,i,j,u;
    int path[10000];
    int dist[1000];

    for(i=0;i<=183;i++)
    {
        dist[i]= a[start][i];
        set[i]=0;//initial not pass
        if(a[start][i]<INT64_MAX)
        {
            path[i]=start;
        }
        else
        {
            path[i]=-1;
        }
    }
    set[start]=1;
    path[start]=-1;
    for(int i=0;i<edge-1;i++)
    {
        min=10000;
        for(j=0;j<184;j++)
        {
            if(set[j]==0&&dist[j]<min)
            {
                u=j;
                min=dist[j];
            }
        }
        set[u]=1;
        for(j=0;j<184;j++)
        {
            if(set[j]==0&&dist[u]+a[u][j]<dist[j])
            {
                dist[j]=dist[u]+a[u][j];
                path[j]=u;
            }
        }
    }
    int end;
    stack <int> stackForOutput;
    string str="";
    while(path[endPoint]!=-1)
    {
        stackForOutput.push(endPoint);
        endPoint=path[endPoint];
    }
    stackForOutput.push(endPoint);
    cout<<"The shortest path:"<<endl;
    while(!stackForOutput.empty())
    {
        cout<<stackForOutput.top()<<" ";
        if (stackForOutput.size()==1){
            str+=std::to_string(stackForOutput.top());

        }
        else{str+=std::to_string(stackForOutput.top())+" -> ";}
        stackForOutput.pop();

    }
    cout<<endl;
    str+= "\n the distance is "+std::to_string(dist[end]);

}
string graph::city_to_string(){
    ostringstream os;
    for (int i = 0; i < v; i++){
        os << cities[i]->get_name() << " " << cities[i]->get_num() << endl;
    }

    return os.str();
}

void graph::add_patient(const string& city_name, const string& district_name, const string& state_name) {
    for(int i = 0; i < v; i++){
        if(cities[i]->get_name() == city_name || cities[i]->get_name() == district_name || cities[i]->get_name() == state_name){
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
//count the shortest path from delhi to another city
void graph::dfs_1(string cityName) {
    int delhi=0;
    int destination = 0;
    for(int i = 0; i < v; i++){
        if(cities[i]->get_name() == cityName){
            destination=i;
            break;
        }

    }
    for(int i = 0; i < v; i++){
        if(cities[i]->get_name() =="Delhi"){
            delhi=i;
            break;
        }
    }
    dfsUtil(delhi,destination);

}
void graph::dfs_2(string highRiskCity, string lowRiskCity) {
    int start=0;
    int destination = 0;
    for(int i = 0; i < v; i++){
        if(cities[i]->get_name() == lowRiskCity){
            destination=i;
            break;
        }

    }
    for(int i = 0; i < v; i++){
        if(cities[i]->get_name() ==highRiskCity){
            start=i;
            break;
        }
    }
    dfsUtil(start,destination);
}
#endif //COVID19GRAPH_INDIA_GRAPH_H
