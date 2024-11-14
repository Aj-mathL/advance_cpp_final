#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Tea
{
protected: //Protected variable accessible here not need to getter setter as private 
    string teaName;
    int servings;

public:
    Tea(string name, int serve):teaName(name), servings(serve)//main constructor 
    {
        
        cout << "Tea Name: " << teaName << endl;
        cout << "Servings: " << servings << endl;
    }

    virtual ~Tea() //virtual for deconstructor is necessary for inheritance deconstructor "It is important to do otherwise not working "
    {
        cout << "Main destructer called" << endl;
    }

    virtual void brew() const // here we make some functions those we use further; 
    {
        cout << "Brewing " << teaName << endl;
    }

    virtual void serve() const
    {
        cout << "Serving " << servings << endl;
    }
};



class MasalaTea : public Tea
{

public:
    MasalaTea(int serve) : Tea("Masala Tea", serve)
    {
        cout<<"\n\n ====Now constructor from " << teaName<< " Tea==== \n\n"; 
    }

    ~MasalaTea() {
        cout<<"\n\n Destructor of "<<teaName <<" called\n"<<endl; 
    }

    void brew() const override{
        cout<<"Brew "<< teaName <<" by making spies and milk for Masala chia "<<endl; 
    }
    void serve() const override{
        cout<<"Serve "<< teaName << " now! "<<endl; 
    }


    
};


class ElaichiTea : public Tea
{

public:
    ElaichiTea(int serve) : Tea("Elaichi Tea", serve)
    {
        cout<<"\n\n ====Now constructor from "<< teaName <<" Tea==== \n\n"; 
    }

    ~ElaichiTea() {
        cout<<"\n\n Destructor of "<<teaName <<" called\n"<<endl; 
    }

    void brew() const override{
        cout<<"Brew "<< teaName <<" by crusting eleaichi and boil milk for Elaichi Tea"<<endl; 
    }
    void serve() const override{
        cout<<"Serve "<< teaName << " now! "<<endl; 
    }


    
};


class CuttingChai : public Tea
{

public:
    CuttingChai(int serve) : Tea("Cutting Chai", serve)
    {
        cout<<"\n\n ====Now constructor from "<< teaName<< "==== \n\n"; 
    }

    ~CuttingChai() {
        cout<<"\n\n Destructor of "<<teaName <<" called\n"<<endl; 
    }

    void brew() const override{
        cout<<"Brew "<< teaName <<" by boil milk and melting sugar and aroma for cutting chai"<<endl; 
    }
    void serve() const override{
        cout<<"Serve "<< teaName << " now! "<<endl; 
    }
};
class GreenTea : public Tea
{

public:
    GreenTea(int serve) : Tea("Green Tea", serve)
    {
        cout<<"\n\n ====Now constructor from "<< teaName<< "==== \n\n"; 
    }

    ~GreenTea() {
        cout<<"\n\n Destructor of "<<teaName <<" called\n"<<endl; 
    }

    void brew() const override{
        cout<<"Brew "<< teaName <<" by boil milk and melting sugar and aroma for cutting chai"<<endl; 
    }
    void serve() const override{
        cout<<"Serve "<< teaName << " now! "<<endl; 
    }
    
};

int main()
{
    Tea * tea1 = new GreenTea(5); //Here we use pointer and use new key word to get reference from inherite class 
    Tea * tea2 = new MasalaTea(5); 
    Tea * tea3 = new ElaichiTea(5); 
    Tea * tea4 = new CuttingChai(5); 
    tea1->brew(); // here -> this method useful for using pointer . 
    tea1->serve(); 

    tea2->brew(); 
    tea2->serve(); 

    tea3->brew(); 
    tea3->serve(); 

    tea4->brew(); 
    tea4->serve(); 


    delete tea1; 
    delete tea2; 
    delete tea3;
    delete tea4; 

    return 0;
}