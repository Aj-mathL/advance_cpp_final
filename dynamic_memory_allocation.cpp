#include<iostream>
#include<vector>
using namespace std; 

int * chai(int cups)
{
    int * orders = new int[cups]; 
    for(int i = 0; i< cups; i++)
    {
        orders[i] = (i+1) * cups; 
    }
    return orders; 
}

int main(){
    int cups = 5; 
    int *chaiOrders = chai(cups); 
    for(int i=0; i<cups; i++)
    {
        cout<< " The temperature of tea I have " << chaiOrders[i] << " degree C " <<endl; 

    }

    delete[] chaiOrders; 
    
    return 0;
}