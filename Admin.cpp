#include "Admin.h"
/*These are functions related to class Admin*/
void Admin::add_student(){
    student st;
    char ch;
    string a,b,filename;
    cout<<"enter the name: ";
    cin.ignore();
    getline(cin,a);
    cout<<"enter the roll no: ";
    getline(cin,b);
     Actor *AB;
     AB=new Actor;
     AB->load(b,"student");
     AB->put();
    delete(AB);
    filename="./Students/"+b+".txt";
    st.intiate(a,b);
     ifstream temp;
    temp.open((filename).c_str());
    if(temp){
    cout<<"student exists"<<endl;
    cout<<"if okay type y?";
    cin>>ch;
    if(ch=='y'){return;}
     return;
     }
    temp.close();
    ofstream myfile;
    myfile.open((filename).c_str());
    myfile<<st.get_name()<<endl<<st.get_roll()<<endl;
    myfile.close();
    cout<<"if okay type y?";
    cin>>ch;
    if(ch=='y'){return;}
    return;
}

void Admin::delete_student(){
    string d,filename;
    cout<<"Delete a student"<<endl;
    cout<<"enter the student roll no: "<<endl;
    cin>>d;
    filename="./Students/"+d+".txt";
    ifstream temp;
    temp.open((filename).c_str());
    if(temp){
    cout<<"sucessfully deleted student"<<endl;
     temp.close();
    remove((filename).c_str());
    }
    else{
        cout<<"student does't exist"<<endl;
        cout<<"invalid deletion"<<endl;
        remove((filename).c_str());
        temp.close();      
        }
    system("pause>0");
    return;
}
void Admin::add_course(){
    string d;
    cout<<"Adding a course"<<endl;
    cout<<"Enter course Id: ";
    cin>>d;
    course*cr;
    cr=new course;
    cr->add_course();
    delete(cr);
    courses.push_back(d);
    ofstream myfile;
    myfile.open("./Courses/list.txt");
    for(int i=0;i<courses.size();i++){
        myfile<<courses[i]<<endl;
    }
    myfile.close();
}
void Admin::delete_course(){
    string d;
    int j;
    cout<<"Deleting a course a course"<<endl;
    cout<<"list of courses"<<endl;
    for(int i=0;i<courses.size();i++){
        cout<<i+1<<")"<<courses[i]<<endl;
    }
    cout<<"Enter the serial number of course to get it delete:";
    cin>>j;
    while(j>courses.size()){
        cout<<"Enter the valid serial number:";
        cin>>j;
    }
    vector<string>::iterator q;
           q=courses.begin();
           for(int k=0;k<courses.size();k++){
              if(k!=(j-1)){q++;}
              else{
                  d=courses[k];
                  courses.erase(q);}
                  
}
string filename="./Courses/"+d+".txt";
remove((filename).c_str());
ofstream myfile;
myfile.open("./Courses/list.txt");
    for(int i=0;i<courses.size();i++){
        myfile<<courses[i]<<endl;
    }
            cout<<"Course deleted sucessfully"<<endl;
}
void Admin::list(){
      cout<<"list of courses:"<<endl;
     for(int i=0;i<courses.size();i++){
        cout<<courses[i]<<endl;
    }
}
