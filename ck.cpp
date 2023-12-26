#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

struct Record {
    int id;
    int flag1;
    int flag2;
    std::string school;
    std::string team;
    std::vector<std::string> members;
};

std::vector<Record> parseRecords(const std::vector<std::string>& lines) {
    std::vector<Record> records;
    for (const auto& line : lines) {
        std::istringstream iss(line.substr(3)); // Skip "@t "
        Record record;
        char comma;
        iss >> record.id >> comma >> record.flag1 >> comma >> record.flag2 >> comma;
        std::getline(iss, record.school, '-');
        iss >> comma; // Skip the space after "-"
        std::getline(iss, record.team, '-');
        iss >> comma; // Skip the space after "-"
        for (int i = 0; i < 3; ++i) {
            std::string member;
            std::getline(iss, member, ',');
            record.members.push_back(member);
        }
        records.push_back(record);
    }
    return records;
}

int main() {
    int rk; std::string s;
    std::vector<std::pair<int,std::string>> v;
    while(std::cin >> rk >> s){
        v.push_back({rk, s});
    }
    std::sort(v.begin(), v.end());
    // std::vector<std::string> lines(240);
    // for(auto &s:lines){
    //     getline(std::cin,s);
    // }
    // auto records = parseRecords(lines);
    // // Now you can process the records as needed.
    std::map<std::string, int> mp;
    int idx = 0;
    for(auto [i,j]:v)if(mp[j] == 0){
        mp[j] = 1;
        std::cout << ++ idx <<  ' ' << i << ' ' << j << std::endl;
        // std::cout << now.id << ' ' << now.school << std::endl;
    }
    return 0;
}
