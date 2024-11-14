#include<iostream>
#include<vector>
#include<string> 
#include<deque>
#include<list>
#include<set>
#include<map>
#include<ctime>
#include<unordered_map>
#include<unordered_set>


using namespace std; 

struct Product
{
    /* data */
    int productID; 
    string name; 
    string category; 

};

struct  Order
{
    /* data */
    int orderID; 
    int productID; 
    int quantity; 
    string coustomerID;
    time_t orderDate; 
};

int main(){
    vector <Product> products={
        {101, "Laptop", "Electronics"}, 
        {102, "Mobile", "Electronics"}, 
        {103, "Headphone", "Electronics"}, 
        {104, "TV Screen", "Electronics"}, 
        {105, "Mouse", "Electronics"}, 
    }; 

    deque <string> recentCustomers ={
        "C001", "C002", "C003", "C004", "C005"
    }; 

    recentCustomers.push_back("C006"); 

    list<Order> orderHistory; 
    orderHistory.push_back({1, 101, 1, "C001", time(0)}); 
    orderHistory.push_back({2, 102, 1, "C002", time(0)}); 
    orderHistory.push_back({3, 103, 1, "C003", time(0)}); 
    orderHistory.push_back({4, 104, 1, "C004", time(0)}); 
    orderHistory.push_back({5, 105, 1, "C005", time(0)}); 


    set <string> categories; 
    for(const auto & product: products){
        categories.insert(product.category); 
    }

    map<int, int> productStock = {
        {101, 10}, 
        {102, 20}, 
        {103, 5}, 
        {104, 7}, 
        {105, 15}
    }; 
    multimap <string, Order> customerOrders; 

    for(const auto & order: orderHistory){
        customerOrders.insert({order.coustomerID, order}); 
    }

    unordered_map <string, string> customerData ={
        {"C001", "Abhijit"}, 
        {"C002", "Abhijit"}, 
        {"C003", "Abhijit"}, 
        {"C004", "Abhijit"}, 
        {"C005", "Abhijit"}, 
    }; 

    unordered_set <int> uniqueProductIDs; 
    for(const auto& product: products)
    {
        uniqueProductIDs.insert(product.productID); 
    }

    cout<<"\n\n===========Information about Products===========\n\n"<<endl; 

    for(const  auto & product : products ){
        cout<<product.productID<<endl; 
        cout<<product.name<<endl; 
        cout<<product.category<<endl; 
        cout<<"=============================="<<endl;
    }

    cout<<"\n\n==========Informaton about Coustomers==========\n\n"<<endl;
    

    return 0; 
}


