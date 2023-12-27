#include "summary.h"

void select_Identity() {//登录界面
	IMAGE img;
	initgraph(1200, 700);
	HWND hwnd;// 设置窗口句柄变量保存窗口信息
	hwnd = GetHWnd();// 获取窗口句柄
	SetWindowText(hwnd, _T("电子投票系统 2.0"));
	loadimage(&img, _T("登录界面.png"), 1200, 700);
	putimage(0, 0, &img);
	//鼠标点击事件监听
	MOUSEMSG msg;// 定义变量，保存鼠标消息
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区	
	while (1) { // 主循环 循环监听鼠标信息
		while (MouseHit())// 监听鼠标信息 当有鼠标消息的时候执行 可检测连续的鼠标信息
		{
			msg = GetMouseMsg();// 获取鼠标消息
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 961 && msg.y >= 245 && msg.y <= 273) {
				//管理员登录
				admin_System_Login();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 961 && msg.y >= 315 && msg.y <= 340) {
				//投票人登录
				closegraph();
				user_System_Login();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 871 && msg.y >= 378 && msg.y <= 405) {
				//退出
				closegraph();
				goto label;
			}
		}
	}
label:return;
}

void admin_System_Panel() {
	IMAGE img;
	initgraph(1200, 700);//宽、高
	loadimage(&img, _T("管理员菜单.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("电子投票系统系统 2.0"));
labelStart:
	MOUSEMSG msg;// 定义变量，保存鼠标消息
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1060 && msg.y >= 240 && msg.y <= 272) {
				//初始化候选人信息
				closegraph();
				init_candidates_information();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 970 && msg.y >= 306 && msg.y <= 335) {
				//浏览候选人信息
				closegraph();
				scan_candidates_information(1);
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 970 && msg.y >= 374 && msg.y <= 405) {
				//修改投票人信息
				closegraph();
				modify_candidates_panel();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1000 && msg.y >= 444 && msg.y <= 469) {
				//查询投票情况
				closegraph();
				/*FindInformation();*/
				scan_candidates_information(2);
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1000 && msg.y >= 505 && msg.y <= 536) {
				//投票信息清零
				MessageBox(hwnd, _T("现在清除成功啦！QAQ"), _T("清除成功"), MB_OK);
				clear_vote_information();
				admin_System_Panel();
				/*ProcessingData();*/
				goto labelTeachersMenu;
			}

			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 1000 && msg.y >= 569 && msg.y <= 606) {
				//更改用户权限
				closegraph();
				user_manager_panel();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 874 && msg.y >= 642 && msg.y <= 670) {
				//退出系统
				closegraph();
				select_Identity();
				goto labelTeachersMenu;
			}
		}
	}
labelTeachersMenu:
	return;
}

void user_manager_panel() {
	IMAGE img;
	initgraph(1200, 700);//宽、高
	loadimage(&img, _T("更改用户权限.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("电子投票系统系统 2.0"));
labelStart:
	MOUSEMSG msg;// 定义变量，保存鼠标消息
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 991 && msg.y >= 244 && msg.y <= 270) {
				//初始化新用户
				closegraph();
				init_new_user();
				user_manager_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 1027 && msg.y >= 306 && msg.y <= 337) {
				//更改用户Setting
				closegraph();
				change_user_setting();
				user_manager_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 371 && msg.y <= 403) {
				//增加用户
				closegraph();
				add_user_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 442 && msg.y <= 470) {
				//删除用户
				closegraph();
				delete_user();
				/*FindInformation();*/
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 506 && msg.y <= 536) {
				//查询用户
				query_user_panel();
				/*ProcessingData();*/
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 814 && msg.x <= 879 && msg.y >= 568 && msg.y <= 604) {
				//排序
				closegraph();
				sort_user_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 808 && msg.x <= 875 && msg.y >= 634 && msg.y <= 671) {
				closegraph();
				admin_System_Panel();
				goto labelAdminMenu;
			}
		}
	}
labelAdminMenu:
	return;
}

void user_System_Panel() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("投票人菜单.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 809 && msg.x <= 878 && msg.y >= 236 && msg.y <= 274) {
				//投票	
				user_vote();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 810 && msg.x <= 1030 && msg.y >= 302 && msg.y <= 344) {
				//浏览投票人信息
				scan_candidates_information(1);
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 813 && msg.x <= 882 && msg.y >= 369 && msg.y <= 409) {
				//推出
				select_Identity();
				goto label;
			}
		}

	}
label:return;
}