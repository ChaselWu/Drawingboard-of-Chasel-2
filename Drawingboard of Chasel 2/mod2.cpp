#include"mod2.h"

//（读取文件并）选择清屏/作画/退出
void mod2(int ylist, int xinstr, int screen_bottom,int* react_ifdraw,int* react_draw,int screen_right, int react_fileread, int xperbutton,int xline1,int yline1,int xline2,int yline2,int arcbegin,int arcend,int rcir) {
	for (int j = 1; j == 1;) {//j!=1时退出
		write_instr(20, L"欢迎您进入Chasel画板，请根据菜单选择您想进行的操作：\n1.清除屏幕\n2.作画\n3.退出", ylist,  xinstr,  screen_bottom);

		*react_ifdraw = getch();
		switch (*react_ifdraw) {

		case '1':
			clear_board(ylist, screen_right,  screen_bottom,  xinstr,  react_fileread,  xperbutton);
			write_instr(1, L"已清屏", ylist, xinstr, screen_bottom);
			write_instr(20, L"欢迎您进入Chasel画板，请根据菜单选择您想进行的操作：\n1.清除屏幕\n2.作画\n3.菜单\n4.退出", ylist, xinstr, screen_bottom);
			break;

		case '2':
			clear_instr( ylist, xinstr, screen_bottom);
			write_instr(1, L"请根据上方的指令表选择您要画的图形", ylist, xinstr, screen_bottom);
			*react_draw = getch();
			clear_instr(ylist, xinstr, screen_bottom);
			switch (*react_draw) {

			case '1':
				write_instr(1, L"画直线", ylist, xinstr, screen_bottom);
				write_instr(20, L"请输入第一个点横坐标:(按enter结束)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60,ylist);
				write_instr(80, L"请输入第一个点纵坐标：", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"请输入第二个点横坐标：", ylist, xinstr, screen_bottom);
				xline2 = coordinate(140, ylist);
				write_instr(160, L"请输入第二个点纵坐标：", ylist, xinstr, screen_bottom);
				yline2 = coordinate(180, ylist);
				line(xline1 + xinstr, yline1 + ylist, xline2 + xinstr, yline2 + ylist);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"已作图", ylist, xinstr, screen_bottom);
				break;

			case '2':
				write_instr(1, L"画矩形", ylist, xinstr, screen_bottom);
				write_instr(20, L"请输入第一个点横坐标:(按enter结束)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60, ylist);
				write_instr(80, L"请输入第一个点纵坐标：", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"请输入第二个点横坐标：", ylist, xinstr, screen_bottom);
				xline2 = coordinate(140, ylist);
				write_instr(160, L"请输入第二个点纵坐标：", ylist, xinstr, screen_bottom);
				yline2 = coordinate(180, ylist);
				rectangle(xline1 + xinstr, yline1 + ylist, xline2 + xinstr, yline2 + ylist);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"已作图", ylist, xinstr, screen_bottom);
				break;


			case '3':
				write_instr(1, L"画圆形", ylist, xinstr, screen_bottom);
				write_instr(20, L"请输入圆点横坐标:(按enter结束)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60, ylist);
				write_instr(80, L"请输入圆点纵坐标：", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"请输入半径：", ylist, xinstr, screen_bottom);
				rcir = coordinate(140, ylist);
				circle(xline1 + xinstr, yline1 + ylist, rcir);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"已作图", ylist, xinstr, screen_bottom);
				break;

			case '4':
				write_instr(1, L"画圆弧", ylist, xinstr, screen_bottom);
				write_instr(20, L"请输入圆点横坐标:(按enter结束)", ylist, xinstr, screen_bottom);
				xline1 = coordinate(60, ylist);
				write_instr(80, L"请输入圆点纵坐标：", ylist, xinstr, screen_bottom);
				yline1 = coordinate(100, ylist);
				write_instr(120, L"请输入半径：", ylist, xinstr, screen_bottom);
				rcir = coordinate(140, ylist);
				write_instr(160, L"请输入圆弧起始角：", ylist, xinstr, screen_bottom);
				arcbegin = coordinate(180, ylist);
				write_instr(200, L"请输入圆弧终止角：", ylist, xinstr, screen_bottom);
				arcend = coordinate(220, ylist);
				arc(xline1 + xinstr, yline1 + ylist, arcbegin, arcend, rcir);
				clear_instr(ylist, xinstr, screen_bottom);
				write_instr(1, L"已作图", ylist, xinstr, screen_bottom);
				break;

			case '5':

				break;
			}



			break;

		case '3':

			break;
		case '4':
			j = 0;
			break;
		}
	}
}
