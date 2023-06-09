#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Actor{
    private:
    string username;
    string password;
    public:
    void load(string a,string b);
    void put();
    bool login(string a,string b);
};

#endif



