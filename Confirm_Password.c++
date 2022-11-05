/*
MINI PROJECT :- Password Confirmer*
LANGUAGE USED :- C++
AUTHOR :- Dhruv Jain
Last Updated :- 05/07/2022
*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str1, str2;
    int check;
    cout << "Enter Your Password: " << endl;
    cin >> str1;
    cout << "Confirm Your Password: " << endl;
    cin >> str2;
    // check = strcmp(*str1,*str2);
    // compare() Function in C++ Gives Broadly two outputs of compapring string
    // equal to(==0)
    // or
    // not Equal to (!=0)
    check = str1.compare(str2);
    if (check == 0)
    {
        cout << "Your Password Have Been Saved!" << endl;
    }
    else
    {
        cout << "Please Check and Renter Your Password!!" << endl;
    }

    return 0;
}