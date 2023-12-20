#pragma once
class candidates
{
	friend ostream& operator<< (ostream&, const candidates&);
private:
	int no;
	string name;
	string resume;	//¼ò½é
	int mount;
	vector<candidates> _candidates;

public:
	candidates() = default;
	candidates(const int& _no, const string& _name, const string& _resume):
		no(_no), name(_name), resume(_resume) {}

	int getNo() const;
	string getName() const;
	string getResume() const;
	int getMount() const;
	void setNo(int _no);
	void setName(string _name);
	void setResume(string _resume);
	void setMount(int _mount);
	void add_Candidates(candidates info);
};

