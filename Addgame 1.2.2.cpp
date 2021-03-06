// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
bool pr = 1;
int z, g, h, la, r1, r2, a, b, c, d, tr = 0, bst = 0, winner = -1;
char st;
int chs(int x, int y) {//伪随机数生成器
	if (x == 0)return y;
	if (y == 0)return x;
	if (y > x) {
		z = y;y = x;x = z;//交换
	}
	pr = (!pr);
	if (pr)return x;else return y;
}
int start() {//开始游戏
	cout << "press S to start, press any other key to exit\nBest score:" << tr << "turns" << endl;
	cin >> st;
	if (st == 's')return 1;else return 0;
}
void num(int n1, int n2, int n3, int n4) {//输出数字
	cout << "AI's number:" << n1 << ' ' << n2 << "\nYour number:" << n3 << " " << n4 << endl;
}
void aiact() {//ai回合
	num(a, b, c, d);
	r1 = chs(a, b);
	r2 = chs(c, d);
	if (r1 == a)a += r2;else b += r2;//加法
	cout << "computer:" << r1 << '+' << r2 << '=' << r1 + r2 << '\n';
	if (a >= 10)a = a - 10;
	if (b >= 10)b = b - 10;
	tr++;//回合计数器+1
}
void playeract() {//玩家回合
	num(a, b, c, d);
	cout << "input 0 to choose the left number for you, or input 1 to choose the right one\n";
	while (true) {
		cin >> g;
		if (g != 0 && g != 1)cout << "wrong input\n";else {
			if ((g == 0 && c == 0) || (g == 1 && d == 0))cout << "You can't choose a 0\n";else break;
		}
	}//等待输入
	cout << "input 0 to choose the left number for the computer, or input 1 to choose the right one\n";
	while (true) {
		cin >> h;
		if (h != 0 && h != 1)cout << "wrong input\n";else {
			if ((h == 0 && a == 0) || (h == 1 && b == 0))cout << "You can't choose a 0\n";else break;
		}
	}
	if (g + h == 0)c += a;
	if (g + h == 2)d += b;
	if (g == 0 && h == 1)c += b;
	if (g == 1 && h == 0)d += a;//加法
	if (c >= 10)c = c - 10;
	if (d >= 10)d = d - 10;
	tr++;//回合计数器+1
}
int main() {
	cout << "更新日志\n"
		<< "13:14 11.May 2019 " << "Alpha 1.0.0: " << "修复了ai无法获胜的问题" << '\n'
		<< "13:22 11.May 2019 " << "Alpha 1.1.1: " << "更新日志上线。修复了无法刷新最高分的问题，改动了部分语法" << '\n'
		<< "13:27 11.May 2019 " << "Alpha 1.2.1: " << "加入了游戏时间过长时的平局机制" << '\n'
		<< '\n';
	while (true) {
		a = 1;b = 1;c = 1;d = 1;tr = 0;
		if (!start())return 0;
		do {
			playeract();
			if (c == 0 && d == 0) {
				winner = 1;break;
			}
			aiact();
			if (a == 0 && b == 0) {
				winner = 0;break;
			}
		} while (winner<0 || tr>=120);//胜负判断
		if (winner==0) {
			cout<<"computer won\nAt round: "<<tr<<"\nAgain?";
		}
		else if(winner==1){
			cout << "You won!\nAt round: " << tr << endl;
			if (tr < bst && winner==1)cout << "New Best score!\n";
			cout << "Again?\n";
		}
		else if (winner == -1) {
			cout << "Draw\n"<< "Again?\n";;
		}
		else cout << "An unexpected error is detected. Please report it to the developer. Thank you." << "Again?\n";
	}
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
