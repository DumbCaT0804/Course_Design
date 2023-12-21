#include "summary.h"
//ostream: "output stream"
//ofstream         �ļ�д���� �ڴ�д��洢�豸 
//ifstream         �ļ����������洢�豸�������ڴ���
//fstream          ��д�������Դ򿪵��ļ��ɽ��ж�д���� 

ostream& operator<< (ostream& out, const user& user) {
	return out << user.no << " " << user.account << " " << user.password;
}

bool operator> (const user& user1, const user& user2) {
	return user1.no > user2.no;
}

void user::setNo(int _no) { no = _no; };	//����userǰ׺���ܱ�����user�ĺ����������������ڵı���
void user::setAccount(string _account) { account = _account; };
void user::setPassword(string _password) { password = _password; };

int user::getNo() { return no; };
string user::getAccount() { return account; };
string user::getPassword() { return password; };

ostream& operator<< (ostream& out, const candidates& actor) {
	out << "---------------------------------------------------------" << endl;
	out << "1)���: " << actor.no << endl;
	out << "2)����: " << actor.name << endl;
	out << "3)���: " << actor.resume << endl;
	out << "4)֧������: " << actor.mount << endl;
	return out;
}

int candidates::getNo() const { return no; }
int candidates::getMount() const { return mount; }
string candidates::getName() const { return name; }
string candidates::getResume() const { return resume; }

void candidates::setNo(int _no) {
	no = _no;
}

void candidates::setName(string _name) {
	name = _name;
}

void candidates::setResume(string _resume) {
	resume = _resume;
}

void candidates::setMount(int _mount) {
	mount = _mount;
}

void candidates::add_Candidates(candidates info) {
	_candidates.push_back(info);
}