#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class BankAccount
{
private:
    /* data */
    string accountNumber;
    string name;
    string password;
    double balance;

public:
    BankAccount(string accNum, string userName, string pass, double bal = 0.0);

    // Getter and setter
    string getAccountNumber();
    string getName();
    double getBalence();
    bool verifyPassword(const string &pass);

    // Account Operations
    void depostie(double amount);
    bool withdraw(double amount);
    void displayBalance();
    string getAccountDetails();
};

class BankSystem
{
private:
    vector<BankAccount> accounts;

public:
    BankSystem();
    void loadAccounts();
    void saveAccounts();

    // Core Functionalities
    void createAccount();
    BankAccount *login();
    void performOperations(BankAccount *account);
    void viewTranstionHistory(const string &accountNumber);
    void saveTranstion(const string &accountNumber, const string &type, double amount);
};

#endif