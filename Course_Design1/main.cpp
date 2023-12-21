#include "summary.h"

int main() {
	//
	//ifstream in("Data/user.txt", std::ios::in);
	////代表文件存在
	//	int n = 0;
	//	in >> n;

	//	user* u1 = new user[n + 1];
	//	for (int i = 1; i <= n; i++) {
	//		int no;
	//		string account, password;
	//		in >> no >> account >> password;
	//		u1[i].setNo(no); u1[i].setAccount(account); u1[i].setPassword(password);
	//	}
	//	cout << n << endl;
	//	in.close();
	//	user* head = u1;
	//	int number = n;
	//	for (int i = 1; i <= number; i++) {
	//		int index = 1;
	//		for (int j = 2; j <= number - i + 1; j++) {
	//			if (head[j] > head[index])
	//				index = j;
	//		}
	//		user x;
	//		x = head[index];
	//		head[index] = head[number - i + 1];
	//		head[number - i + 1] = x;
	//		cout << index <<" " << head[index].getNo() << "置换为: " << number - i + 1 << " "<< head[number - i + 1].getNo() << endl;
	//	}
	//	ofstream fout("Data/user.txt");
	//	fout << number << endl;
	//	for (int i = 1; i <= number; i++)
	//		fout << head[i].getNo() << " " << head[i].getAccount() << " " << head[i].getPassword() << endl;
	//	fout.close();
	Begin();
	getchar();
	select_Identity();

	//string name = "稿子好";
	//cout << name;
	//cout << "Hello, World" << endl;

	return 0;
}