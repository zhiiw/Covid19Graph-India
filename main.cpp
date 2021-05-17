//
// Created by zhiiw on 2021/5/16.
//
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using json  = nlohmann::json;
int main(){
    json jsonPatients;
    json citys;
    std::ifstream i("indiaPatients.json");
    std::ifstream j("indiaCitys.json");
    i>>jsonPatients;
    j>>citys;

    std::cout<<"hello world";
}
