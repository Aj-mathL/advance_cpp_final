#include<iostream>
#include<vector>
using namespace std; 

class Chai
{
private:
    /* data */
    string teaName; 
    int servings; 
    vector <string> ingredients; 

public:
    //Default constructor
    Chai(){
        teaName = "Cutting Chai"; 
        servings= 1; 
        ingredients = {"Water", "Tea_leaves", "Milk", "Sugar"}; 

    }
    //Parametrazied constructor
    Chai(string name, int serve, vector <string> ing){
        teaName = name; 
        servings = serve; 
        ingredients = ing; 
    }

    //==============Deligating Constructor==============
    Chai(string name): Chai(name, 1 , {"Water", "Tea Leaves", "Honey"}) { }


    ~Chai(){
        cout<< "Here deconstructor is called work properly"<<endl; 
    }

    //getter
    string getTeaName(){
        return teaName; 
    }
    //setter 
    void setTeaName(string name){
        teaName = name; 
    }
    // *** 
    int getServings(){
        return servings; 
    }

    void setServings(int serve){
        servings = serve; 
    }

    //*** 
    vector <string> getIngredients(){
        return ingredients; 
    }

    void setIngredients(vector <string> ing){
        ingredients = ing; 
    }

    //Member function
    void displayChaiDetails(){
        cout<<"\t\t ===Here is your Chai details=== \n"; 
        cout<<"Tea Name: "<<teaName<<endl; 
        cout<<"Servings: "<<servings<<endl; 
        cout<<"Ingredients: "; 
        for(string ing: ingredients)
        {
            cout<<ing<< " "; 
        }
        cout<<endl; 

    }
};

// Chai::Chai(/* args */)
// {
// }

// Chai::~Chai()
// {
// }


int main(){

    Chai chai; 
    chai.setTeaName("Lemon Tea"); 
    chai.setServings(5); 
    chai.setIngredients({"Water", "Tea_leaves", "Lemon", "Honey"}); 
    chai.displayChaiDetails(); 

    Chai chai1("Ginger Tea"); 
    chai1.displayChaiDetails(); 

    Chai chai2("Lemon Tea", 3, {"Water ", "Lemon", "Tea Leaves", "Honey"}); 
    chai2.displayChaiDetails(); 

    Chai chai3; 
    chai3.displayChaiDetails(); 

    return 0;
}