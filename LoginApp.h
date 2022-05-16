
#ifndef LOGINAPP_H
#define LOGINAPP_H

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
//--------------------------------------------------
//                     Global Objects
//--------------------------------------------------


//          Structs

struct login_user
{
    string UserID;
    string UserPass;
};

struct register_user
{
    string Uname;
    string Uemail;
    string Uid;
    string Uphone;
    string Upassword;
};

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


#endif // LOGINAPP_H
