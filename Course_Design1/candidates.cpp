#include "summary.h"

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