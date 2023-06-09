#ifndef STUDENT_H
#define STUDENT_H

#include "Actor.h"
class student : public Actor{
    private:
    string name;
    string roll_no;
    vector<string>cIds;
    public:
    string get_name();
    string get_roll();
    void intiate(string a,string b);
    void enroll(string c);
    void show_cIds();
    void unroll(int a);
    void put(ofstream &file);
};

#endif
