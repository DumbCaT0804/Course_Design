#include "summary.h"
//ostream: "output stream"
//ofstream         文件写操作 内存写入存储设备 
//ifstream         文件读操作，存储设备读区到内存中
//fstream          读写操作，对打开的文件可进行读写操作 

ostream& operator<< (ostream& out, const user& user) {
	return out << user.no << " " << user.account << " " << user.password;
}

bool operator> (const user& user1, const user& user2) {
	return user1.no > user2.no;
}

void user::setNo(int _no) { no = _no; };	//带有user前缀既能表明是user的函数，又能引用其内的变量
void user::setAccount(string _account) { account = _account; };
void user::setPassword(string _password) { password = _password; };

int user::getNo() { return no; };
string user::getAccount() { return account; };
string user::getPassword() { return password; };

ostream& operator<< (ostream& out, const candidates& actor) {
	out << "---------------------------------------------------------" << endl;
	out << "1)编号: " << actor.no << endl;
	out << "2)名称: " << actor.name << endl;
	out << "3)简介: " << actor.resume << endl;
	out << "4)支持人数: " << actor.mount << endl;
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