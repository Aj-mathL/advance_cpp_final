#include<iostream>
#include<vector>
#include<string> 
using namespace std;

class BankAccount
{
private:
    string accountNumber; 
    double balence;


public:
    BankAccount(string acc, double initialBalence): accountNumber(acc) , balence(initialBalence) {}

    //getter
    double getBalence() const {
        return balence; 
    }

    //Method to deposite
    void deposite(double amount)  {
        if(amount > 0){
            balence += amount; 
            cout<<"\n===Credit Balence====\n"; 
            cout<<"Deposite balence: "<< amount<<endl; 
            cout<<"Total Balence: "<< balence<<endl; 
        }else{
            cout<<"Invalid deposite"<<endl; 

        }
    }

    //Method to withdrawal 
    void withdraw(double amount){
        if(amount>0 && amount <= balence){
            balence -= amount; 
            cout<<"\n==== You make a withdraw of  "<< amount <<"====="<<endl; 
            cout<<"Remaining balence: "<<balence<<endl; 
        }else{
            cout<<"Insufficient balence!"<<endl; 
        }
    }

    ~BankAccount(){}
};




int main(){

    BankAccount acc("1229999", 5000); 
    acc.deposite(2000); 
    acc.withdraw(1500); 
    
    return 0;
}