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
#include <sstream>
#include <queue>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <WinUser.h>
using namespace std;

//其他self-headfile
#include "candidates.h"
#pragma warning(disable:4996)
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
void add_admin(string, string);
void delete_new_user(int number, user* head);
void user_System_Panel();
void user_System_Login_Error();
void user_System_Login();
void wcharTochar(const wchar_t* wchar, char* chr, int length);
void charTowchar(const char* chr, wchar_t* wchar, int size);
std::string charArrayToString(const char* charArray);
void first_admin_create(HWND hwnd);
void verify_login(fstream& test, HWND hwnd);
string wchartostring(const wchar_t* wchar, int length);
void clear_vote_information();
void user_manager_panel();
user* init_user(int& n);
char* stringToCharArray(const std::string& str);
wchar_t* stringToWideCharArray(const std::string& str);
void verify_login_user(fstream& test, HWND hwnd);
void user_vote1(int);
void scan_candidates_information(int);
void init_candidates_information();
void modify_candidates_panel();
void user_vote();
void init_new_user();
void change_user_setting();
void add_user_panel();
void delete_user();
void query_user_panel();
void sort_user_panel();