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
	SetWindowText(hwnd, _T("����ͶƱϵͳ 2.33"));
	loadimage(&img, _T("res/�˳�����png"), 1200, 700);
	putimage(0, 0, &img);
	system("Pause");
	return 0;
}







/*int i = MessageBox(NULL, L"����������˺Ż������������������룡", _T("�˺��������"), MB_OKCANCEL | MB_ICONHAND);
cout << i;
InputBox(no, 2, _T("Account"), _T("�˺�"), NULL, 0, 0, false);
user* new_user = new user(std::stoi(wchartostring(user_No, 2)), wchartostring(user_account, 10), wchartostring(user_password, 40));

*/