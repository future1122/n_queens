// n_Queens.cpp : 定义控制台应用程序的入口点。
//添加注释。。。。
//添加另一行注释
#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
int queenArr[20][20] = {};
int judge[20] = {};
int nSolution = 0;
bool isChange;
void showSolution(int n)
{
	cout << ".................Solution " << nSolution << " ............." << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << queenArr[i][j];
		}
		cout << endl;
	}
	cout << ".................................................." << endl;
}
bool isOk(int judge[],int n) {
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++) {
			if (judge[i] == judge[j]) return false;
			if (abs(judge[i] - judge[j]) == abs(i - j) || judge[i] + i == judge[j] + j) return false;
		}
	return true;
}
void setQueens(int changeLen,int n) {
	for (int i = 0; i < n; i++) {
		queenArr[changeLen][i] = 1;
		judge[changeLen] = i;
		isChange = true;
		if (changeLen < n-1) {
			setQueens(changeLen + 1,n);
		}
		/*判断每一个解决放哪是否符合题意*/
		if (isOk(judge,n) && isChange) {
			nSolution++;
			showSolution(n);
		}
		queenArr[changeLen][i] = 0;
		isChange = false;
	}
	/*changeLen -= 1;*/
}
int main()
{
	/*for (int i = 0; i < 8; i++)
	queenArr[i][i] = 1;*/

	/*showSolution(queenArr,nSolution);*/
	int n;
	cout << " Please enter the n (n<=20)of n_queens problem!" << endl;
	cin >> n;
	if (n > 20|| n <= 0) {
		cout << "wrong input!  0 < n <=20!!!" << endl;
		cin >> n;
	}
	setQueens(0,n);
	if (nSolution == 0)
		cout << "There is no answer!!!" << endl;

	return 0;
}
