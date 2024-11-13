#include<iostream>

#include<vector>

#include<string> 

using namespace std; 

class Chai
{
private:
    /* data */
    string teaName; 
    int servings; 
    
public:
    Chai(string name, int serve): teaName(name), servings(serve) {}

    friend bool compareServings(const Chai &chai1, const Chai &chai2); 

    ~Chai(){}

    void display( ) const {
        cout<<"Tea Name: "<<teaName <<endl; 
    }
};


bool compareServings(const Chai & chai1, const Chai & chai2){
    return chai1.servings >chai2.servings; 
}
// Chai::Chai(/* args */)
// {
// }

// Chai::~Chai()
// {
// }


int main(){
    Chai masalaChai("Masala Chai", 5); 
    Chai gingerTea("Ginger Tea", 7); 

    masalaChai.display(); 
    gingerTea.display(); 

    if(compareServings(masalaChai, gingerTea)){
        cout<<"Masala Chai has more servings\n"; 
    }else{
        cout<<"Masal Chai has less servings\n"; 
    }
    
    return 0;
}