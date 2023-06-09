#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

typedef struct crlst
{
  	string roll_no;
   string grade="A";
}crlst;


class course{
    private:
    string co_name;
    string co_id;
    vector<crlst> clst; 
    public:
    void add_course();
    void enroll_sts(string roll);
    void unroll_sts(string a);
};

#endif