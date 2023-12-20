//#include "test.h"
//#include <iostream>
//#include <ostream>
//using namespace std;
//
//struct classTime {
//	int x;
//};
//
//int main() {
//	ostream& operator<< (ostream & out, const classTime & rhs)
//	{
//		//out << "(" << rhs.classWeek << " " << rhs.week << " " << rhs.section << ")";
//		out << "第" << rhs.classWeek << "周周" << rhs.week << "第" << rhs.section << "大节";
//		return out;
//	}
//
//	bool operator== (const classTime & lhs, const classTime & rhs)
//	{
//		if (lhs.classWeek == rhs.classWeek && lhs.week == rhs.week && lhs.section == rhs.section)
//			return 1;
//		return 0;
//	}
//
//	bool operator!= (const classTime & lhs, const classTime & rhs) { return !(lhs == rhs); }
//
//	//预约信息类
//	ostream& operator<< (ostream & out, const OrderInfo & rhs)
//	{
//		out << " ";
//		out << rhs.m_time.classWeek << " " << rhs.m_time.week
//			<< " " << rhs.m_time.section << " "
//			<< rhs.m_ID << " " << rhs.m_name << " "
//			<< rhs.m_phoneNum;
//		return out;
//	}
//	cout << "Hello, World";
//	return 0;
//}