// five.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int putt[25][25], turn = 0, row, xc, i, j, k, w, winner, px = -1, py = -1, st;
void field() {
	for (i = 0;i < 20;i++) {
		for (j = 0;j < 20;j++) {
			if (putt[i][j] == -1)cout << '.';
			else if (putt[i][j] == 0)cout << 'o';
			else if (putt[i][j] == 1)cout << 'x';else cout << 'E';
		}cout << '\n';
	}cout << '\n';
}
int win() {
	row = -1;
	xc = row;
	w = 0;
	for (i = 0;i < 20;i++) {
		for (j = 0;j < 20;j++) {
			row = putt[i][j];
			if (row != -1) {
				if (j < 15) {
					for (k = 1;k < 5;k++) {
						if (putt[i][j + k] != row)break;
						if (k == 4)w = 1;
					}
				}
				if (i < 15) {
					for (k = 1;k < 5;k++) {
						if (putt[i + k][j] != row)break;
						if (k == 4)w = 1;
					}
				}
				if (i < 15 && j < 15) {
					for (k = 1;k < 5;k++) {
						if (putt[i + k][j + k] != row)break;
						if (k == 4)w = 1;
					}
				}
				if (i > 4 && j < 15) {
					for (k = 1;k < 5;k++) {
						if (putt[i - k][j + k] != row)break;
						if (k == 4)w = 1;
					}
				}
				if (w&&row == 0)return 1;else if (w&&row == 1)return 2;
			}
		}
	}
	return 0;
}
void act(int f) {
	st = 0;
	if (!f)cout << "circle's";else cout << "cross'";
	cout << " turn:" << turn << endl;
	cout << "where do you want to put your piece? input coordinates:(row, array)from 0 to 19" << endl;
	while (px < 0 || py < 0 || putt[px][py] != -1) {
		if (st)cout << "this position is unavailable" << endl;
		cin >> px >> py;
		if (!st)st = 1;
	}
	putt[px][py] = f;
	cout << '(' << px << ',' << py << ')' << endl;
	field();
	px = -1;
	py = -1;
}
void initialize() {
	for (i = 0;i < 20;i++) {
		for (j = 0;j < 20;j++) {
			putt[i][j] = -1;
		}
	}
}
int main() {
	initialize();
	field();
	cout << "circle goes first" << endl;
	while (turn <= 150) {
		turn++;
		act(0);
		if (win()) { winner = 0;break; }
		act(1);
		if (win()) { winner = 1;break; }
	}
	if (winner) cout << "cross wins at turn:" << turn << endl; else cout << "circle wins at turn:" << turn << endl;
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
