#include<iostream>
#include<vector>
#include<string> 
using namespace std; 

class Tea
{
private:
    /* data */
public:
    virtual void prepareIngredients() = 0; //Pure virtual function
    virtual void brew() = 0; //Pure virtual function
    virtual void serve() = 0; //Pure virtual function
    Tea(/* args */){}
    ~Tea(){}

    //
    void makeTea(){
        prepareIngredients(); 
        brew(); 
        serve(); 
    }
};

//Derieved class 
class GreenTea: public Tea{
    public: 
        void prepareIngredients() override {
            cout<<"===== Preparing Green Tea===="<<endl; 
            cout<<"Green leaves and water is ready for green tea"<<endl; 
        }
        void brew() override {
            
            cout<<"Green tea is brew "<<endl; 
        }
        void serve() override {
            
            cout<<"Green tea is served"<<endl; 
        }
}; 
class MasalaTea: public Tea{
    public: 
        void prepareIngredients() override {
            cout<<"===== Preparing Masala Tea===="<<endl; 
            cout<<"Green leaves and water and masala is ready for masala tea"<<endl; 
        }
        void brew() override {
            
            cout<<"Masala tea is brew "<<endl; 
        }
        void serve() override {
            
            cout<<"Masala tea is served"<<endl; 
        }
}; 
class GingerTea: public Tea{
    public: 
        void prepareIngredients() override {
            cout<<"===== Preparing Ginger Tea===="<<endl; 
            cout<<"Green leaves and water and ginger is ready for ginger tea"<<endl; 
        }
        void brew() override {
            
            cout<<"Ginger tea is brew "<<endl; 
        }
        void serve() override {
            
            cout<<"Ginger tea is served"<<endl; 
        }
}; 


int main(){
    GreenTea greentea;
    MasalaTea masalatea; 
    GingerTea gingertea; 
    greentea.makeTea(); 
    masalatea.makeTea(); 
    gingertea.makeTea(); 


    
    return 0;
}