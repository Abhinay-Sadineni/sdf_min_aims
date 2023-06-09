/*
Name:SADINENI ABHINAY
ROLL NO: CS21BTECH11055
*/
/*MINI AIMIS PROJECT*/

#include "Admin.h"
#include <dirent.h>
#include <sys/stat.h>


/*Student menu*/
void l_student(string temp){
    student *st;
    st= new student;
    string filename="./Students/"+temp+".txt";
    string a,b,c,d;
    int i;
    ifstream myfile;
    ofstream filet;
    ifstream list;
    myfile.open((filename).c_str());
    getline(myfile,a);
    getline(myfile,b);
    st->intiate(a,b);
    while(getline(myfile,c)){
             st->enroll(c);
    } 
    myfile.close();
    int choice;
    string w;
    int g=0;
    while(choice!=4){
     system("cls");
     cout<<"-----------------------------Student Menu-------------------------"<<endl;
    cout<<"\t\t 1)Show details"<<endl;
    cout<<"\t\t 2)Register a course"<<endl;
    cout<<"\t\t 3)Deregister a course"<<endl;
    cout<<"\t\t 4)back"<<endl<<endl;
    cout<<"enter the choice(1-4): ";
     cin>>choice;
     switch(choice){
    case 1:
         system("cls");
         cout<<"details of student: "<<endl;
         cout<<"Name of student: "<<st->get_name()<<endl;
         cout<<"Roll N.o of student: "<<st->get_roll()<<endl;
         st->show_cIds();
         system("pause>0");
         break;
    case 2:
         system("cls");
               cout<<"list of available courses:"<<endl;
               list.open("./Courses/list.txt");
               while(getline(list,w)){
                   cout<<g+1<<")"<<w<<endl;
                   g++;
                   }
               list.close();
               cout<<"enter course id that u want register : ";
               cin>>d;
               st->enroll(d);
               remove((filename).c_str());
               filet.open((filename).c_str());
               filet<<st->get_name()<<endl<<st->get_roll()<<endl;
               st->put(filet);
               filet.close();
               cout<<"successfully enrolled course "<<d<<endl;
               system("pause>0");
               break;
               
    case 3:
        system("cls");
               st->show_cIds();
               cout<<"Enter the serial number of the which u want to deregister: "<<endl;
               cin>>i;
               st->unroll(i);
               remove((filename).c_str());
               filet.open((filename).c_str());
               filet<<st->get_name()<<endl<<st->get_roll()<<endl;
               st->put(filet);
               filet.close();
               cout<<"successfully unrolled course "<<d<<endl;
               system("pause>0");
               break;
       }
       }
       delete(st);
       return;
    }

/*Admins menu*/
void l_Admin(){
    Admin*A;
    A=new Admin;
    string c;
    int choice;
    ifstream myfile;
    myfile.open("./Courses/list.txt");
    while(getline(myfile,c)){
        A->courses.push_back(c);
    }
    while(choice!=6){
    system("cls");
    cout<<"------------------------------------Admin Menu---------------------------------"<<endl;
    cout<<"\t\t 1)Add student"<<endl;
    cout<<"\t\t 2)Delete student"<<endl;
    cout<<"\t\t 3)Add a course"<<endl;
    cout<<"\t\t 4)Delete a course"<<endl;
    cout<<"\t\t 5)Show list of courses"<<endl;
    cout<<"\t\t 6)back"<<endl;
    cout<<"enter the choice(1-6):";
    cin>>choice;
    switch(choice){
        case 1:
        system("cls");
        A->add_student();
        system("pause>0");
        break;
        case 2:
        system("cls");
        A->delete_student();
        break;
        case 3:
        system("cls");
        A->add_course();
        system("pause>0");
        break;
        case 4:
        system("cls");
        A->delete_course();
        system("pause>0");
        break;
        case 5:
        system("cls");
        A->list();
        system("pause>0");
        break;
    }
}
   delete(A);
   return;
}

/*main code*/
int main(){
           string a,b;
                 Actor *AB;
                 AB=new Actor;
                 AB->load("Admin","1234");
                 AB->put();
                 delete(AB);
    int choice,w;
    if(mkdir("Courses")!=0){
     std::cout<<"\t\t Records already exists"<<endl;
       }
 else{
     std::cout<<"\t\t Records folder created"<<endl;
     }
     if(mkdir("Students")!=0){
     std::cout<<"\t\t Records already exists"<<endl;
       }
 else{
     std::cout<<"\t\t Records folder created"<<endl;
     }
      cout<<"#####################################################"<<endl;
    cout<<"                 Mini Aims                           "<<endl;
    cout<<"          Created by sadineni abhinay(cs21btech11055) "<<endl;
    cout<<"#####################################################"<<endl; 
    system("pause>0");
    system("cls");
    cout<<"#####################################################"<<endl;
    cout<<"                 HELP!                               "<<endl;
    cout<<" 1)Admin default login credintials will be found in the code "<<endl;
    cout<<" 2)Default password to student is student                     "<<endl;
    cout<<" 3)Default username is students roll number                   "<<endl;
    cout<<" 4)Admin can add/delete any number of students                "<<endl;
    cout<<" 5)student can register courses                               "<<endl;
    cout<<"#####################################################"<<endl; 
    system("pause>0");
    system("cls");
    while(choice!=2){
        system("cls");
        cout<<"1)login"<<endl;
        cout<<"2)exit"<<endl;
        cout<<"Enter choice(1-2):";
        cin>>choice;
        switch(choice){
        case 1:
            while(w!=3){
                system("cls");
                cout<<"login system"<<endl;
                cout<<"1)Login as admin"<<endl;
                cout<<"2)Login as student"<<endl;
                cout<<"3)back"<<endl;
                cout<<"Enter choice(1-3):";
                cin>>w;
                 
                switch(w){
                    case 1:
                     system("cls");
                     Actor *W;
                     W=new Actor;
                    cout<<"Enter username:";
                    cin>>a;
                    cout<<"Enter password:";
                    cin>>b;
                    if(W->login(a,b)){
                      cout<<"login sucessful"<<endl;
                      l_Admin();
                      system("pause>0");
                      }
                  else{
                      cout<<"invalid credintials"<<endl;
                      system("pause>0");
                      }
                      delete(W);
                break;
                    case 2:
                    system("cls");
                    Actor *S;
                    S=new Actor;
                    cout<<"Enter username:";
                    cin>>a;
                    cout<<"Enter password:";
                    cin>>b;
                    if(S->login(a,b)){
                      cout<<"login sucessful"<<endl;
                      l_student(a);
                      system("pause>0");
                      }
                  else{
                      cout<<"invalid credintials"<<endl;
                      system("pause>0");
                      }
                      delete(S);
                      break;

                }
                   }
                   w=0;
                    
                }
            }
     return 0;
}
            
                   
      
