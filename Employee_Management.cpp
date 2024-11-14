#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

struct Employee
{
    /* data */
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee &emp)
{ // Here we give reference from Employee
    cout<<"ID: "<<emp.id<< " , Name: "<<emp.name <<" , Salary: $" <<emp.salary <<endl; 
}



int main()
{
    vector <Employee> employess= {
        {101, "Abhijit", 200000}, 
        {102, "Bhabesh", 10000}, 
        {103, "Riya", 50000}, 
        {104, "Harry", 90000}, 

    }; 

    sort(employess.begin(), employess.end(), [](const Employee & e1, const Employee & e2 ){
        return e1.salary>e2.salary; 
    }); 

    cout<<"Employeess sorted by salary -> Highest to lowest"<<endl;

    for_each(employess.begin(), employess.end(), displayEmployee); 

    vector<Employee> highEarners; 
    
    

    copy_if(
        employess.begin(), 
        employess.end(), 
        back_inserter( highEarners), 
        [](const Employee &e){
        return e.salary > 50000; 
    }); 

    cout<<"Employees who are high earners \n"; 
    for_each(highEarners.begin(), highEarners.end(), displayEmployee);


    double totalSalary = accumulate(employess.begin(), employess.end(), 0.0, [](double sum, const Employee & e){
        return sum += e.salary;  

    }); 

    double averageSalary = totalSalary /employess.size(); 

    auto higestPaid =  max_element(employess.begin(), employess.end() , [](const Employee & e1, const Employee & e2){
        return e1.salary <e2.salary; 
    }); 

    return 0;
}