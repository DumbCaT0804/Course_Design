#pragma once

struct user {
private:
	int no;
	string account;
	string password;
public:
	friend ostream& operator<< (ostream&, const user&);
	friend bool operator > (const user& user1, const user& user2);
	user() = default;
	user(int _no, string _account, string _password) : no(_no), account(_account), password(_password) {}
	void setNo(int _no);
	void setAccount(string _account);
	void setPassword(string _password);
	int getNo();
	string getAccount();
	string getPassword();
};
/*
	std::vector<user> userContainer;

	// 创建 user 实例并添加到容器中
	userContainer.push_back(user(1, "user1", "password1"));
	userContainer.push_back(user(2, "user2", "password2"));
	userContainer.push_back(user(3, "user3", "password3"));
*/

class candidates
{
	friend ostream& operator<< (ostream&, const candidates&);
private:
	int no;
	string name;
	string resume;	//简介
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

