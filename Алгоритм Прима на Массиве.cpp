#include <iostream>
#include <vector>

#include <set>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	// входные данные
	int n = 0;
	cout << "Введите количество вершин: ";
	cin >> n;
	const int INF = 100000; // значение "бесконечность"


	//vector < vector<int> > g(n);
	//int g[10][10] = { 0 };
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cin >> g[i][j];
	//		if (g[i][j] == 0) {
	//			g[i][j] = INF;
	//		}
	//	}
	//}
	vector < vector<int> > g = {
  { INF, 10, INF, 11},
  { 10, INF, 9, 5},
  { INF, 9, INF, 8},
  { 11, 5, 8, INF }
	};
	//vector < vector<int> > g = {
 // {INF, 9, 75, INF, INF},
 // {9, INF, 95, 19, 42},
 // {75, 95, INF, 51, 66},
 // {INF, 19, 51, INF, 31},
 // {INF, 42, 66, 31, INF}
	//};

	
	unsigned int start_time = clock(); // начальное время
	// алгоритм
	vector<bool> used(n, false);
	vector<int> min_e(n, INF), sel_e(n, -1);
	min_e[0] = 0;
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INF) {
			cout << "No MST!";
			exit(0);
		}

		used[v] = true;
		if (sel_e[v] != -1)
			cout  << sel_e[v] + 1 << "---" << v + 1 <<endl;

		for (int to = 0; to < n; ++to)
			if (g[v][to] < min_e[to]) {
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
		
	}
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	cout << "Время " << search_time << endl;

}
