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
#include <conio.h>

using namespace std;
int mainmessage();
//--------------------------------------------------
//                     Global Objects
//--------------------------------------------------
fstream datafile;
map<string,string> userCheck;
map<string,string> LoginCheck;
string user_password="";
static int checker = 0; // Function CheckPassword in login operator

struct login_user
{
    string UserID;
    string UserPass;
} loginu;

struct register_user
{
    string Uname;
    string Uemail;
    string Uid;
    string Uphone;
    string Upassword;
} newu;
//              Functions
void CheckId(login_user& loginu);
void CheckPassword(login_user& loginu);
void GetUemail(register_user& newu);
void GetUphone(register_user& newu);
void GetUname(register_user& newu);
string HidePass();
void addinfo();
void GetUid(register_user& newu);
void GetUPassword(register_user& newu);
void user_register();
void mainmessege();
void changepassword(login_user& loginu);
void afterlogin();
void loaduser();
void user_login();
void Newpassword(login_user& loginu);
void newfile(login_user& loginu,string );


//--------------------------------------------------
//                     OverLoading
//--------------------------------------------------

//             [1] Over Load On << to struct login user

ostream& operator<< (ostream& out ,login_user& i)
{
    out << "ID:" << i.UserID ;
    out << " | Password:" <<  i.UserPass;
    return out;
}

//             [2] Over Load On >> to struct login user

istream& operator>> (istream& in, login_user& i)
{
   cout << "Please enter the User ID: ";
   CheckId(i);
   cout << "Please enter the Password:";
   CheckPassword(i);
   return in;
}
//             [3] Over Load On << to struct register_user

ostream& operator<< (ostream& out ,register_user& i)
{
   string encrypt = "";
    out << "NAME:" << i.Uname ;
    out << " | E-Mail:" << i.Uemail ;
    out << " | ID:" << i.Uid ;
    out << " | Phone Number:" << i.Uphone ;
    for (int x = 0 ; x < i.Upassword.size() ; x++)
    {
        i.Upassword[x] = char(i.Upassword[x]+1);
    }
    out << " | Password:" <<  i.Upassword << " ";
    return out;
}

//             [4] Over Load On >> to struct register_user

istream& operator>> (istream& in, register_user& i)
{
   cout << "Please enter the User Name: ";
   GetUname(i);
   cout << "Please enter the E-Mail: ";
   GetUemail(i);
   cout << "Please enter the User ID: ";
   GetUid(i);
   GetUphone(i);
   cout << "\nYour Password Should be at least 8 Char \n";
   cout << "and you can use a mixture of: [A-Z], [a-z]\n";
   cout << "and at least one special character, e.g.,!@#?][\n]";
   GetUPassword(i);
   return in;
}

//--------------------------------------------------
//             int Main Function
//--------------------------------------------------

int main()
{
       mainmessage();
}

//--------------------------------------------------
//             Main Message Function
//--------------------------------------------------

int mainmessage()
{
    string choosing;
    while(true)
    {
          cout  << "[1] Login \n"
                << "[2] Register \n"
                << "[3] Forget Password\n"
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
            return mainmessage();
        }

    }

}

//--------------------------------------------------
//             Login Main Function
//--------------------------------------------------

void user_login()
{
    checker = 0;
    loaduser();
    cin >> loginu;
}
//--------------------------------------------------
//             Login User Functions
//--------------------------------------------------

//             [1] Load Users

void loaduser() // this function to load id and password of users from (usersdata.txt) file and add it into map
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
                string password="" , id = "";
                int passwordfound = 0 , idfound = 0;
                if (line.find("| Password") != std::string::npos)
                    passwordfound = line.find("| Password")+11;
                while(line[passwordfound] != ' ')
                {
                    password+= line[passwordfound];
                    passwordfound++;
                }
                if (line.find("| ID") != std::string::npos)
                    idfound = line.find("| ID") + 5;
                while(line[idfound] != ' ')
                {
                    id+= line[idfound];
                    idfound++;
                }
                LoginCheck.insert({ id , password });
            }
        }
    }
    myStream.close();
}

//             [2] Check ID

void CheckId(login_user& loginu) // This function is used to  Check if the user add an Exist Id
{
    getline(cin,loginu.UserID);
    map<string,string>::iterator it;
    it = LoginCheck.find(loginu.UserID);
    if( it == LoginCheck.end())
    {
        cout << "Invalid ID" << endl;
        cout << "Please enter the User ID: ";
        return CheckId(loginu);
    }
    else
    {
        user_password = it->second; //set the variable  equal to the User  Correct Password.
    }
}

//             [3] Check Password

void CheckPassword(login_user& loginu) // This function is used to  Check if the user add an  the correct password.
{
        bool success = false;
        loginu.UserPass = HidePass(); // calling function hide pass to hide the password that the user add
        for (int x = 0 ; x < loginu.UserPass.size() ; x++) // 332 ~ 335 -> Encrypt the input Password
        {
            loginu.UserPass[x] = char(loginu.UserPass[x]+1);
        }
        if ( checker < 3) // check if the user don't lose  his three trials
        {

                    if( user_password == loginu.UserPass) //check if the entry password is correct
                    {
                        success = true; // make success == true
                    }
                    else// if the Entry password wrong
                    {
                        checker += 1; // increment the checker
                        cout << "Failed To Login , You have " << 3-checker << " Trials Left" << endl;
                        cout << "Please enter the Correct Password: ";
                        return CheckPassword(loginu); // return the function
                    }

        }
        else if(checker >= 3 && success == false) // if the user lose his trials and password is still wrong
            {
                        cout << "Access Denied to the system\n";
            }
        if(success == true) // if the user add the password correct
        {
                string line;
                string name = "";
                string filename = "usersdata.txt";
                ifstream myStream(filename);
                while(!myStream.fail() && !myStream.eof()) //code from 362 ~ 386 to get the user name of the user from the file.
                {
                        while(getline(myStream, line)) // take every line as string
                        {
                            int namefound = 0 ; // name counter
                            if (line.find(loginu.UserID)!= std::string::npos) //to get the line that belong to correct user.
                                {
                                    if (line.find("NAME:") != std::string::npos) // then start to find Name:
                                        namefound = line.find("NAME:") + 5; // we increment 5 to get the first letter in the name.
                                    while(line[namefound] != ' ') // start append the name until it found space
                                    {
                                        name+= line[namefound];
                                        namefound++;
                                    }
                                }
                        }
                }
                sleep(1);
                system("CLS");
                cout << "Successful login, Welcome "<< name <<endl; //print successful login and welcome to the user.
                afterlogin();
        }
}
//--------------------------------------------------
//             After Login Function
//--------------------------------------------------

//             [1] After Login [Main Function]

void afterlogin()
{
    string choosing;
    while(true)
    {
          cout  << "[1] Change Password \n"
                << "[2] Log Out and Return to Main Menu  \n"
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
            changepassword(loginu);
        }
        else if (choosing == "2")
        {
            sleep(1);
            system("CLS");
            break;
            cout << "Successfully Log Out.\n";
        }
        else
        {
            sleep(1);
            system("CLS");
            cout << "Wrong Choose !!" << endl;
            return  afterlogin();
        }

    }
}

//             [2] change password [Check Old Password]

void changepassword(login_user& loginu)
{
    string oldpassword="";
    cout << "Enter the Old Password :";
    oldpassword = HidePass();
    for (int x = 0 ; x < oldpassword.size() ; x++) // 332 ~ 335 ->  cipher the user Password
    {
        oldpassword[x] = char(oldpassword[x]+1);
    }
    while(oldpassword != loginu.UserPass)
    {
        cout << "Incorrect Password ,Try Again ! :";
        oldpassword = HidePass();
    }
    Newpassword(loginu);
}

//             [3] new password [Get new Password]

void Newpassword(login_user& loginu)
{
    string newpassword="",encyptpassword="";
    cout << "Please enter the New Password: ";
    newpassword = HidePass();
    encyptpassword = newpassword;
    for (int x = 0 ; x < encyptpassword.size() ; x++) // 332 ~ 335 ->  cipher the user Password
    {
        encyptpassword[x] = char(encyptpassword[x]+1);
    }
    int c1=0, c2=0, c3=0;
    regex validPass("(([A-Z]|[a-z]|[0-9])+([:-@]|[ -/]|[\[-_]|[{-~])+([A-Z]|[a-z]|[0-9]|[:-@]|[ -/]|[\[-_]|[{-~])*)|(([:-@]|[ -/]|[\[-_]|[{-~])+([A-Z]|[a-z]|[0-9])+([:-@]|[ -/]|[\[-_]|[{-~]|[A-Z]|[a-z]|[0-9])*)");
    for(char i: newpassword)
    {
        if(isupper(i))  // Check if the user input at least one capital char
            c1++;
        else if(islower(i))  // Check if the user input at least one small char
            c2++;
        else if(isalnum(i))  // Check if the user input at least one Digit
            c3++;
    }
    char want;
    if((!c1||!c2||!c3)||!regex_match(newpassword, validPass)|| newpassword.size()<8 || encyptpassword == loginu.UserPass)
    {
        cout << "The Password is week, You Should Enter Another One!\n";
        if(!c1) cout << "- at least one capital character is needed\n";
        if(!c2) cout << "- at least one Small character is needed\n";
        if(!c3) cout << "- at least one Digit is needed\n";
        if(!regex_match(newpassword, validPass))
                cout << "- at least one special character is needed\n";
        if(newpassword.size()<8)
                cout << "- The length of the password should be > 7\n";
        if (encyptpassword == loginu.UserPass)
                cout << "You Enter the same password !!\n";
        return Newpassword(loginu);
    }
    string checkPass;
    cout << "Enter The New Password Again: ";
    checkPass = HidePass();
    cout << checkPass << " " << newpassword<<endl;
    while(checkPass != newpassword)  // Check the Matching of the password
    {
        cout << "Enter The New Password Again: ";
        checkPass = HidePass();
    }
    newfile(loginu,encyptpassword);
}

//             [4] new file [change password on file]

void newfile(login_user& loginu,string newpassword)
{
    char ch;
    string file_contents = "";
    datafile.open("usersdata.txt", ios::in);
    while ( datafile >> std::noskipws >> ch)
    {
        file_contents += ch;
    }
    string::size_type foundpass;
    string::size_type foundid;
    foundid = file_contents.find(loginu.UserID);

    if (foundid!=std::string::npos)
    {
        foundpass = file_contents.find(loginu.UserPass);
        if (foundpass != std::string::npos)
        {
            file_contents.replace(foundpass,loginu.UserPass.size(),newpassword);
        }
    }
    datafile.close();
    datafile.open("usersdata.txt", ios::out | ios::trunc);
    datafile << file_contents;
    datafile.close();
    LoginCheck.clear();
    loaduser();
    sleep(1);
    system("CLS");
    cout << "Password Changed Successfully,\n";
    mainmessage();
}


//--------------------------------------------------
//             Register Main Function
//--------------------------------------------------

void user_register()
{
    addinfo();
    datafile.open("usersdata.txt",ios::app);
    cin >> newu;
    cout << "Congratulations, your account has been successfully created";
    datafile << newu << endl;
    datafile.close();

}

//--------------------------------------------------
//             Register User Functions
//--------------------------------------------------

//             [1] Upload all the information from the users data file and add it into map

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
                string email="",id="";
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

//             [2] Get User Name

void GetUname(register_user& newu)
{
    getline(cin,newu.Uname);
    while (!regex_match(newu.Uname, regex("([_a-zA-Z]*)")))
    {
        cout << "Invalid User Name!, Try Again\n:";
        getline(cin,newu.Uname);

    }
}

//
//             [3] Get Email

void GetUemail(register_user& newu)
{
    map<string,string>::iterator it;
    getline(cin,newu.Uemail);
    regex valid_email("((([!--]|[A-z]|[0-9])+(\.)?([!--]|[A-z]|[0-9])+[@])|(([!--]|[A-z]|[0-9])+[@]))((([A-z]*[0-9]*[A-z]+[0-9]*)+[-]?([A-z]*[0-9]*[A-z]+[0-9]*))|([A-z]*[0-9]+[A-z]*[-]?[0-9]*[A-z]+[0-9]*)|([0-9]*[A-z]+[0-9]*[-]?[A-z]*[0-9]+[A-z]*)|([A-z]))+(\.)[A-Za-z]+");
    while (!regex_match(newu.Uemail, valid_email))
    {
        cout << "Invalid E-Mail !";
        cout << "Please enter the E-Mail: ";
        getline(cin,newu.Uemail);

    }
    for(it = userCheck.begin(); it != userCheck.end(); it++)
    {
        if( it->second == newu.Uemail)
        {
            cout << "Email Already Exists!, Try Again\n:";
            return GetUemail(newu);
        }
    }
}

//             [4] Get Phone Number

void GetUphone(register_user& newu)
{
    cout << "Please enter Phone Number: ";
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


}
//             [5] Get Password

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
}

//             [6] Get ID

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

//          [4] Hide Pass

string HidePass() // this function to make * while the user enter the password.
{
    string tmp; int i; char ch;   // char for holding each character temporarily
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
            cout << "\b \b"; // Go Back one step and hide one Asterisk
            tmp.replace(i, 1, ""); // Remove last character in the string
            --i;
            tmp[i] = ' ';
        }

        if(ch >= 32)  // If The User Input Normal Character
        {
            cout << "*";  // print one more asterisk
            tmp += " ";   // wide the string
            tmp[i] = ch;  // Put the char in the string
            ++i;          // Increment the index
        }
    }
    if(tmp[tmp.size()-1] == ' ')
        tmp.replace(tmp.size()-1, 1, "");  // Remove Space in the last of string
    return tmp;
}

