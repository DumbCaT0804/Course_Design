#include "summary.h"
#define number_of_candidates n

//void init_candidates_information() {
//	ofstream fout; //д���ļ�
//	fout.open("Data/voter1.txt", ios::out);
//	if (!fout.is_open()) {
//		std::cerr << "�޷����ļ���Sorry ~.~" << std::endl;
//	}
//	//std::cout << std::left << std::setw(8) << "���" << std::setw(15) << "����"
//	//	<< std::setw(10) << "���" << std::setw(8) << "֧������" << std::endl;
//	string input;
//	int n = 0;	//ѡ�ٸ���
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
//	fout.seekp(0);  // ���ļ�ָ���Ƶ��ļ���ͷ
//	fout << n;
//	fout.close();
//	std::cout << "����д��ɹ�hhh��" << std::endl;
//}

//void init_new_user() {
//	ofstream fout("Data/user.txt", std::ios::out);
//	if (!fout.is_open())
//		std::cerr << "�޷����ļ���Sorry ~.~" << std::endl;
//	string input;
//	int n = 0;	//ͶƱ�˸���
//	getchar();	//���ջ������ո��ַ�
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

void init_new_user() {//1-¼���û���Ϣ
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("��ʼ�����û�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	int usercount = 0;
	user* head = (user*)malloc(sizeof(user));
	head->next = NULL;
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 936 && msg.y >= 244 && msg.y <= 271) {
				while (1) {
					//��ʼ¼��
					/*candidates* new_candidates = (candidates*)malloc(sizeof(candidates));
					if (new_candidates == NULL) {
						printf("�ڴ濪��ʧ�ܣ�");
						exit(1);
					}*/
					wchar_t user_No[2];
					wchar_t user_account[10];
					wchar_t user_password[40];
					int i;
					i = InputBox(user_No, 2, _T("�����롾��š�"), _T("test"), NULL, 0, 0, false);
					if (i == true) {
						InputBox(user_account, 10, _T("�˺�"), _T("test"), NULL, 0, 0, true);
						InputBox(user_password, 40, _T("����"), _T("test"), NULL, 0, 0, true);
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

void init_candidates_information() {//1-¼��ѧ����Ϣ
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("��ʼ����ѡ��.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	int votercount = 0;
	candidates* head = (candidates*)malloc(sizeof(candidates));
	head->next = NULL;
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 937 && msg.y >= 236 && msg.y <= 267) {
				while (1) {
					//��ʼ¼��
					/*candidates* new_candidates = (candidates*)malloc(sizeof(candidates));
					if (new_candidates == NULL) {
						printf("�ڴ濪��ʧ�ܣ�");
						exit(1);
					}*/
					wchar_t Candidates_No[2];
					wchar_t Candidates_Name[10];
					wchar_t Candidates_Resume[40];
					int i;
					i = InputBox(Candidates_No, 2, _T("�����롾��š�"),_T("test"), NULL, 0, 0, false);
					if (i == true) {
						InputBox(Candidates_Name, 10, _T("����"), _T("test"), NULL, 0, 0, true);
						InputBox(Candidates_Resume, 40, _T("����"), _T("test"), NULL, 0, 0, true);
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

void modify_candidates_panel() {//1-¼���û�
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("�޸ĺ�ѡ��.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 937 && msg.y >= 236 && msg.y <= 267) {
				fstream in("Data/voter1.txt", std::ios::in);
				wchar_t candidates_No[2];
				InputBox(candidates_No, 2, _T("���"), _T("����Ҫ�޸ĵı��"), NULL, 0, 0, true);

				int modify_candidate = std::stoi(wchartostring(candidates_No, 2));
				cout << modify_candidate << endl;
				int n;	//��ʾѡ���˸���
				std::stringstream content;
				in >> n;
				content << n << endl;
				for (int i = 1; i <= n; i++) {
					int no, mount;
					string name, resume;
					in >> no >> name >> resume >> mount;
					if (no == modify_candidate) {
						wchar_t  resume_t[40];
						InputBox(resume_t, 40, _T("����"), _T("��������Ҫ�޸ĵļ���"), NULL, 0, 0, true);
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


candidates* browse_candidates_information(int &n) {	//��&����ֻ���������룬�ں����ڲ���n��ֵ
	fstream in("Data/voter1.txt", std::ios::in);	//���ļ�������->����
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
			InputBox(_password, 20, _T("Password"), _T("����"), NULL, 0, 0, false);
			password = wchartostring(_password, 20);
			int i = MessageBox(NULL, L"Ȩ��", _T("�Ƿ�����Ϊ����Ա��"), MB_OKCANCEL | MB_ICONHAND);
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
	loadimage(&img, _T("�����û�Setting.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 993 && msg.y >= 240 && msg.y <= 268) {
				/*modify_candidates_information();*/
				wchar_t no[2];
				InputBox(no, 2, _T("Number"), _T("���"), NULL, 0, 0, true);
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
	loadimage(&img, _T("ɾ���û�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 993 && msg.y >= 240 && msg.y <= 268) {
				/*modify_candidates_information();*/
				wchar_t no[2];
				InputBox(no, 2, _T("Number"), _T("���"), NULL, 0, 0, true);
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
	if (in) {	//�����ļ�����
		in >> n;
		if (n == 0) {	//�����ļ�����Ϊ��
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
	loadimage(&img, _T("�����û�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 812 && msg.x <= 1024 && msg.y >= 238 && msg.y <= 272) {
				/*modify_candidates_information();*/
				wchar_t no[2], account[20], password[20];
				InputBox(no, 2, _T("Number"), _T("���"), NULL, 0, 0, true);
				InputBox(account, 20, _T("Account"), _T("�˺�"), NULL, 0, 0, true);
				InputBox(password, 20, _T("Password"), _T("����"), NULL, 0, 0, true);
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
			_stprintf_s(title, _T("���: %d"), head[i].getNo());
			//���string to char buffer too small ����
			std::string account = head[i].getAccount();
			wchar_t* wideAccount = stringToWideCharArray(account);
			_stprintf_s(content, _countof(content), _T("�û���Ϊ: %ls"), wideAccount);
			MessageBox(hwnd, content, title, MB_OK);
			return;
		}
	}
}

void query_user_panel() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("��ѯ�û�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 815 && msg.x <= 940 && msg.y >= 242 && msg.y <= 278) {
				/*modify_candidates_information();*/
				wchar_t no[2], account[20], password[20];
				InputBox(no, 2, _T("Number"), _T("���"), NULL, 0, 0, true);
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
	loadimage(&img, _T("����.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 812 && msg.x <= 911 && msg.y >= 136 && msg.y <= 188) {
				/*modify_candidates_information();*/
				MessageBox(hwnd, L"����ɹ���", _T("��ϲ��ϲ"), MB_OK);
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
	initgraph(1200, 700);//����
	loadimage(&img, _T("�����û�Ȩ��.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("����ͶƱϵͳϵͳ 2.0"));
labelStart:
	MOUSEMSG msg;// ������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ������
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 991 && msg.y >= 244 && msg.y <= 270) {
				//��ʼ�����û�
				closegraph();
				init_new_user();
				user_manager_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 1027 && msg.y >= 306 && msg.y <= 337) {
				//�����û�Setting
				closegraph();
				change_user_setting();
				user_manager_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 371 && msg.y <= 403) {
				//�����û�
				closegraph();
				add_user_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 442 && msg.y <= 470) {
				//ɾ���û�
				closegraph();
				delete_user();
				/*FindInformation();*/
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 506 && msg.y <= 536) {
				//��ѯ�û�
				query_user_panel();
				/*ProcessingData();*/
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 814 && msg.x <= 879 && msg.y >= 568 && msg.y <= 604) {
				//����
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
//	cout << "1) ��ʼ�����û�" << endl;
//	cout << "2) �����û�Setting" << endl;
//	cout << "3) �����û�" << endl;
//	cout << "4) ɾ���û�" << endl;
//	cout << "5) ��ѯ�û�" << endl;
//	cout << "6) ����" << endl;
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
//		cout << "��������Ҫɾ���ı��" << endl;
//		cout << "> ";
//		int number;
//		cin >> number;
//		delete_new_user(number, head);
//	}
//	else if (op == 5) {
//		cout << "��������Ҫ���ҵ��û����" << endl;
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
	int n;	//��ʾѡ���˸���
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
	std::cout << std::left << std::setw(8) << "���" << std::setw(15) << "����"
		<< std::setw(8) << "֧������" << std::endl;
	for (int i = 1; i <= n; i++) {
		std::cout << std::left << std::setw(8) << voter[i].getNo() << std::setw(15) << voter[i].getName()
			 << std::setw(8) << voter[i].getMount() << std::endl;
	}
}

void display_voter(int n, candidates* voter) {
	std::cout << std::left << std::setw(8) << "���" << std::setw(15) << "����"
		<< std::setw(10) << "���" << std::endl;
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

void Begin() {//��ӭ����
	IMAGE img;
	initgraph(1200, 700);//����
	loadimage(&img, _T("��ʼ����.png"), 1200, 700);//����ͼƬ���ߣ�������ԭͼ��С
	putimage(0, 0, &img);//ͼƬ��ʾ��λ��
	HWND hwnd;// ���ô��ھ���������洰����Ϣ
	hwnd = GetHWnd();// ��ȡ���ھ��
	SetWindowText(hwnd, _T("����ͶƱϵͳ 2.0"));
	Sleep(2000);
	closegraph();
}

//����ֱ�����벻�ø��ƣ������޸ģ���ʡʱ�䣬�ռ�;

bool judge_Admin1(const string& account, const string& password) {
	int no;
	string verifyAccount, verifyPassword;
	ifstream in("Data/user.txt", ios::in);	//����������
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
	ifstream in("Data/admin.txt", ios::in);	//����������
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
//	cout << "\t\t\t     ��1������Ա" << endl;
//	cout << "\t\t\t     ��2��ͶƱ��Ա" << endl;
//	cout << "\t\t\t     ��3���˳�" << endl;
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
//	cout << "1) ͶƱ" << endl;
//	cout << "2) �����ѡ����Ϣ" << endl;
//	cout << endl;
//	printLine();
//	cout << endl;
//	cout << "> ";
//	int op;
//	cin >> op;
//	if (op == 1) {
//		cout << "����������ҪͶƱ�ı��)> ";
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
		initgraph(1200, 700);//����
		loadimage(&img, _T("ͶƱ�˵�¼.png"), 1200, 700);
		putimage(0, 0, &img);
		HWND hwnd;
		hwnd = GetHWnd();
		SetWindowText(hwnd, _T("����ͶƱϵͳ 2.0"));
		fstream test("Data/admin.txt", std::ios::in);
		if (!test.is_open()) {
			int i = MessageBox(hwnd, _T("�ļ��򲻿�"), _T("û���û�����"), MB_OK);
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
	loadimage(&img, _T("ͶƱ.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 1054 && msg.y >= 239 && msg.y <= 274) {
				/*modify_candidates_information();*/
				wchar_t no[2];
				InputBox(no, 2, _T("Account"), _T("�˺�"), NULL, 0, 0, false);
				int number = std::stoi(wchartostring(no, 2));
				MessageBox(NULL, L"ͶƱ�ɹ�", _T("��ϲ��ϲ"), MB_OK);
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
	loadimage(&img, _T("ͶƱ�˲˵�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 809 && msg.x <= 878 && msg.y >= 236 && msg.y <= 274) {
				//ͶƱ	
				user_vote();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 810 && msg.x <= 1030 && msg.y >= 302 && msg.y <= 344) {
				//���ͶƱ����Ϣ
				scan_candidates_information(1);
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 813 && msg.x <= 882 && msg.y >= 369 && msg.y <= 409) {
				//�Ƴ�
				select_Identity();
				goto label;
			}
		}

	}
label:return;
}


void verify_login_user(fstream& test, HWND hwnd) {
	wchar_t account[20], password[20];
	if (InputBox(account, 20, _T("Account"), _T("�˺�"), NULL, 0, 0, false)) {
		InputBox(password, 20, _T("Password"), _T("����"), NULL, 0, 0, false);
		if (judge_Admin1(wchartostring(account, 20), wchartostring(password, 20))) {
			user_System_Panel();
		}
		else {
			MessageBox(hwnd, L"����������˺Ż������������������룡", _T("�˺��������"), MB_OK | MB_ICONHAND);
			verify_login(test, hwnd);
		}
	}
	else {
		select_Identity();
	}

}

void select_Identity() {//��¼����
	IMAGE img;
	initgraph(1200, 700);
	HWND hwnd;// ���ô��ھ���������洰����Ϣ
	hwnd = GetHWnd();// ��ȡ���ھ��
	SetWindowText(hwnd, _T("����ͶƱϵͳ 2.0"));
	loadimage(&img, _T("��¼����.png"), 1200, 700);
	putimage(0, 0, &img);
	//������¼�����
	MOUSEMSG msg;// ������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ������	
	while (1) { // ��ѭ�� ѭ�����������Ϣ
		while (MouseHit())// ���������Ϣ ���������Ϣ��ʱ��ִ�� �ɼ�������������Ϣ
		{
			msg = GetMouseMsg();// ��ȡ�����Ϣ
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 961 && msg.y >= 245 && msg.y <= 273) {
				//����Ա��¼
				admin_System_Login();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 961 && msg.y >= 315 && msg.y <= 340) {
				//ͶƱ�˵�¼
				closegraph();
				user_System_Login();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 871 && msg.y >= 378 && msg.y <= 405) {
				//�˳�
				closegraph();
				goto label;
			}
		}
	}
label:return;
}


void user_System_Login_Error() {
	cout << "��Ǹ���˺��������" << endl;
}

void exit_System() {

}

void admin_System_Login() {
	IMAGE img;
	initgraph(1200, 700);//����
	loadimage(&img, _T("����Ա��¼.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("����ͶƱϵͳ 2.0"));
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
	if (InputBox(account, 20, _T("Account"), _T("�˺�"), NULL, 0, 0, false)) {
		InputBox(password, 20, _T("Password"), _T("����"), NULL, 0, 0, false);
		if (judge_Admin(wchartostring(account, 20), wchartostring(password, 20))) {
			admin_System_Panel();
		}
		else {
			MessageBox(hwnd, L"����������˺Ż������������������룡", _T("�˺��������"), MB_OK | MB_ICONHAND);
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
	InputBox(account, 20, _T("Account"), _T("�˺�"), NULL, 0, 0, true);
	InputBox(password, 20, _T("Password"), _T("����"), NULL, 0, 0, false);
	char account1[20], password1[20];
	wcharTochar(account, account1, 20);
	wcharTochar(password, password1, 20);
	test << charArrayToString(account1) << " " << charArrayToString(password1) << endl;
	test.close();
}

void first_admin_create(HWND hwnd) {
	MessageBox(hwnd, _T("����Ϊ������һ�����õġ�����Ա���˻�"), _T("�����˻�"), MB_OK);
	wchar_t Temppassaccount[20];
	InputBox(Temppassaccount, 20, _T("�������˺�"), _T("����������Ա�˻���"), NULL, 0, 0, true);
labelStart:	wchar_t Temppassword_one[20], Temppassword_two[20];
	InputBox(Temppassword_one, 20, _T("����������"), _T("��������ʦ�˻���"), NULL, 0, 0, true);
	InputBox(Temppassword_two, 20, _T("���ٴ���������"), _T("��������ʦ�˻���"), NULL, 0, 0, true);
	char temp_one[20], temp_two[20];
	wcharTochar(Temppassword_one, temp_one, 20);
	wcharTochar(Temppassword_two, temp_two, 20);
	if (strcmp(temp_one, temp_two) != 0) {
		MessageBox(hwnd, _T("������������벻һ�£�����������"), _T(""), MB_OK | MB_ICONEXCLAMATION);
		goto labelStart;
	}
	char account[20], password[20];
	ofstream fp("Data/admin.txt", ios::app);
	if (!fp) {
		cerr << "Error opening file!" << endl;
		// ��������������Ĵ�����Ϣ
	}
	else {
		//wcharTochar(Temppassaccount, account, 20);
		//wcharTochar(Temppassword_two, password, 20);
		//fp << charArrayToString(account) << " " << charArrayToString(password) << endl;
		fp << wchartostring(Temppassaccount, 20) << " " << wchartostring(Temppassword_two, 20) << endl;
		fp.close();
		MessageBox(hwnd, _T("���ڣ�������ʹ������˻���¼������Ա�ˡ��ˣ�"), _T("�����ɹ�"), MB_OK);
		return;
	}
}

void admin_System_Login_Error() {
	system("cls");
	cout << "�˻����������        " << endl << endl;
	cout << "1) ��������            " << endl;
	cout << "2) ����ѡ��˵�            " << endl;
	cout << "3)	 �˳�               " << endl;
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
		cout << "������������������" << endl;
		admin_System_Login_Error1();
	}
}

void admin_System_Login_Error1() {

	cout << "1) ��������            " << endl;
	cout << "2) ����ѡ��˵�            " << endl;
	cout << "3)	 �˳�               " << endl;
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
		cout << "������������������" << endl;
	}
}

void scan_candidates_information(int x) {
	setlocale(LC_ALL, "Chinese-simplified");  // ����Ϊ�ʵ���������������
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("�����ѡ��.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(153, 50, 204));
	settextstyle(20, 0, _T("����"));
	if (x == 1) {
		outtextxy(691, 293, _T("\t���      \t����              \t����"));
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
		outtextxy(691, 293, _T("\t���      \t����         \tͶƱ��"));
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
	FlushMouseMsgBuffer(); //��������Ϣ������
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
	initgraph(1200, 700);//����
	loadimage(&img, _T("����Ա�˵�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("����ͶƱϵͳϵͳ 2.0"));
labelStart:
	MOUSEMSG msg;// ������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ������
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1060 && msg.y >= 240 && msg.y <= 272) {
				//��ʼ����ѡ����Ϣ
				closegraph();
				init_candidates_information();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 970 && msg.y >= 306 && msg.y <= 335) {
				//�����ѡ����Ϣ
				closegraph();
				scan_candidates_information(1);
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 970 && msg.y >= 374 && msg.y <= 405) {
				//�޸�ͶƱ����Ϣ
				closegraph();
				modify_candidates_panel();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1000 && msg.y >= 444 && msg.y <= 469) {
				//��ѯͶƱ���
				closegraph();
				/*FindInformation();*/
				scan_candidates_information(2);
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1000 && msg.y >= 505 && msg.y <= 536) {
				//ͶƱ��Ϣ����
				MessageBox(hwnd, _T("��������ɹ�����QAQ"), _T("����ɹ�"), MB_OK);
				clear_vote_information();
				admin_System_Panel();
				/*ProcessingData();*/
				goto labelTeachersMenu;
			}

			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 1000 && msg.y >= 569 && msg.y <= 606) {
				//�����û�Ȩ��
				closegraph();
				user_manager_panel();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 874 && msg.y >= 642 && msg.y <= 670) {
				//�˳�ϵͳ
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
//	cout << "\t1) ��ʼ����ѡ����Ϣ" << endl;
//	cout << "\t2) �����ѡ�˼��" << endl;
//	cout << "\t3) �޸ĺ�ѡ�˼��" << endl;
//	cout << "\t4) ��ѯͶƱ���" << endl;
//	cout << "\t5) ���ͶƱ��Ϣ" << endl;
//	cout << "\t6) �����˻�Ȩ��" << endl;
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

void wcharTochar(const wchar_t* wchar, char* chr, int length) {//��wcharת��Ϊchar
	WideCharToMultiByte(CP_ACP, 0, wchar, -1, chr, length, NULL, NULL);
}

void charTowchar(const char* chr, wchar_t* wchar, int size) {//��charת��Ϊwchar
	MultiByteToWideChar(CP_ACP, 0, chr, strlen(chr) + 1, wchar, size / sizeof(wchar[0]));
}

std::string charArrayToString(const char* charArray) {
	// ʹ�� std::string �Ĺ��캯������ת��
	return std::string(charArray);
}

std::string wchartostring(const wchar_t* wchar, int length) {
	char* string = new char[length + 1];
	wcharTochar(wchar, string, length + 1);
	std::string result(string);
	delete[] string;  // �ͷ��ڴ�
	return result;
}

char* stringToCharArray(const std::string& str) {
	char* charArray = new char[str.length() + 1];  // �����㹻�����ַ������ַ�����

	strcpy(charArray, str.c_str());  // ʹ��strcpy()������string���͸��Ƶ�char������
	charArray[str.length()] = '\0';  // ���null�ַ�

	return charArray;
}

wchar_t* stringToWideCharArray(const std::string& str) {
	size_t size = str.length() + 1;
	wchar_t* wideCharArray = new wchar_t[size];
	mbstowcs(wideCharArray, str.c_str(), size);
	wideCharArray[size - 1] = L'\0';
	return wideCharArray;
}