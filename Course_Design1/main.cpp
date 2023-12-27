#include "summary.h"
#pragma warning(disable:4996)
#define version 2.0
#define nameNum 10


int main() {

	Begin();
	select_Identity();
	IMAGE img;
	initgraph(1200, 700);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("电子投票系统 2.33"));
	loadimage(&img, _T("res/退出界面png"), 1200, 700);
	putimage(0, 0, &img);
	system("Pause");
	return 0;
}







/*int i = MessageBox(NULL, L"您所输入的账号或密码有误，请重新输入！", _T("账号密码错误"), MB_OKCANCEL | MB_ICONHAND);
cout << i;
InputBox(no, 2, _T("Account"), _T("账号"), NULL, 0, 0, false);
user* new_user = new user(std::stoi(wchartostring(user_No, 2)), wchartostring(user_account, 10), wchartostring(user_password, 40));

*/