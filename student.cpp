#include "student.h"
/*These all are functions related to class student*/
   string student::get_name(){
       return name;
    }
    string student::get_roll(){
       return roll_no;
    }
    void student::intiate(string a,string b){
         name=a;
         roll_no=b;
   }
   void student::enroll(string c){
         cIds.push_back(c);
   }
   void student::show_cIds(){
         cout<<"courses enrolled"<<endl;
         for(int i=0;i<cIds.size();i++){
              cout<<i+1<<")"<<cIds[i]<<endl;
           }
   }
   void student::unroll(int a){
           vector<string>::iterator q;
           q=cIds.begin();
           for(int k=0;k<cIds.size();k++){
              if(k!=(a-1)){q++;}
              else{cIds.erase(q);}
           }
   };
   void student::put(ofstream &file){
           for(int i=0;i<cIds.size();i++){
              file<<cIds[i]<<endl;
           }
   }