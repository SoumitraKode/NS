#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std ;

void First_Task(string &sentence){
    string input_password ;
    cout<<"ENter The Password : ";
    cin>>input_password ;
    if(input_password == sentence){
        cout<<"Password Matched"<<endl;
    }else{
        cout<<"Password is Incorrect"<<endl ;
    }
}

void Second_Task(string sentence){
    string password ;
    char ch ;
    cout<<"Enter Password : ";
    while(true){
        ch = _getch() ;

        if(ch == 13 ){ //enter{
            break ;
        }else if(ch == 8){
            //back space
            if(!password.empty()){
                password.pop_back() ;
                cout<<"\b \b" ;
            }
        }else{
            password.push_back(ch) ;
            cout<<"*" ;
        }
        
    }
    cout<<"Entered Pasword : "<<password<<endl ;
    cout<<endl;
}
void Third_task()
{
    string pass;
    cout<<"Enter The password: ";
    cin>>pass;
    cout<<"Password Entered is: "<<pass;
}

int main(){
    ifstream file("password.txt") ;

    if(!file.is_open()){
        cout<<"Error in Opening File : "<<endl ;
        return 0 ;
    }

    string sentence ;
    getline(file,sentence) ;
    cout<<"Password is :"<<sentence<<endl ;
    //First task 
    First_Task(sentence) ;
    Second_Task(sentence) ;
    Third_task() ;
    return 0 ;
}