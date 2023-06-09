#include "Actor.h"
/*These functions related to Class Actor*/
void Actor::load(string a,string b){
    username=a;
    password=b;
}

void Actor:: put(){
    ofstream myfile;
    myfile.open("users.txt",ios::app);
    myfile<<username<<" ";
    myfile<<password<<" "<<endl;
    myfile.close();

}
bool Actor::login(string a,string b){
    ifstream myfile;
    myfile.open("users.txt");
    while(myfile>>username>>password){
        if((username==a)&&(password==b)){
            myfile.close();
            return true;
        }
    }
    myfile.close();
    return false;
}