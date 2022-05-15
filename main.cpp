/*
FCAI – Programming 1 – 2022 - Assignment 4
Program Name: CS112-203-2nd–S1,2-20210255-20210376-20210436-A4-LoginApp.cpp
Program Description: Login Application
Last Modification Date: 12 / 5 / 2022.
Author1 and ID and Group: Abdelrhman Reda Mohamed- 20210255- GROUP A
Author2 and ID and Group: Mahmoud Mamdouh Abdelaziz-20210376- GROUP A
Author3 and ID and Group: Nourhan Elsayed Hassan Ibrahim-20210436- GROUP A
Teaching Assistant: Eng. Nesma & Eng. Yousra
Purpose: Registeration and login of users' accounts
 */


//--------------------------------------------------
//             int Main Function
//--------------------------------------------------
#include "LoginApp.h"

int main()
{
    string choosing;
    while(true)
    {
          cout  << "[1] Login \n"
                << "[2] Register \n"
                << "[0] Exit. \n";
          cout << "=> ";
         cin >> choosing;
        if(choosing == "0")
        {
            cout << "See You Next Time ..." << endl;
            break;
        }
        else if (choosing == "1")
        {
                cin.ignore();
                sleep(1);
                system("CLS");
                user_login();
        }
        else if (choosing == "2")
        {
                cin.ignore();
                sleep(1);
                system("CLS");
                user_register();
        }
        else
        {
            sleep(1);
            system("CLS");
            cout << "Wrong Choose !!" << endl;
            return main();
        }

    }
}
