#include "summary.h"
#define number_of_candidates n

//void init_candidates_information() {
//	ofstream fout; //写入文件
//	fout.open("Data/voter1.txt", ios::out);
//	if (!fout.is_open()) {
//		std::cerr << "无法打开文件！Sorry ~.~" << std::endl;
//	}
//	//std::cout << std::left << std::setw(8) << "编号" << std::setw(15) << "姓名"
//	//	<< std::setw(10) << "简介" << std::setw(8) << "支持人数" << std::endl;
//	string input;
//	int n = 0;	//选举个数
//	getchar();
//	fout << n << endl;
//	while (1) {
//		std::getline(std::cin, input);
//		if (input.empty()) {
//			break;
//		}
//		n++;
//		fout << input << std::endl;
//	}
//	fout.seekp(0);  // 将文件指针移到文件开头
//	fout << n;
//	fout.close();
//	std::cout << "数据写入成功hhh！" << std::endl;
//}

//void init_new_user() {
//	ofstream fout("Data/user.txt", std::ios::out);
//	if (!fout.is_open())
//		std::cerr << "无法打开文件！Sorry ~.~" << std::endl;
//	string input;
//	int n = 0;	//投票人个数
//	getchar();	//吸收缓存区空格字符
//	fout << n << endl;
//	while (1) {
//		getline(std::cin, input);
//		if (input.empty())
//			break;
//		n++;
//		fout << input << std::endl;
//	}
//	fout.seekp(0);
//	fout << n;
//	fout.close();
//}

void init_new_user() {//1-录入用户信息
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("初始化新用户.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	int usercount = 0;
	user* head = (user*)malloc(sizeof(user));
	head->next = NULL;
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 936 && msg.y >= 244 && msg.y <= 271) {
				while (1) {
					//开始录入
					/*candidates* new_candidates = (candidates*)malloc(sizeof(candidates));
					if (new_candidates == NULL) {
						printf("内存开辟失败！");
						exit(1);
					}*/
					wchar_t user_No[2];
					wchar_t user_account[10];
					wchar_t user_password[40];
					int i;
					i = InputBox(user_No, 2, _T("请输入【编号】"), _T("test"), NULL, 0, 0, false);
					if (i == true) {
						InputBox(user_account, 10, _T("账号"), _T("test"), NULL, 0, 0, true);
						InputBox(user_password, 40, _T("密码"), _T("test"), NULL, 0, 0, true);
						user* new_user = new user(std::stoi(wchartostring(user_No, 2)), wchartostring(user_account, 10), wchartostring(user_password, 40));
						/*new_candidates->setNo(std::stoi(wchartostring(Candidates_No, 2)));
						cout << new_candidates->getNo();
						new_candidates->setName(wchartostring(Candidates_Name, 10));
						cout << new_candidates->getName();
						new_candidates->setResume(wchartostring(Candidates_Resume, 40));
						cout << "YES4";*/
						//wcharTochar(TempName, new_stu->students.name, nameNum);
						//wcharTochar(TempSex, new_stu->students.sex, 10);
						//wcharTochar(TempID, new_stu->students.ID, 40);
						//wcharTochar(_T("123456"), new_stu->students.password, 40);
						new_user->next = head->next;
						head->next = new_user;
						usercount++;
					}
					else if (i == false) {
						ofstream fout("Data/user.txt", std::ios::out);
						fout << usercount << endl;
						while (head->next != NULL) {
							fout << head->next->getNo() << " " << head->next->getAccount() << " " << head->next->getPassword() << endl;
							head = head->next;
						}
						fout.close();
						closegraph();
						//user_manager_panel();
						goto labelInputInformation;
					}
				}

			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 966 && msg.y >= 305 && msg.y <= 333) {
				closegraph();
				admin_System_Panel();
				goto labelInputInformation;
			}
		}
	}
labelInputInformation:
	return;
}

void init_candidates_information() {//1-录入学生信息
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("初始化候选人.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	int votercount = 0;
	candidates* head = (candidates*)malloc(sizeof(candidates));
	head->next = NULL;
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 937 && msg.y >= 236 && msg.y <= 267) {
				while (1) {
					//开始录入
					/*candidates* new_candidates = (candidates*)malloc(sizeof(candidates));
					if (new_candidates == NULL) {
						printf("内存开辟失败！");
						exit(1);
					}*/
					wchar_t Candidates_No[2];
					wchar_t Candidates_Name[10];
					wchar_t Candidates_Resume[40];
					int i;
					i = InputBox(Candidates_No, 2, _T("请输入【编号】"),_T("test"), NULL, 0, 0, false);
					if (i == true) {
						InputBox(Candidates_Name, 10, _T("姓名"), _T("test"), NULL, 0, 0, true);
						InputBox(Candidates_Resume, 40, _T("简历"), _T("test"), NULL, 0, 0, true);
						candidates* new_candidates = new candidates(std::stoi(wchartostring(Candidates_No, 2)), wchartostring(Candidates_Name, 10), wchartostring(Candidates_Resume, 40));
						/*new_candidates->setNo(std::stoi(wchartostring(Candidates_No, 2)));
						cout << new_candidates->getNo();
						new_candidates->setName(wchartostring(Candidates_Name, 10));
						cout << new_candidates->getName();
						new_candidates->setResume(wchartostring(Candidates_Resume, 40));
						cout << "YES4";*/
						//wcharTochar(TempName, new_stu->students.name, nameNum);
						//wcharTochar(TempSex, new_stu->students.sex, 10);
						//wcharTochar(TempID, new_stu->students.ID, 40);
						//wcharTochar(_T("123456"), new_stu->students.password, 40);
						new_candidates->next = head->next;
						head->next = new_candidates;
						votercount++;
					}
					else if (i == false) {
						ofstream fout("Data/voter1.txt", std::ios::out);
						fout << votercount << endl;
						while (head->next != NULL) {
							fout << head->next->getNo() << " " << head->next->getName() << " " << head->next->getResume() << " 0" << endl;
							head = head->next;
						}
						fout.close();
						closegraph();
						admin_System_Panel();
						goto labelInputInformation;
					}
				}

			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 966 && msg.y >= 305 && msg.y <= 333) {
				closegraph();
				admin_System_Panel();
				goto labelInputInformation;
			}
		}
	}
labelInputInformation:
	return;
}

void modify_candidates_panel() {//1-录入用户
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("修改候选人.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 937 && msg.y >= 236 && msg.y <= 267) {
				fstream in("Data/voter1.txt", std::ios::in);
				wchar_t candidates_No[2];
				InputBox(candidates_No, 2, _T("编号"), _T("你想要修改的编号"), NULL, 0, 0, true);

				int modify_candidate = std::stoi(wchartostring(candidates_No, 2));
				cout << modify_candidate << endl;
				int n;	//表示选举人个数
				std::stringstream content;
				in >> n;
				content << n << endl;
				for (int i = 1; i <= n; i++) {
					int no, mount;
					string name, resume;
					in >> no >> name >> resume >> mount;
					if (no == modify_candidate) {
						wchar_t  resume_t[40];
						InputBox(resume_t, 40, _T("简历"), _T("输入你想要修改的简历"), NULL, 0, 0, true);
						resume = wchartostring(resume_t, 40);
					}
					content << no << " " << name << " " << resume << " " << mount << endl;
				}
				in.close();
				ofstream fout("Data/voter1.txt");
				fout << content.str();
				fout.close();
				closegraph();
				modify_candidates_panel();
				goto labelInputInformation;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 966 && msg.y >= 305 && msg.y <= 333) {
				closegraph();
				admin_System_Panel();
				goto labelInputInformation;
			}
		}
	}
labelInputInformation:
	return;
}


candidates* browse_candidates_information(int &n) {	//用&可以只声明就引入，在函数内部给n赋值
	fstream in("Data/voter1.txt", std::ios::in);	//从文件中输入->变量
	in >> n;
	candidates *voter = new candidates[n + 1];
	for (int i = 1; i <= n; i++) {
		int no, mount;
		string name, resume;
		in >> no >> name >> resume >> mount;
		voter[i].setNo(no);
		voter[i].setName(name);
		voter[i].setResume(resume);
		voter[i].setMount(mount);
	}
	in.close();

	return voter;
}

void change_user(int no) {
	fstream in("Data/user.txt", std::ios::in);
	stringstream input;
	int n;
	in >> n;
	input << n << endl;
	for (int i = 1; i <= n; i++) {
		int number;
		string account, password;
		in >> number >> account >> password;
		if (number == no) {
			wchar_t _password[20];
			InputBox(_password, 20, _T("Password"), _T("密码"), NULL, 0, 0, false);
			password = wchartostring(_password, 20);
			int i = MessageBox(NULL, L"权限", _T("是否升级为管理员？"), MB_OKCANCEL | MB_ICONHAND);
			if (i == 1) {
				add_admin(account, password);
			}
		}
		input << number << " " << account << " " << password << endl;
	}
	in.close();
	ofstream fout("Data/user.txt", std::ios::out);
	fout << input.str();
	fout.close();
}

void change_user_setting() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("更改用户Setting.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 993 && msg.y >= 240 && msg.y <= 268) {
				/*modify_candidates_information();*/
				wchar_t no[2];
				InputBox(no, 2, _T("Number"), _T("编号"), NULL, 0, 0, true);
				change_user(stoi(wchartostring(no, 2)));
				change_user_setting();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 967 && msg.y >= 307 && msg.y <= 337) {
				user_manager_panel();
				goto label;
			}
		}
	
	}
label:return;
}

void delete_user() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("删除用户.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 993 && msg.y >= 240 && msg.y <= 268) {
				/*modify_candidates_information();*/
				wchar_t no[2];
				InputBox(no, 2, _T("Number"), _T("编号"), NULL, 0, 0, true);
				int n;
				user* head = init_user(n);
				delete_new_user(std::stoi(wchartostring(no, 2)), head);
				delete_user();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 967 && msg.y >= 307 && msg.y <= 337) {
				user_manager_panel();
				goto label;
			}
		}

	}
label:return;
}


void add_new_user(int no, string account, string password) {
	ofstream fout("Data/user.txt", std::ios::app);
	user user(no, account, password);
	fout << user;
	fout.close();
}

void delete_new_user(int number, user* head) {

	ifstream in("Data/user.txt", std::ios::in);
	int n;
	in >> n;
	in.close();
	ofstream fout("Data/user.txt", std::ios::out);
	fout << n - 1 << endl;
	for (int i = 1; i <= n; i++) {
		if (i == number)
			continue;
		fout << head[i].getNo() << " " << head[i].getAccount() << " " << head[i].getPassword() << endl;
	}
	fout.close();
}

user* init_user(int& n) {
	ifstream in("Data/user.txt", std::ios::in);
	if (in) {	//代表文件存在
		in >> n;
		if (n == 0) {	//代表文件内容为空
			user* u1 = new user();
			u1->setNo(0x3f3f3f3f);
			in.close();
			return u1;
		}
		else {
			user* u1 = new user[n + 1];
			for (int i = 1; i <= n; i++) {
				int no; 
				string account, password;
				in >> no >> account >> password;
				u1[i].setNo(no); u1[i].setAccount(account); u1[i].setPassword(password);
			}
			in.close();
			return u1;
		}
	}
}


void add_user_panel() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("增加用户.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 812 && msg.x <= 1024 && msg.y >= 238 && msg.y <= 272) {
				/*modify_candidates_information();*/
				wchar_t no[2], account[20], password[20];
				InputBox(no, 2, _T("Number"), _T("编号"), NULL, 0, 0, true);
				InputBox(account, 20, _T("Account"), _T("账号"), NULL, 0, 0, true);
				InputBox(password, 20, _T("Password"), _T("密码"), NULL, 0, 0, true);
				add_new_user(std::stoi(wchartostring(no, 2)), wchartostring(account, 20), wchartostring(password, 20));
				add_user_panel();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 810 && msg.x <= 966 && msg.y >= 307 && msg.y <= 342) {
				user_manager_panel();
				goto label;
			}
		}

	}
label:return;
}

void search_user(int number, user* head, HWND hwnd) {

	ifstream in("Data/user.txt");
	int n;
	in >> n;
	for (int i = 1; i <= n; i++) {
		int no;
		string account, password;
		in >> no >> account >> password;
		if (number == no) {
			wchar_t title[40], content[40];
			_stprintf_s(title, _T("编号: %d"), head[i].getNo());
			//解决string to char buffer too small 问题
			std::string account = head[i].getAccount();
			wchar_t* wideAccount = stringToWideCharArray(account);
			_stprintf_s(content, _countof(content), _T("用户名为: %ls"), wideAccount);
			MessageBox(hwnd, content, title, MB_OK);
			return;
		}
	}
}

void query_user_panel() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("查询用户.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 815 && msg.x <= 940 && msg.y >= 242 && msg.y <= 278) {
				/*modify_candidates_information();*/
				wchar_t no[2], account[20], password[20];
				InputBox(no, 2, _T("Number"), _T("编号"), NULL, 0, 0, true);
				int i;
				user* head = init_user(i);
				cout << i << endl;
				cout << head[0].getAccount() << endl;
				search_user(std::stoi(wchartostring(no, 2)), head, hwnd);
				query_user_panel();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 814 && msg.x <= 877 && msg.y >= 309 && msg.y <= 342) {
				user_manager_panel();
				goto label;
			}
		}

	}
label:return;
}
void selectSort(int number, user* head) {
	for (int i = 1; i <= number; i++) {
		int index = 1;
		for (int j = 2; j <= number - i + 1; j++) {
			if (head[j] > head[index])
				index = j;
		}
		user x;
		x = head[index];
		head[index] = head[number - i + 1];
		head[number - i + 1] = x;
	}
	ofstream fout("Data/user.txt");
	fout << number << endl;
	for (int i = 1; i <= number; i++)
		fout << head[i].getNo() << " " << head[i].getAccount() << " " << head[i].getPassword() << endl;
	fout.close();
}
void sort_user_panel() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("排序.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 812 && msg.x <= 911 && msg.y >= 136 && msg.y <= 188) {
				/*modify_candidates_information();*/
				MessageBox(hwnd, L"排序成功！", _T("恭喜恭喜"), MB_OK);
				int i;
				user* head = init_user(i);
				cout << i << endl;
				selectSort(i, head);
				sort_user_panel();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 813 && msg.x <= 970 && msg.y >= 240 && msg.y <= 279) {
				user_manager_panel();
				goto label;
			}
		}

	}
label:return;
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


//void user_manager_panel() {
//	system("cls");
//	cout << "1) 初始化新用户" << endl;
//	cout << "2) 更改用户Setting" << endl;
//	cout << "3) 增加用户" << endl;
//	cout << "4) 删除用户" << endl;
//	cout << "5) 查询用户" << endl;
//	cout << "6) 排序" << endl;
//	cout << endl;
//	printLine();
//	cout << endl;
//	cout << "> ";
//	int op;
//	cin >> op;
//	user* head;
//	int n;
//	head = init_user(n);
//	if (op == 1) {
//		init_new_user();
//	}
//	else if (op == 2) {
//		change_user_setting(head);
//	}
//	else if (op == 3) {
//		add_new_user();
//	}
//	else if (op == 4) {
//		cout << "输入你想要删除的编号" << endl;
//		cout << "> ";
//		int number;
//		cin >> number;
//		delete_new_user(number, head);
//	}
//	else if (op == 5) {
//		cout << "输入你想要查找的用户编号" << endl;
//		cout << "> ";
//		int number;
//		cin >> number;
//		search_user(number, head);
//	}
//	else if (op == 6) {
//		cout << n << endl;	
//		selectSort(n, head);
//	}
//}



void clear_vote_information() {
	fstream in("Data/voter1.txt", std::ios::in);
	int n;	//表示选举人个数
	std::stringstream content;
	in >> n;
	content << n << endl;
	for (int i = 1; i <= n; i++) {
		int no, mount;
		string name, resume;
		in >> no >> name >> resume >> mount;
		mount = 0;
		content << no << " " << name << " " << resume << " " << mount << endl;
	}
	in.close();
	ofstream fout("Data/voter1.txt");
	fout << content.str();
	fout.close();
}

void check_voting_status(int n, candidates* voter) {
	std::cout << std::left << std::setw(8) << "编号" << std::setw(15) << "姓名"
		<< std::setw(8) << "支持人数" << std::endl;
	for (int i = 1; i <= n; i++) {
		std::cout << std::left << std::setw(8) << voter[i].getNo() << std::setw(15) << voter[i].getName()
			 << std::setw(8) << voter[i].getMount() << std::endl;
	}
}

void display_voter(int n, candidates* voter) {
	std::cout << std::left << std::setw(8) << "编号" << std::setw(15) << "姓名"
		<< std::setw(10) << "简介" << std::endl;
	for (int i = 1; i <= n; i++) {
		std::cout << std::left << std::setw(8) << voter[i].getNo() << std::setw(15) << voter[i].getName()
			<< std::setw(10) << voter[i].getResume() << std::endl;
	}
}

void printLine() {
	cout << "---------------------------------------------------------" << endl;
}
//
//void Begin() {
//	printLine();
//	cout << endl;
//	cout << "\t Welcome to the Electronic Voting System 1.0" << endl;
//	cout << endl;
//	cout << "\t\t Author : Zhiwei Yu, Quyu Hao" << endl;
//	cout << endl;
//	printLine();
//}

void Begin() {//欢迎界面
	IMAGE img;
	initgraph(1200, 700);//宽、高
	loadimage(&img, _T("初始界面.png"), 1200, 700);//设置图片宽、高，若加载原图大小
	putimage(0, 0, &img);//图片显示的位置
	HWND hwnd;// 设置窗口句柄变量保存窗口信息
	hwnd = GetHWnd();// 获取窗口句柄
	SetWindowText(hwnd, _T("电子投票系统 2.0"));
	Sleep(2000);
	closegraph();
}

//这样直接引入不用复制，不被修改，节省时间，空间;

bool judge_Admin1(const string& account, const string& password) {
	int no;
	string verifyAccount, verifyPassword;
	ifstream in("Data/user.txt", ios::in);	//定义输入流
	int n;
	in >> n;
	while (in >> no >> verifyAccount >> verifyPassword) {
		if (account == verifyAccount && password == verifyPassword) {
			in.close();
			return true;
		}
	}
	in.close();
	return false;
}

bool judge_Admin(const string& account, const string& password) {
	string verifyAccount, verifyPassword;
	ifstream in("Data/admin.txt", ios::in);	//定义输入流
	while (in >> verifyAccount >> verifyPassword) {
		if (account == verifyAccount && password == verifyPassword) {
			in.close();
			return true;
		}
	}
	in.close();
	return false;
}

void add_admin(string account, string password) {
	ofstream fout("Data/admin.txt", std::ios::app);
	fout << endl << account << " " << password;
	fout.close();
}

//void select_Identity() {
//	system("cls");
//	printLine();
//	cout << endl;
//	cout << " Please select your identity :" << endl;
//	cout << "\t\t\t     （1）管理员" << endl;
//	cout << "\t\t\t     （2）投票人员" << endl;
//	cout << "\t\t\t     （3）退出" << endl;
//	cout << endl;
//	printLine();
//	cout << endl;
//	cout << "> ";
//	char x;
//	x = getchar();
//	if (x == 'a')
//		cout << "Test Over!" << endl;
//	if (x == '1')
//		admin_System_Login();
//	else if (x == '2')
//		user_System_Login(); 
//	else
//		exit_System();	//xx
//}
//
//void user_System_Login() {
//	system("cls");
//	string account, password;
//	cout << "Account :" << endl;
//	cout << "> ";
//	cin >> account;
//	cout << "Password :" << endl;
//	cout << "> ";
//	cin >> password;
//	if (judge_Admin1(account, password))
//		user_System_Panel();
//	else
//		user_System_Login_Error();
//}
//
//void user_System_Panel() {
//	printLine();
//	cout << endl;
//	cout << "1) 投票" << endl;
//	cout << "2) 浏览候选人信息" << endl;
//	cout << endl;
//	printLine();
//	cout << endl;
//	cout << "> ";
//	int op;
//	cin >> op;
//	if (op == 1) {
//		cout << "请输入你想要投票的编号)> ";
//		int n;
//		cin >> n;
//		user_vote(n);
//	}
//	else if (op == 2) {
//		int n;
//		candidates* voter = browse_candidates_information(n);
//		display_voter(n, voter);
//	}
//		
//}

void user_System_Login() {
		IMAGE img;
		initgraph(1200, 700);//宽、高
		loadimage(&img, _T("投票人登录.png"), 1200, 700);
		putimage(0, 0, &img);
		HWND hwnd;
		hwnd = GetHWnd();
		SetWindowText(hwnd, _T("电子投票系统 2.0"));
		fstream test("Data/admin.txt", std::ios::in);
		if (!test.is_open()) {
			int i = MessageBox(hwnd, _T("文件打不开"), _T("没有用户存在"), MB_OK);
			if (i == true)
				select_Identity();
		}
		else {
			verify_login_user(test, hwnd);
		}
}


void user_vote() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("投票.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 1054 && msg.y >= 239 && msg.y <= 274) {
				/*modify_candidates_information();*/
				wchar_t no[2];
				InputBox(no, 2, _T("Account"), _T("账号"), NULL, 0, 0, false);
				int number = std::stoi(wchartostring(no, 2));
				MessageBox(NULL, L"投票成功", _T("恭喜恭喜"), MB_OK);
				user_vote1(number);
				user_vote();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 806 && msg.x <= 879 && msg.y >= 306 && msg.y <= 343) {
				user_System_Panel();
				goto label;
			}
		}

	}
label:return;
}

void user_vote1(int number) {
	fstream in("Data/voter1.txt", std::ios::in);
	std::stringstream content;
	int n;
	in >> n;
	content << n << endl;
	for (int i = 1; i <= n; i++) {
		int no, mount;
		string name, resume;
		in >> no >> name >> resume >> mount;
		if (i == number) mount++;
		content << no << " " << name << " " << resume << " " << mount << endl;
	}
	in.close();
	ofstream fout("Data/voter1.txt");
	fout << content.str();
	fout.close();
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


void verify_login_user(fstream& test, HWND hwnd) {
	wchar_t account[20], password[20];
	if (InputBox(account, 20, _T("Account"), _T("账号"), NULL, 0, 0, false)) {
		InputBox(password, 20, _T("Password"), _T("密码"), NULL, 0, 0, false);
		if (judge_Admin1(wchartostring(account, 20), wchartostring(password, 20))) {
			user_System_Panel();
		}
		else {
			MessageBox(hwnd, L"您所输入的账号或密码有误，请重新输入！", _T("账号密码错误"), MB_OK | MB_ICONHAND);
			verify_login(test, hwnd);
		}
	}
	else {
		select_Identity();
	}

}

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


void user_System_Login_Error() {
	cout << "抱歉，账号密码错误" << endl;
}

void exit_System() {

}

void admin_System_Login() {
	IMAGE img;
	initgraph(1200, 700);//宽、高
	loadimage(&img, _T("管理员登录.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("电子投票系统 2.0"));
	fstream test("Data/admin.txt",std::ios::in);
	if (!test.is_open()) {
		first_admin_create(hwnd);
	}
	else {
		verify_login(test, hwnd);
	}
}

void verify_login(fstream& test, HWND hwnd) {
	wchar_t account[20], password[20];
	if (InputBox(account, 20, _T("Account"), _T("账号"), NULL, 0, 0, false)) {
		InputBox(password, 20, _T("Password"), _T("密码"), NULL, 0, 0, false);
		if (judge_Admin(wchartostring(account, 20), wchartostring(password, 20))) {
			admin_System_Panel();
		}
		else {
			MessageBox(hwnd, L"您所输入的账号或密码有误，请重新输入！", _T("账号密码错误"), MB_OK | MB_ICONHAND);
			verify_login(test, hwnd);
		}
	}
	else {
		select_Identity();
	}

}

////////////////////////////
void add_new_admin(fstream& test) {
	wchar_t account[20], password[20];
	InputBox(account, 20, _T("Account"), _T("账号"), NULL, 0, 0, true);
	InputBox(password, 20, _T("Password"), _T("密码"), NULL, 0, 0, false);
	char account1[20], password1[20];
	wcharTochar(account, account1, 20);
	wcharTochar(password, password1, 20);
	test << charArrayToString(account1) << " " << charArrayToString(password1) << endl;
	test.close();
}

void first_admin_create(HWND hwnd) {
	MessageBox(hwnd, _T("现在为您创建一个可用的【管理员】账户"), _T("创建账户"), MB_OK);
	wchar_t Temppassaccount[20];
	InputBox(Temppassaccount, 20, _T("请输入账号"), _T("创建【管理员账户】"), NULL, 0, 0, true);
labelStart:	wchar_t Temppassword_one[20], Temppassword_two[20];
	InputBox(Temppassword_one, 20, _T("请输入密码"), _T("创建【教师账户】"), NULL, 0, 0, true);
	InputBox(Temppassword_two, 20, _T("请再次输入密码"), _T("创建【教师账户】"), NULL, 0, 0, true);
	char temp_one[20], temp_two[20];
	wcharTochar(Temppassword_one, temp_one, 20);
	wcharTochar(Temppassword_two, temp_two, 20);
	if (strcmp(temp_one, temp_two) != 0) {
		MessageBox(hwnd, _T("两次输入的密码不一致，请重新输入"), _T(""), MB_OK | MB_ICONEXCLAMATION);
		goto labelStart;
	}
	char account[20], password[20];
	ofstream fp("Data/admin.txt", ios::app);
	if (!fp) {
		cerr << "Error opening file!" << endl;
		// 这里可以输出更多的错误信息
	}
	else {
		//wcharTochar(Temppassaccount, account, 20);
		//wcharTochar(Temppassword_two, password, 20);
		//fp << charArrayToString(account) << " " << charArrayToString(password) << endl;
		fp << wchartostring(Temppassaccount, 20) << " " << wchartostring(Temppassword_two, 20) << endl;
		fp.close();
		MessageBox(hwnd, _T("现在，您可以使用这个账户登录【管理员端】了！"), _T("创建成功"), MB_OK);
		return;
	}
}

void admin_System_Login_Error() {
	system("cls");
	cout << "账户或密码错误        " << endl << endl;
	cout << "1) 重新输入            " << endl;
	cout << "2) 返回选择菜单            " << endl;
	cout << "3)	 退出               " << endl;
	cout << "> ";
	int op;
	cin >> op;
	if (op == 1)
		admin_System_Login();
	else if (op == 2)
		select_Identity();
	else if (op == 3)
		exit_System();
	else {
		system("cls");
		cout << "输入有误，请重新输入" << endl;
		admin_System_Login_Error1();
	}
}

void admin_System_Login_Error1() {

	cout << "1) 重新输入            " << endl;
	cout << "2) 返回选择菜单            " << endl;
	cout << "3)	 退出               " << endl;
	printLine();
	cout << endl;
	cout << "> ";
	int op;
	cin >> op;
	if (op == 1)
		admin_System_Login();
	else if (op == 2)
		select_Identity();
	else if (op == 3)
		exit_System();
	else {
		system("cls");
		cout << "输入有误，请重新输入" << endl;
	}
}

void scan_candidates_information(int x) {
	setlocale(LC_ALL, "Chinese-simplified");  // 设置为适当的中文区域设置
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("浏览候选人.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("学生成绩管理系统 2.0"));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(153, 50, 204));
	settextstyle(20, 0, _T("等线"));
	if (x == 1) {
		outtextxy(691, 293, _T("\t编号      \t姓名              \t简历"));
		ifstream in("Data/voter1.txt", std::ios::in);
		int n;
		in >> n;
		for (int i = 1, y = 313; i <= n; i++, y += 20) {
			wchar_t candidates_Name[10];
			wchar_t candidates_Resume[40];
			wchar_t candidates_information[100];
			int no, mount;
			string name, resume;
			in >> no >> name >> resume >> mount;
			wchar_t* wideName = stringToWideCharArray(name);
			wchar_t* wideResume = stringToWideCharArray(resume);
			cout << wideName << wideResume << endl;
			_stprintf_s(candidates_information, _T("%-5d      %-10s      %-20s "), no, wideName, wideResume);
			outtextxy(691, y, candidates_information);
		}
	}
	else if (x == 2) {
		outtextxy(691, 293, _T("\t编号      \t姓名         \t投票数"));
		ifstream in("Data/voter1.txt", std::ios::in);
		int n;
		in >> n;
		for (int i = 1, y = 313; i <= n; i++, y += 20) {
			wchar_t candidates_Name[10];
			wchar_t candidates_information[100];
			int no, mount;
			string name, resume;
			in >> no >> name >> resume >> mount;
			wchar_t* wideName = stringToWideCharArray(name);
			_stprintf_s(candidates_information, _T("%-5d      %-10s      %-20d "), no, wideName, mount);
			outtextxy(691, y, candidates_information);
		}
	}
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //清空鼠标消息缓冲区
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
				/*modify_candidates_information();*/
				if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 969 && msg.y >= 237 && msg.y <= 272) {
				admin_System_Panel();
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
				goto labelTeachersMenu;
			}
		}
	}
labelTeachersMenu:
	return;
}

//void admin_System_Panel() {
//	system("cls");
//	printLine();
//	cout << endl;
//	cout << "\t1) 初始化候选人信息" << endl;
//	cout << "\t2) 浏览候选人简介" << endl;
//	cout << "\t3) 修改候选人简介" << endl;
//	cout << "\t4) 查询投票情况" << endl;
//	cout << "\t5) 清除投票信息" << endl;
//	cout << "\t6) 更改账户权限" << endl;
//	cout << endl;
//	printLine();
//	cout << endl;
//	cout << "> ";
//	int op;
//	cin >> op;
//	if (op == 1) {
//		init_candidates_information();
//		admin_System_Panel();
//	}
//	else if (op == 2) {
//		int n;
//		candidates* voter = browse_candidates_information(n);
//		display_voter(n, voter);
//	}
//	else if (op == 3) {
//		modify_candidates_information();
//	}
//	else if (op == 4) {
//		int n;
//		candidates* voter = browse_candidates_information(n);
//		check_voting_status(n, voter);
//	}
//	else if (op == 5) {
//		clear_vote_information();
//	}
//	else if (op == 6) {
//		user_manager_panel();
//	}
//}

void wcharTochar(const wchar_t* wchar, char* chr, int length) {//将wchar转化为char
	WideCharToMultiByte(CP_ACP, 0, wchar, -1, chr, length, NULL, NULL);
}

void charTowchar(const char* chr, wchar_t* wchar, int size) {//将char转化为wchar
	MultiByteToWideChar(CP_ACP, 0, chr, strlen(chr) + 1, wchar, size / sizeof(wchar[0]));
}

std::string charArrayToString(const char* charArray) {
	// 使用 std::string 的构造函数进行转换
	return std::string(charArray);
}

std::string wchartostring(const wchar_t* wchar, int length) {
	char* string = new char[length + 1];
	wcharTochar(wchar, string, length + 1);
	std::string result(string);
	delete[] string;  // 释放内存
	return result;
}

char* stringToCharArray(const std::string& str) {
	char* charArray = new char[str.length() + 1];  // 创建足够容纳字符串的字符数组

	strcpy(charArray, str.c_str());  // 使用strcpy()函数将string类型复制到char数组中
	charArray[str.length()] = '\0';  // 添加null字符

	return charArray;
}

wchar_t* stringToWideCharArray(const std::string& str) {
	size_t size = str.length() + 1;
	wchar_t* wideCharArray = new wchar_t[size];
	mbstowcs(wideCharArray, str.c_str(), size);
	wideCharArray[size - 1] = L'\0';
	return wideCharArray;
}