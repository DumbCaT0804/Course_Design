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
		int no;
		string name, resume;
		in >> no >> name >> resume;
		voter[i].setNo(no);
		voter[i].setName(name);
		voter[i].setResume(resume);
	}
	in.close();

	return voter;
}

void display_voter(int n, candidates* voter) {
	std::cout << std::left << std::setw(8) << "编号" << std::setw(15) << "姓名"
		<< std::setw(10) << "简介" << std::setw(8) << "支持人数" << std::endl;
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
	cout << "\t\t Author : Zhiwei Yu" << endl;
	cout << endl;
	printLine();
}

//这样直接引入不用复制，不被修改，节省时间，空间;
bool judge_Admin(const string& account, const string& password) {
	string verifyAccount, verifyPassword;
	ifstream in("Data/admin.txt", ios::in);	//定义输入流
	while (in >> verifyAccount >> verifyPassword) {
		cout << verifyAccount << " " << verifyPassword;
		if (account == verifyAccount && password == verifyPassword) {
			in.close();
			return true;
		}
		int x;
		cin >> x;
	}
	in.close();
	return false;
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
		voter_System_Login(); //xx
	else
		exit_System();	//xx
}

void voter_System_Login() {

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
}

