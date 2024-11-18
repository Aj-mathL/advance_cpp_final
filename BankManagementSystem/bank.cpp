#include "bank.h"

// Utility function to generate a random account number
string generateAccountNumber()
{
    srand(time(0));
    string accNum = "ACC" + to_string(rand() % 10000);
    return accNum;
}

// Constructor for BankAccount
BankAccount::BankAccount(string accNum, string userName, string pass, double bal)
{
    accountNumber = accNum;
    name = userName;
    password = pass;
    balance = bal;
}

// getter
string BankAccount::getAccountNumber()
{
    return accountNumber;
}

string BankAccount::getName()
{
    return name;
}

double BankAccount::getBalence()
{
    return balance;
}

// verify Password
bool BankAccount::verifyPassword(const string &pass)
{
    return password == pass;
}

// Deposite money
void BankAccount::depostie(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }
    else
    {
        cout << "Insuficient" << endl;
    }
}

// Withdraw Money
bool BankAccount::withdraw(double amount)
{
    if (amount > balance && amount < 0)
    {
        cout << "Insufficient funds!" << endl;
        return false;
    }
    else
    {
        balance -= amount;
        cout << "Withdrew: $" << amount << endl;
        return true;
    }
}

// Display Balence
void BankAccount::displayBalance()
{
    cout << "Current Balence: $" << balance << endl;
}

// Load existing accounts form a file
BankSystem::BankSystem()
{
    loadAccounts();
}

// Create a new account
void BankSystem::createAccount()
{
    string name, password;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Set your password: ";
    cin >> password;

    string accNum = generateAccountNumber();
    BankAccount newAccount(accNum, name, password);
    accounts.push_back(newAccount);
    saveAccounts();

    cout << "Account created successfully!\n Your Account number is: " << accNum << endl;
}

// Login to an existing account

BankAccount *BankSystem::login()
{
    string accNum, password;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Password: ";
    cin >> password;

    for (auto &account : accounts)
    {
        if (account.getAccountNumber() == accNum && account.verifyPassword(password))
        {
            cout << "Login Successful! " << endl;
            return &account;
        }
    }
    cout << "Invalid credentials!" << endl;
    return nullptr;
}

// perform operations like deposite, withdraw, view balaence

void BankSystem::performOperations(BankAccount *account)
{
    int choice;
    double amount;

    do
    {
        cout << "\n1. Deposite \n2. Withdraw \n3. Check Balence \n4. View Transactions \n5.Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposite: ";
            cin >> amount;
            account->depostie(amount);

            saveTranstion(account->getAccountNumber(), "Deposite", amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (account->withdraw(amount))
            {
                saveTranstion(account->getAccountNumber(), "Withdraw", amount);
            }
            break;
        case 3:
            account->displayBalance();

            break;
        case 4:
            viewTranstionHistory(account->getAccountNumber());

            break;
        case 5:
            cout << "Logging out..." << endl;
            return;

        default:
            cout << "Invalid option!" << endl;
            break;
        }
    } while (choice != 5);
}
// Load account form file
void BankSystem::loadAccounts()
{
    ifstream file("accounts.txt");
    string accNum, name, password;
    double balance;

    if (file.is_open())
    {
    }
    else
    {
    }

    while (file >> accNum >> name >> password >> balance)
    {
        accounts.push_back(BankAccount(accNum, name, password, balance));
    }
    file.close();
}

// Save account to file
void BankSystem::saveAccounts()
{
    ofstream file("accounts.txt");
    if (file.is_open())
    {
        for (auto &account : accounts)
        {
            file << account.getAccountNumber() << " " << account.getName() << " " << account.getBalence() << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error: Unable to save accounts to file. " << endl;
    }
}

// save transtion to a file
void BankSystem::saveTranstion(const string &accountNumber, const string &type, double amount)
{
    ofstream file("transactions.txt", ios::app);
    if (file.is_open())
    {
        {
            time_t now = time(0);
            char *dt = ctime(&now);
            file << accountNumber << " " << type << "$" << amount << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error: Unable to load accounts from file!" << endl;
    }
}

// view Transtion history
void BankSystem::viewTranstionHistory(const string &accountNumber)
{
    ifstream file("transactions.txt");
    string accNum, type, date;
    double amount;
    bool found = false;

    if (file.is_open())
    {
        cout << "Transtion History for Account: " << accountNumber << endl;
        cout << "-------------------------------------" << endl;
    }

    while (file >> accNum >> type >> amount)
    {
        file.ignore();
        if (accNum == accountNumber)
        {
            found = true;
            cout << "Type: " << type << ": $" << amount << ", Date: " << date << endl;
        }
    }

    if (!found)
    {
        cout << "No transaction history is available for this account." << endl;
    }
    else
    {
        cout << "Unable to open transtion history file!" << endl;
    }
    file.close();
}