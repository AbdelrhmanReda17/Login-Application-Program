#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>
#include <regex>

using namespace std;
int mainmessage();
fstream datafile;
map<string,string> userCheck;
struct register_user
{
    string Uname;
    string Uemail;
    string Uid;
    string Uphone;
    string Upassword;
} newu;

void GetUemail(register_user& newu)
{
    map<string,string>::iterator it;
    getline(cin,newu.Uemail);
    regex valid_email("((([!--]|[A-z]|[0-9])+(\.)?([!--]|[A-z]|[0-9])+[@])|(([!--]|[A-z]|[0-9])+[@]))((([A-z]*[0-9]*[A-z]+[0-9]*)+[-]?([A-z]*[0-9]*[A-z]+[0-9]*))|([A-z]*[0-9]+[A-z]*[-]?[0-9]*[A-z]+[0-9]*)|([0-9]*[A-z]+[0-9]*[-]?[A-z]*[0-9]+[A-z]*)|([A-z]))+(\.com)");
    while (!regex_match(newu.Uemail, valid_email))
    {
                cout << "Invalid E-Mail !, Try Again\n:";
                getline(cin,newu.Uemail);

    }
    for(it = userCheck.begin(); it!=userCheck.end(); it++)
    {
        if( it->second == newu.Uemail)
        {
            cout << "Email Already Exists!, Try Again\n:" ;
            return GetUemail(newu);
        }
    }
}
void GetUphone(register_user& newu)
{
    getline(cin,newu.Uphone);

}
void GetUname(register_user& newu)
{
    cin.ignore();
    getline(cin,newu.Uname);
}
void GetUPassword(register_user& newu)
{
    getline(cin,newu.Upassword);
}
void GetUid(register_user& newu)
{
    getline(cin,newu.Uid);
    map<string,string>::iterator it;
    it = userCheck.find(newu.Uid);
    if( it != userCheck.end())
    {
        cout << "This ID Number Already Exists!, Try Again\n:";
        return GetUid(newu);
    }
}
void addinfo()
{
    string line;
    string filename = "usersdata.txt";
    ifstream myStream(filename);
    while(!myStream.fail() && !myStream.eof())
    {
        if(!myStream.eof())
        {
            while(getline(myStream, line))
            {
                string email,id;
                int emailfound =0 , idfound = 0;
                if (line.find("| E-Mail") != std::string::npos)
                    emailfound = line.find("| E-Mail") + 9;
                while(line[emailfound] != ' ')
                {
                    email+= line[emailfound];
                    emailfound++;
                }
                if (line.find("| ID") != std::string::npos)
                    idfound = line.find("| ID") + 5;
                while(line[idfound] != ' ')
                {
                    id+= line[idfound];
                    idfound++;
                }
                userCheck.insert({id,email});
            }
        }
    }
    myStream.close();

}

ostream& operator<< (ostream& out ,const register_user& i)
{
    out << "NAME:" << i.Uname ;
    out << " | E-Mail:" << i.Uemail ;
    out << " | ID:" << i.Uid ;
    out << " | Phone Number:" << i.Uphone ;
    out << " | Password:" << i.Upassword ;
}

istream& operator>> (istream& in, register_user& i){
   cout << "Please enter the User Name: ";
   GetUname(i);
   cout << "Please enter the E-Mail: ";
   GetUemail(i);
   cout << "Please enter the User ID: ";
   GetUid(i);
   cout << "Please enter the Phone Number: ";
   GetUphone(i);
   cout << "Please enter the Password: ";
   GetUPassword(i);
   return in;
}


void user_register()
{
    addinfo();
    datafile.open("usersdata.txt",ios::app);
    cin >> newu;
    cout << "Congratulations, your account has been successfully created";
    datafile << newu << endl;

}


int main()
{
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
          cout << "=> ";
         cin >> choosing;
        if(choosing == "0")
        {
            cout << "See You Next Time ..." << endl;
            break;
        }
        else if (choosing == "2")
        {
            sleep(1);
            system("CLS");
            user_register();
            break;
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
