//Prim算法
//#include<iostream>
//using namespace std;
//#define Vmax 100
//int v[Vmax];
//bool isEmpty(int v[], int length) {
//	for (int i = 1; i < length; i++) {
//		if (*(v + i) == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//int main() {
//	int Vnumber, Enumber, i, j;
//	int x[Vmax][Vmax];
//	int a, b, c;
//	cout << "输入结点个数和边条数:";
//	cin >> Vnumber >> Enumber;
//	cout << "分别输入两个结点和结点之间的距离：\n";
//	for (i = 0; i < Vnumber + 1; i++) {
//		for (j = 0; j < Vnumber + 1; j++) {
//			x[i][j] = 0;
//		}
//	}
//	for (i = 0; i < Enumber; i++) {
//		cin >> a >> b >> c;
//		x[a][b] = c;
//		x[b][a] = c;
//	}
//	cout << "最小生成树为：\n";
//	for (i = 0; i < Vnumber + 1; i++) {
//		v[i] = 0;
//	}
//	v[1] = 1;
//	int min, p, q;
//	while (!isEmpty(v, Vnumber)) {
//		min = 100;
//		for (i = 1; i < Vnumber + 1; i++) {
//
//			if (v[i] == 1) {
//				for (j = 1; j < Vnumber + 1; j++) {
//					if (x[i][j] != 0 && x[i][j] < min && v[j] != 1) {
//						min = x[i][j];
//						q = i;
//						p = j;
//					}
//				}
//			}
//		}
//		v[p] = 1;
//		x[q][p] = 0;
//		x[p][q] = 0;
//		cout << "(" << q << "," << p << ")" << endl;
//	}
//	return 0;
//}


//Kruskal算法
#include<iostream>
using namespace std;
#define Vmax 100
#define Emax 100
struct edge
{
	int x;
	int y;
	int w;
};
int main() {
	int Vnumber, Enumber, i, j;
	struct edge E[Emax], t;
	int p, q;
	int agg[Vmax];
	int k = 1, l = 1;
	int s1, s2;
	cout << "输入结点个数和边条数:";
	cin >> Vnumber >> Enumber;
	cout << "分别输入两个结点和结点之间的距离：\n";
	for (i = 1; i < Enumber + 1; i++) {
		cin >> E[i].x >> E[i].y >> E[i].w;
	}
	for (i = 1; i < Enumber; i++) {
		for (j = 1; j < Enumber + 1 - i; j++) {
			if (E[j].w > E[j + 1].w) {
				t = E[j];
				E[j] = E[j + 1];
				E[j + 1] = t;
			}
		}
	}
	for (i = 1; i < Vnumber + 1; i++) {
		agg[i] = i;
	}
	while (k < Vnumber) {
		p = E[l].x;
		q = E[l].y;
		s1 = agg[p];
		s2 = agg[q];
		if (s1 != s2) {
			cout << "(" << p << "," << q << ")" << endl;
			for (i = 1; i < Vnumber + 1; i++) {
				if (agg[i] == s2) {
					agg[i] = s1;
				}
			}
			k++;
		}
		l++;
	}
	return 0;
}




//例1
/*6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6*/
//结果1
/*(1,3)
(3,6)
(6,4)
(3,2)
(2,5)*/

//例2
/*6 8
1 2 80
2 3 90
3 4 10
4 5 60
5 6 40
6 1 20
1 4 100
3 6 70*/
//结果2
/*(1,6)
(6,5)
(5,4)
(4,3)
(1,2)*/