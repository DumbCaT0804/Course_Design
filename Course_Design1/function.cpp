#include "summary.h"
#define number_of_candidates n

void init_candidates_information() {
	ofstream fout; //写入文件
	fout.open("Data/voter1.txt", ios::out);
	if (!fout.is_open()) {
		std::cerr << "无法打开文件！Sorry ~.~" << std::endl;
	}
	std::cout << std::left << std::setw(8) << "编号" << std::setw(15) << "姓名"
		<< std::setw(10) << "简介" << std::setw(8) << "支持人数" << std::endl;
	string input;
	int n = 0;	//选举个数
	getchar();
	fout << n << endl;
	while (1) {
		std::getline(std::cin, input);
		if (input.empty()) {
			break;
		}
		n++;
		fout << input << std::endl;
	}
	fout.seekp(0);  // 将文件指针移到文件开头
	fout << n;
	fout.close();
	std::cout << "数据写入成功hhh！" << std::endl;
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

void change_user_setting(user* head) {
	cout << "输入你想要更改的用户编号" << endl;
	cout << "> ";
	int no;
	cin >> no;
	getchar();
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
			cout << "修改账号 > ";
			cin >> account;
			cout << "修改密码 > ";
			cin >> password;
			cout << "是否想要修改用户权限？(yes/no)" << endl;
			string x;
			cin >> x;
			if (x == "yes") {
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

void init_new_user() {
	ofstream fout("Data/user.txt", std::ios::out);
	if(!fout.is_open())
		std::cerr << "无法打开文件！Sorry ~.~" << std::endl;
	string input;
	int n = 0;	//投票人个数
	getchar();	//吸收缓存区空格字符
	fout << n << endl;
	while (1) {
		getline(std::cin, input);
		if (input.empty())
			break;
		n++;
		fout << input << std::endl;
	}
	fout.seekp(0);
	fout << n;
	fout.close();
}

void add_new_user() {
	ofstream fout("Data/user.txt", std::ios::app);
	int no;
	string account, password;
	cin >> no >> account >> password;
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

void search_user(int number, user* head) {

	ifstream in("Data/user.txt");
	int n;
	in >> n;
	for (int i = 1; i <= n; i++) {
		if (number == n) {
			cout << "账号：" << head[i].getAccount() << " 密码：" << head[i].getPassword();
			return;
		}
	}
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


void user_manager_panel() {
	system("cls");
	cout << "1) 初始化新用户" << endl;
	cout << "2) 更改用户Setting" << endl;
	cout << "3) 增加用户" << endl;
	cout << "4) 删除用户" << endl;
	cout << "5) 查询用户" << endl;
	cout << "6) 排序" << endl;
	cout << endl;
	printLine();
	cout << endl;
	cout << "> ";
	int op;
	cin >> op;
	user* head;
	int n;
	head = init_user(n);
	if (op == 1) {
		init_new_user();
	}
	else if (op == 2) {
		change_user_setting(head);
	}
	else if (op == 3) {
		add_new_user();
	}
	else if (op == 4) {
		cout << "输入你想要删除的编号" << endl;
		cout << "> ";
		int number;
		cin >> number;
		delete_new_user(number, head);
	}
	else if (op == 5) {
		cout << "输入你想要查找的用户编号" << endl;
		cout << "> ";
		int number;
		cin >> number;
		search_user(number, head);
	}
	else if (op == 6) {
		cout << n << endl;	
		selectSort(n, head);
	}
}

void modify_candidates_information() {
	fstream in("Data/voter1.txt", std::ios::in);
	cout << "输入你想修改的候选人序号: " << endl;
	cout << "> ";
	int modify_candidate;
	cin >> modify_candidate;
	int n;	//表示选举人个数
	std::stringstream content;
	in >> n;
	content << n << endl;
	for (int i = 1; i <= n; i++) {
		int no, mount;
		string name, resume;
		in >> no >> name >> resume >> mount;
		if (no == modify_candidate) {
			cout << "你要修改的内容: " << endl;
			cout << "> ";
			cin >> no >> name >> resume >> mount;
		}
		content << no << " " << name << " " << resume << " " << mount << endl;
	}
	in.close();
	ofstream fout("Data/voter1.txt");
	fout << content.str();
	fout.close();
}

void user_vote(int number) {
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

void Begin() {
	printLine();
	cout << endl;
	cout << "\t Welcome to the Electronic Voting System 1.0" << endl;
	cout << endl;
	cout << "\t\t Author : Zhiwei Yu, Quyu Hao" << endl;
	cout << endl;
	printLine();
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

void select_Identity() {
	system("cls");
	printLine();
	cout << endl;
	cout << " Please select your identity :" << endl;
	cout << "\t\t\t     （1）管理员" << endl;
	cout << "\t\t\t     （2）投票人员" << endl;
	cout << "\t\t\t     （3）退出" << endl;
	cout << endl;
	printLine();
	cout << endl;
	cout << "> ";
	char x;
	x = getchar();
	if (x == 'a')
		cout << "Test Over!" << endl;
	if (x == '1')
		admin_System_Login();
	else if (x == '2')
		user_System_Login(); //xx
	else
		exit_System();	//xx
}

void user_System_Login() {
	system("cls");
	string account, password;
	cout << "Account :" << endl;
	cout << "> ";
	cin >> account;
	cout << "Password :" << endl;
	cout << "> ";
	cin >> password;
	if (judge_Admin1(account, password))
		user_System_Panel();
	else
		user_System_Login_Error();
}

void user_System_Panel() {
	printLine();
	cout << endl;
	cout << "1) 投票" << endl;
	cout << "2) 浏览候选人信息" << endl;
	cout << endl;
	printLine();
	cout << endl;
	cout << "> ";
	int op;
	cin >> op;
	if (op == 1) {
		cout << "请输入你想要投票的编号)> ";
		int n;
		cin >> n;
		user_vote(n);
	}
	else if (op == 2) {
		int n;
		candidates* voter = browse_candidates_information(n);
		display_voter(n, voter);
	}
		
}

void user_System_Login_Error() {
	cout << "抱歉，账号密码错误" << endl;
}

void exit_System() {

}

void admin_System_Login() {
	system("cls");

	string account, password;
	cout << "Account :" << endl;
	cout << "> ";
	cin >> account;
	cout << "Password :" << endl;
	cout << "> ";
	cin >> password;
	if (judge_Admin(account, password))
		admin_System_Panel();
	else
		admin_System_Login_Error();

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

void admin_System_Panel() {
	system("cls");
	printLine();
	cout << endl;
	cout << "\t1) 初始化候选人信息" << endl;
	cout << "\t2) 浏览候选人简介" << endl;
	cout << "\t3) 修改候选人简介" << endl;
	cout << "\t4) 查询投票情况" << endl;
	cout << "\t5) 清除投票信息" << endl;
	cout << "\t6) 更改账户权限" << endl;
	cout << endl;
	printLine();
	cout << endl;
	cout << "> ";
	int op;
	cin >> op;
	if (op == 1) {
		init_candidates_information();
		admin_System_Panel();
	}
	else if (op == 2) {
		int n;
		candidates* voter = browse_candidates_information(n);
		display_voter(n, voter);
	}
	else if (op == 3) {
		modify_candidates_information();
	}
	else if (op == 4) {
		int n;
		candidates* voter = browse_candidates_information(n);
		check_voting_status(n, voter);
	}
	else if (op == 5) {
		clear_vote_information();
	}
	else if (op == 6) {
		user_manager_panel();
	}
}

