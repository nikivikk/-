#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[100][100];
	int count = 1;
	int row = n;
	int col = m;
	int bottom, top, right, left;
	for (int i = 0; i < n; i++) {
		for (top = i; top < m; top++) {
			a[i][top] = count;
			count++;
		}
		if (i + 1 == n) {
			break;
		}
		for (right = i + 1; right < n; right++) {
			a[right][top - 1] = count;
			count++;
		}
		m--;

		for (bottom = m - 1; bottom >= i; bottom--) {
			a[right - 1][bottom] = count;
			count++;
		}
		n--;
		for (left = n - 1; left > i && m != i; left--) {
			a[left][bottom + 1] = count;
			count++;
		}
		if (count == row * col + 1) {
			break;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}