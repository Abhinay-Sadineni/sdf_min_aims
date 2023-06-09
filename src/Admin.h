#ifndef ADMIN_H
#define ADMIN_H

#include "student.h"
#include "course.h"

class Admin: public Actor{
    public:
    vector<string>courses;
    void add_student();
    void delete_student();
    void add_course();
    void delete_course();
    void list();
};

#endif

