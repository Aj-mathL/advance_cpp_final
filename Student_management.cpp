#include<iostream>
#include<vector>
#include<string> 
using namespace std; 

struct Student
{
    string name; 
    int rollNumber; 
    int attendanceCount = 0; //Track Attendance


    //constructor for initialization
    Student(string studentName, int studentRollNumber):name(studentName), rollNumber(studentRollNumber), attendanceCount(0){}
};
//Global Student list
vector <Student> students = {
    {"Abhijit", 1}, 
    {"Bhabesh", 2}, 
    {"Riya", 3}
}; 

//Login Function
bool login(){
    string correctUsername = "teacher"; 
    string correctPassword = "password123"; 
    string username, password;

    cout<<"==========Teacher Login=========="<<endl; 
    cout<<"Username: ";
    cin>>username; 
    cout<<"Password: "; 
    cin>>password; 

    if(username == correctUsername && password == correctPassword){
        cout<<"Login successful!"<<endl; 
        return true; 
    }else{
        cout<<"Invalid username or password!" <<endl; 
        return false; 
    }
}

//Fuction for mark attendance 
void markAttendance(){
    cout<<"=========Mark Attendance============"<<endl; 
    for(auto & student : students){
        char present; 
        cout<<"Is " <<student.name <<" (Roll No: "<< student.rollNumber << ") present? (y/n): "; 
        cin>>present; 
        if(present == 'y' || present == 'Y'){
            student.attendanceCount++; 
            cout<<student.name<<" marked present!"<<endl; 
        }
        else{
            cout<<student.name << " marked absent!"<<endl; 
        }
    }
    cout<<"Attendance marked successfully!"<<endl; 
}

//Function for view attendance
void viewAttendance(){
    cout<<"=============Attendace Report=================="<<endl; 
    cout<<"Roll No    Name \t Attendance Count"<<endl; 
    cout<<"------------------------------------------------"<<endl; 
    for(const auto & student : students){
        cout<<student.rollNumber <<"\t" <<student.name << " \t\t" << student.attendanceCount<<endl; 

    }
}






void mainMenu(){

    int choice; 

    do{
        cout<<"==========Student Attendance System================"<<endl; 
        cout<<"1. Mark Attendance \n 2. View Attendance \n 3. Exit \n Enter your choice: "; 
        cin>>choice; 
        switch ( choice )
        {
        case 1:
            markAttendance(); 
            break;
        case 2:
            viewAttendance(); 
            break;
        case 3:
            cout<<"Exiting system. Goodbye!"<<endl;  
            break;
        
        default:
            cout<<"Invalid choice. Please try again!"<<endl; 
            cout<<"Press Enter to continue..."; 
            cin.ignore(); 
            cin.get();
            break;  
        }

    }while(choice !=3); 
    
}

int main(){
    if(login()){
        mainMenu(); 
    }else{
        cout<<"Access Denied Exiting program...."<<endl;
    }

    return 0; 
}