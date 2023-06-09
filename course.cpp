#include "course.h"

/*Functions related to class course*/
void course::add_course(){
string filename;
 char ch;
cout<<"Enter the course name:";
cin.ignore();
getline(cin,co_name);
cout<<"enter the course id:";
cin>>co_id;
filename="./Courses/"+co_id+".txt";
 ifstream temp;
 temp.open(filename.c_str());
 if(temp){
   cout<<"course exists"<<endl;
    cout<<"if okay type y?";
 cin>>ch;
 if(ch=='y'){return;}
   return;
}
else{
   cout<<"New course Added"<<endl;
}
 ofstream myfile;
 myfile.open(filename.c_str());
 myfile<<co_name<<endl;
 myfile<<co_id<<endl;
 cout<<"if okay type y?";
 cin>>ch;
 if(ch=='y'){return;}
 return;
}
void course::enroll_sts(string roll){
   crlst *A;
   A=new crlst;
   A->roll_no=roll;
   clst.push_back(*A);
   delete(A);
string filename="./Courses/"+co_id+".txt";
 ofstream myfile;
 myfile.open(filename.c_str());
myfile<<co_name<<endl;
 myfile<<co_id<<endl;
 for(int i=0;i<clst.size();i++){
              myfile<<clst[i].roll_no<<" "<<clst[i].grade<<endl;
           }
}
void course::unroll_sts(string a){
    for(int i=0;i<clst.size();i++){
              cout<<i<<")"<<clst[i].roll_no<<endl;
           }
           vector<crlst>::iterator q;
           q=clst.begin();
           for(int k=0;k<clst.size();k++){
              if(clst[k].roll_no!=a){q++;}
              else{clst.erase(q);}
           }
string filename="./Courses/"+co_id+".txt";
 ofstream myfile;
 myfile.open(filename.c_str());
myfile<<co_name<<endl;
 myfile<<co_id<<endl;
 for(int i=0;i<clst.size();i++){
              myfile<<clst[i].roll_no<<" "<<clst[i].grade<<endl;
           }
}