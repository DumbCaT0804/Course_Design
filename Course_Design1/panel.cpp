#include "summary.h"

void select_Identity() {//��¼����
	IMAGE img;
	initgraph(1200, 700);
	HWND hwnd;// ���ô��ھ���������洰����Ϣ
	hwnd = GetHWnd();// ��ȡ���ھ��
	SetWindowText(hwnd, _T("����ͶƱϵͳ 2.0"));
	loadimage(&img, _T("��¼����.png"), 1200, 700);
	putimage(0, 0, &img);
	//������¼�����
	MOUSEMSG msg;// ������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ������	
	while (1) { // ��ѭ�� ѭ�����������Ϣ
		while (MouseHit())// ���������Ϣ ���������Ϣ��ʱ��ִ�� �ɼ�������������Ϣ
		{
			msg = GetMouseMsg();// ��ȡ�����Ϣ
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 961 && msg.y >= 245 && msg.y <= 273) {
				//����Ա��¼
				admin_System_Login();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 961 && msg.y >= 315 && msg.y <= 340) {
				//ͶƱ�˵�¼
				closegraph();
				user_System_Login();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 871 && msg.y >= 378 && msg.y <= 405) {
				//�˳�
				closegraph();
				goto label;
			}
		}
	}
label:return;
}

void admin_System_Panel() {
	IMAGE img;
	initgraph(1200, 700);//����
	loadimage(&img, _T("����Ա�˵�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("����ͶƱϵͳϵͳ 2.0"));
labelStart:
	MOUSEMSG msg;// ������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ������
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1060 && msg.y >= 240 && msg.y <= 272) {
				//��ʼ����ѡ����Ϣ
				closegraph();
				init_candidates_information();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 970 && msg.y >= 306 && msg.y <= 335) {
				//�����ѡ����Ϣ
				closegraph();
				scan_candidates_information(1);
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 970 && msg.y >= 374 && msg.y <= 405) {
				//�޸�ͶƱ����Ϣ
				closegraph();
				modify_candidates_panel();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1000 && msg.y >= 444 && msg.y <= 469) {
				//��ѯͶƱ���
				closegraph();
				/*FindInformation();*/
				scan_candidates_information(2);
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 819 && msg.x <= 1000 && msg.y >= 505 && msg.y <= 536) {
				//ͶƱ��Ϣ����
				MessageBox(hwnd, _T("��������ɹ�����QAQ"), _T("����ɹ�"), MB_OK);
				clear_vote_information();
				admin_System_Panel();
				/*ProcessingData();*/
				goto labelTeachersMenu;
			}

			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 811 && msg.x <= 1000 && msg.y >= 569 && msg.y <= 606) {
				//�����û�Ȩ��
				closegraph();
				user_manager_panel();
				goto labelTeachersMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 874 && msg.y >= 642 && msg.y <= 670) {
				//�˳�ϵͳ
				closegraph();
				select_Identity();
				goto labelTeachersMenu;
			}
		}
	}
labelTeachersMenu:
	return;
}

void user_manager_panel() {
	IMAGE img;
	initgraph(1200, 700);//����
	loadimage(&img, _T("�����û�Ȩ��.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("����ͶƱϵͳϵͳ 2.0"));
labelStart:
	MOUSEMSG msg;// ������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ������
	while (1) {
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 991 && msg.y >= 244 && msg.y <= 270) {
				//��ʼ�����û�
				closegraph();
				init_new_user();
				user_manager_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 1027 && msg.y >= 306 && msg.y <= 337) {
				//�����û�Setting
				closegraph();
				change_user_setting();
				user_manager_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 371 && msg.y <= 403) {
				//�����û�
				closegraph();
				add_user_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 442 && msg.y <= 470) {
				//ɾ���û�
				closegraph();
				delete_user();
				/*FindInformation();*/
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 816 && msg.x <= 932 && msg.y >= 506 && msg.y <= 536) {
				//��ѯ�û�
				query_user_panel();
				/*ProcessingData();*/
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 814 && msg.x <= 879 && msg.y >= 568 && msg.y <= 604) {
				//����
				closegraph();
				sort_user_panel();
				goto labelAdminMenu;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 808 && msg.x <= 875 && msg.y >= 634 && msg.y <= 671) {
				closegraph();
				admin_System_Panel();
				goto labelAdminMenu;
			}
		}
	}
labelAdminMenu:
	return;
}

void user_System_Panel() {
	IMAGE img;
	initgraph(1200, 700, NOCLOSE);
	loadimage(&img, _T("ͶƱ�˲˵�.png"), 1200, 700);
	putimage(0, 0, &img);
	HWND hwnd;
	hwnd = GetHWnd();
	SetWindowText(hwnd, _T("ѧ���ɼ�����ϵͳ 2.0"));
	MOUSEMSG msg;
	FlushMouseMsgBuffer(); //��������Ϣ������
	while (1) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 809 && msg.x <= 878 && msg.y >= 236 && msg.y <= 274) {
				//ͶƱ	
				user_vote();
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 810 && msg.x <= 1030 && msg.y >= 302 && msg.y <= 344) {
				//���ͶƱ����Ϣ
				scan_candidates_information(1);
				goto label;
			}
			else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 813 && msg.x <= 882 && msg.y >= 369 && msg.y <= 409) {
				//�Ƴ�
				select_Identity();
				goto label;
			}
		}

	}
label:return;
}