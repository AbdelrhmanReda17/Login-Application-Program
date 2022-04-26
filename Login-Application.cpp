#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <cstring>

using namespace std;
int mainmessage();

int main()
{
        cout << "Ahlan ya User Ya Habibyyy \n";
        sleep(1);
        system("CLS");
        mainmessage();
}

int mainmessage()
{
    string choosing;
    while(true)
    {
          cout  << "[1] Login \n"
                << "[2] Register \n"
                << "[3] Change Password\n"
                << "[0] Exit. \n";
         cin >> choosing;
        if(choosing == "0")
        {
            cout << "See You Next Time ..." << endl;
            break;
        }
        else if (choosing == "1")
        {

        }
        else
        {
            sleep(1);
            system("CLS");
            cout << "Wrong Choose !!" << endl;
            return mainmessage();
        }

    }

}


