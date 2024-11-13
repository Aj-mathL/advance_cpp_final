#include<iostream>
#include<vector>
using namespace std; 

class Chai
{
private:
    /* data */
public:
    string teaName; 
    int servings; 
    vector <string> ingridents; 

    //Member function 
    void displayChaiDetails(){
        cout<<"Tea Name: " <<teaName <<endl; 
        cout<<"Servings: " <<servings<<endl; 
        cout<<"Ingridents: " ; 
        for(string ing: ingridents)
        {
            cout<< ing << " " ; 
        }
        cout<<endl; 
    }



    Chai(/* args */);
    ~Chai();
};

Chai::Chai(/* args */)
{
}

Chai::~Chai()
{
}


int main(){

    Chai LemonTea; 
    LemonTea.teaName = "Lemon Tea"; 
    LemonTea.servings = 2; 
    LemonTea.ingridents = { " Water " , "Lemon" , "Tea Leaves" , "Honey" , "Bayleaf"}; 

    LemonTea.displayChaiDetails(); 

    return 0;
}