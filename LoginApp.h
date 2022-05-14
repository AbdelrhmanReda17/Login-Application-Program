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
