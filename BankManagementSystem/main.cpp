#include "bank.h"

int main()
{
    BankSystem bankSystem;
    BankAccount *loggedInAccount = nullptr;

    int choice;
    do
    {
        cout << "\n1. Create Account \n2. Login \n3. Exit \nChoose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bankSystem.createAccount();
            break;
        case 2:
            loggedInAccount = bankSystem.login();
            if (loggedInAccount)
            {
                bankSystem.performOperations(loggedInAccount);
            }
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option!" << endl;
            break;
        }

    } while (choice != 3);
    return 0;
}