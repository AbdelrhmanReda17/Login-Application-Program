#include "LoginApp.h"
#include "LoginApp.cpp"

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
