#include "summary.h"
#define number_of_candidates n

void init_candidates_information() {
	ofstream fout; //д���ļ�
	fout.open("Data/voter1.txt", ios::out);
	if (!fout.is_open()) {
		std::cerr << "�޷����ļ���Sorry ~.~" << std::endl;
	}
	std::cout << std::left << std::setw(8) << "���" << std::setw(15) << "����"
		<< std::setw(10) << "���" << std::setw(8) << "֧������" << std::endl;
	string input;
	int n = 0;	//ѡ�ٸ���
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
	fout.seekp(0);  // ���ļ�ָ���Ƶ��ļ���ͷ
	fout << n;
	fout.close();
	std::cout << "����д��ɹ�hhh��" << std::endl;
}

candidates* browse_candidates_information(int &n) {	//��&����ֻ���������룬�ں����ڲ���n��ֵ
	fstream in("Data/voter1.txt", std::ios::in);	//���ļ�������->����
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
	std::cout << std::left << std::setw(8) << "���" << std::setw(15) << "����"
		<< std::setw(10) << "���" << std::setw(8) << "֧������" << std::endl;
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

//����ֱ�����벻�ø��ƣ������޸ģ���ʡʱ�䣬�ռ�;
bool judge_Admin(const string& account, const string& password) {
	string verifyAccount, verifyPassword;
	ifstream in("Data/admin.txt", ios::in);	//����������
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
	cout << "\t\t\t     ��1������Ա" << endl;
	cout << "\t\t\t     ��2��ͶƱ��Ա" << endl;
	cout << "\t\t\t     ��3���˳�" << endl;
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

void admin_System_Panel() {
	system("cls");
	printLine();
	cout << endl;
	cout << "\t1) ��ʼ����ѡ����Ϣ" << endl;
	cout << "\t2) �����ѡ�˼��" << endl;
	cout << "\t3) �޸ĺ�ѡ�˼��" << endl;
	cout << "\t4) ��ѯͶƱ���" << endl;
	cout << "\t5) ���ͶƱ��Ϣ" << endl;
	cout << "\t6) �����˻�Ȩ��" << endl;
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

