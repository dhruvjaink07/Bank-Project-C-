/*
PROJECT :- Banking System
LANGUAGE USED :- C++
AUTHOR :- Dhruv Jain
Last Updated :- 12/07/2022

*******************************************************INSTRUCTIONS*************************************************************
                        1.You Can Enter Your Full Name Without Using Underscore
                        2.The PIN Entered By You At The Beggining Should be same at each time asked
                        3.If The PIN not Same You Can Re-enter it again for 5 times
                        4.If Any Issue faced please Contact The Author
                        5.Hope You Liked it!!!
*******************************************************************************************************************************/
#include <iostream>
// #include <iomanip>
#include <windows.h>
#include <string.h>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class Bank
{
private:
    int Age, Acc_number;
    int CheckPin;
    string Acc_Holder_name, account_type, PIN, _PIN;
    float balance = 2000, amount; // Default Balance in a New Account
public:
    // friend Bank Thanks_giving();
    void init_Data_in()
    { // Takes Data To Give Further Access of The Program
        cout << "Enter Account Number: ";
        cin >> Acc_number;
        cout << "Enter PIN: ";
        cin >> PIN;
    }
    void Data_in()
    { // Takes Data To be Printed on PassBook
        cout << "Enter Account Holder's Name: ";
        cin.ignore();                        // Imp Part to Take Name With Blank Spaces
        getline(cin, Acc_Holder_name, '\n'); // Using getline() Function to take name input blank spaces in it
        // cout<<Acc_Holder_name<<endl;
        cout << "Enter Age: ";
        cin >> Age;
        cout << "Enter Account Type: ";
        cin >> account_type;
    }
    void Data_out()
    { // Data Printed for PassBook
        cout << "Account Number: " << Acc_number << endl;
        cout << "Account Holder's Name: " << Acc_Holder_name << endl;
        cout << "Age: " << Age << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit();
    void Withdraw();
    void Thanks_giving()
    { // Wishing Function
        cout << endl
             << endl
             << "\t\t\t"
             << "Thanks For Choosing Us" << endl
             << "\t\t\t"
             << "We Are Glad To Help You Sir/Madam " << Acc_Holder_name << endl
             << "\t\t\t"
             << "For Further Issues Please visit Your Nearest Branch!!" << endl;
    }
};
void Bank ::Deposit()
{ // Important Function To Deposit Money in Bank Account
    int i = 0;
PWD: // for Bring the goto statement Here So the User Can Enter the Correted PIN And Deposit the Money Successfully!
    cout << "Enter PIN: ";
    cin >> _PIN;
    CheckPin = PIN.compare(_PIN); // Comparing PIN Entered By The Account Holder at the Starting if The Pin Matches The User Can Deposit Money else He /She HAve To renter The Pin.

    if (CheckPin == 0)
    {
        cout << "How Much Money Does Mr/Mrs " << Acc_Holder_name << " wants to Deposit :";
        cin >> amount;
        balance += amount;
        cout << "Bank Balance: " << balance << endl;
        cout << "Successfully Deposited amount of " << amount << endl;
    }
    else
    { // Can Renter The PIN Only till 5 Incorrect PIN's By User!
        for (i; i < 5; i++)
        {
            cout << "Renter Your PIN!" << endl;
            i++;
            goto PWD; // Use of goto statement
        }
        // Program Terminates after 5 Incorrect PIN Inputs!!
        cout << "You Have Entered 5 Times Wrong PIN!!" << endl;
    }
}

void Bank ::Withdraw()
{ // Imp Function WithDraw Money From The Account
    int i = 0;
PWD:
    cout << "Enter PIN: ";
    cin >> _PIN;
    CheckPin = PIN.compare(_PIN); // Comparing PIN Entered By The Account Holder at the Starting if The Pin Matches The User Can WithDraw Money else He /She HAve To renter The Pin.
    if (CheckPin == 0)
    {

        cout << "How Much Money Does Mr/Mrs " << Acc_Holder_name << " wants to Withdraw :";
        cin >> amount;
        if (balance < amount) // If The Amount Requested By The User
        {
            cout << "Sorry Money Required is Not Present in Your Account" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Bank Balance: " << balance << endl;
            cout << "Successfully Withdrawed amount of " << amount << endl;
        }
    }
    else
    {
        for (i; i < 5; i++)
        {
            cout << "Renter Your PIN!" << endl;
            i++;
            goto PWD;
        }
        cout << "You Have Entered 5 Times Wrong PIN!!" << endl;
    }
}
void clrscr();
int main()
{

    int ANS;
    Bank B1;
    cout << "\t\t\t **********Welcome To ISUV Bank**********" << endl;
    B1.init_Data_in();

    B1.Data_in();

    cout << "Press 1 to Print PassBook" << endl;
    cout << "Press 2 to Deposit Money in Your Account" << endl;
    cout << "Press 3 to Withdraw Money from Your Account" << endl;
    cin >> ANS;
    // clrscr();
    switch (ANS)
    {
    case 1:
        B1.Data_out();
        break;

    case 2:
        B1.Deposit();
        break;

    case 3:
        B1.Withdraw();
        break;
    default:
        cout << "Invalid Choice!" << endl;
        break;
    }
    B1.Thanks_giving();
    return 0;
}