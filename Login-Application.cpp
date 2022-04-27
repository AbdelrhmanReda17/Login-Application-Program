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
<<<<<<< HEAD
#include <conio.h>
=======
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a

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
<<<<<<< HEAD
        cout << "Invalid E-Mail !";
        cout << "Please enter the E-Mail: ";
        getline(cin,newu.Uemail);
=======
                cout << "Please enter the E-Mail: ";
                cout << "Invalid E-Mail !";
                getline(cin,newu.Uemail);
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a

    }
    for(it = userCheck.begin(); it!=userCheck.end(); it++)
    {
        if( it->second == newu.Uemail)
        {
            cout << "Email Already Exists!, Try Again\n:";
            return GetUemail(newu);
        }
    }
}
void GetUphone(register_user& newu)
{
<<<<<<< HEAD
    cout << "Please Enter the Phone Number: ";
    getline(cin,newu.Uphone);
    if(newu.Uphone.size() == 11  || newu.Uphone.size() == 10)
    {
        while(!regex_match(newu.Uphone, regex("(01)(1|2|5|0)([0-9]+)")))
        {
                cout << "Invalid Phone Number !, Try Again\n:" << endl;
                getline(cin,newu.Uphone);
        }
    }
    else
    {
        cout << "Invalid Phone Number!, Try Again\n:";
        return GetUphone(newu);
    }
    string tmp;
    ifstream check;
    check.open("usersdata.txt");
    while(!datafile.fail() && !datafile.eof())
    {
        check >> tmp;
        size_t found = tmp.find(newu.Uphone);
        if(found != string::npos)
        {
            cout << "This Phone Number Already Exists!, Try Again\n";
            return GetUphone(newu);
        }
    }
    check.close();
=======
    getline(cin,newu.Uphone);
    if(newu.Uphone.size() == 11  || newu.Uphone.size() == 10)
    {
                while(!regex_match(newu.Uphone, regex("(01)(1|2|5|0)([0-9]+)")))
                {
                        cout << "Invalid Phone Number !, Try Again\n:" << endl;
                        getline(cin,newu.Uphone);
                }
    }else
    {
            cout << "Invalid Phone Number !, Try Again\n:";
            return GetUphone(newu);
    }
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a

}
void GetUname(register_user& newu)
{
    getline(cin,newu.Uname);
    while (!regex_match(newu.Uname, regex("([_a-zA-Z]*)")))
<<<<<<< HEAD
    {
        cout << "Invalid User Name!, Try Again\n:";
        getline(cin,newu.Uname);

    }
}
string HidePass()
{
    string tmp; int i;
    char ch;   // char for holding each character temporarly
    for(i=0 ; ; ) // Infinite Loop
    {
        ch = getch();
        if(ch == 13) // If The User Enter Input Key
        {
            cout << endl;  // Newline
            break;        // Exit from the loop
        }
        else if(ch == 8 && i>0)  // If The User Input Backspace
        {
            cout << "\b \b"; // Go Back one step and hide one Asterik
            tmp.replace(i, 1, ""); // Remove last character in the string
            --i;
            tmp[i] = ' ';
        }

        if(ch >= 32)  // If The User Input Normal Character
        {
            cout << "*";  // print one more astrik
            tmp += " ";   // wide the string
            tmp[i] = ch;  // Put the char in the string
            ++i;          // Increment the index
        }
    }
    if(tmp[tmp.size()-1] == ' ')
        tmp.replace(tmp.size()-1, 1, "");  // Remove Space in the last of string
    return tmp;
}
void GetUPassword(register_user& newu)
{
    cout << "Please enter the Password: ";
    int c1=0, c2=0, c3=0;
    regex validPass("(([A-Z]|[a-z]|[0-9])+([:-@]|[ -/]|[\[-_]|[{-~])+([A-Z]|[a-z]|[0-9]|[:-@]|[ -/]|[\[-_]|[{-~])*)|(([:-@]|[ -/]|[\[-_]|[{-~])+([A-Z]|[a-z]|[0-9])+([:-@]|[ -/]|[\[-_]|[{-~]|[A-Z]|[a-z]|[0-9])*)");
    newu.Upassword = HidePass();
    for(char i: newu.Upassword)
    {
        if(isupper(i))  // Check if the user input at least one capital char
            c1++;
        else if(islower(i))  // Check if the user input at least one small char
            c2++;
        else if(isalnum(i))  // Check if the user input at least one Digit
            c3++;
    }
    char want;
    if((!c1||!c2||!c3)||!regex_match(newu.Upassword, validPass)|| newu.Upassword.size()<8)
    {
        cout << "The Password is week, You Should Enter Another One!\n";
        if(!c1) cout << "- at least one capital character is needed\n";
        if(!c2) cout << "- at least one Small character is needed\n";
        if(!c3) cout << "- at least one Digit is needed\n";
        if(!regex_match(newu.Upassword, validPass))
                cout << "- at least one special character is needed\n";
        if(newu.Upassword.size()<8)
                cout << "- The length of the password should be > 7\n";
        return GetUPassword(newu);
    }
    string checkPass;
    cout << "Enter The Password Again: ";
    checkPass = HidePass();
    while(checkPass != newu.Upassword)  // Check the Matching of the password
    {
        cout << "Enter The Password Again: ";
        checkPass = HidePass();
    }
=======
        {
            cout << "Invalid User Name !, Try Again\n:";
            getline(cin,newu.Uname);

        }
}
void GetUPassword(register_user& newu)
{
    getline(cin,newu.Upassword);
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a
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
<<<<<<< HEAD
                int emailfound =0 , idfound = 0;
=======
                int emailfound = 0 , idfound = 0;
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a
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

istream& operator>> (istream& in, register_user& i)
{
   cout << "Please enter the User Name: ";
   GetUname(i);
   cout << "Please enter the E-Mail: ";
   GetUemail(i);
   cout << "Please enter the User ID: ";
   GetUid(i);
<<<<<<< HEAD

   GetUphone(i);
   cout << "\nYour Password Should be at least 8 Char \n";
   cout << "and you can use a mixture of: [A-Z], [a-z]\n";
   cout << "and at least one special character, e.g.,!@#?][\n";
=======
   cout << "Please enter the Phone Number: ";
   GetUphone(i);
   cout << "Please enter the Password: ";
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a
   GetUPassword(i);
   return in;
}

<<<<<<< HEAD
void putToSystem()
{
    fstream Usys;
    Usys.open("UserSystem.txt", ios::app);
    Usys << "ID: " << newu.Uid << " | " << "Password: " << newu.Upassword << endl;
    Usys.close();
}
=======

>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a
void user_register()
{
    addinfo();
    datafile.open("usersdata.txt",ios::app);
    cin >> newu;
<<<<<<< HEAD
    putToSystem();
    cout << "Congratulations, your account has been successfully created";
    datafile << newu << endl;
    datafile.close();
=======
    cout << "Congratulations, your account has been successfully created";
    datafile << newu << endl;
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a

}


int main()
{
<<<<<<< HEAD
       user_register();
=======
        mainmessage();
>>>>>>> 6a20efaff336e4333f3482416288cb34d4f3bd9a
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
            return mainmessage();
        }

    }

}
