#pragma once
//所有的库文件
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//其他self-headfile
#include "candidates.h"

//函数声明
void Begin();
void printLine();
void select_Identity();
void admin_System_Login();
void voter_System_Login();
void exit_System();
bool judeg_Admin(const string& account, const string& password);
void admin_System_Panel();
void admin_System_Login_Error();
void admin_System_Login_Error1();