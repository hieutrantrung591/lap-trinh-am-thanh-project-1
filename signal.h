#include <bits/stdc++.h>
using namespace std;

class Signal {
	private:
		int rows, cols;
		float **a;
	public:
		// Ham khoi tao
		Signal(int rows = 1, int cols = 1) : cols(cols), rows(rows), a(NULL) {
			if (cols <= 0 || rows <= 0) {
				throw "Illegal argument";
			}
			a = new float*[rows];
			for (int i = 0; i < rows; i++) {
				a[i] = new float[cols];
				for (int j = 0; j < cols; j++) {
					a[i][j] = 0;
				}
			}
		}

		// Ham huy
		~Signal() {
			for(int i = 0; i < rows; i++) {
				delete[] a[i];
			}
			delete[] a;
		}

		istream& input(istream& is = cin) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cin >> a[i][j];
				}
			}
			return is;
		}

		ostream& output(ostream& os = cout) const {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << setw(10) << setprecision(5) << a[i][j] << (j < cols - 1 ? ", " : "\n");
				}
			}
			return os;
		}

		friend ostream& operator<<(ostream& os, const Signal& s) {
			return s.output(os);
		}

		friend istream& operator>>(istream& is, Signal& s) {
			return s.input(is);
		}

		// Dang la cong ma tran binh thuong
		friend Signal operator+(Signal s1, const Signal& s2) {
			if (s1.cols != s2.cols || s1.rows != s2.rows) {
				throw "Illegal argument";
			}
			
			Signal result(s1.rows, s1.cols);
			for (int i = 0; i < s1.rows; i++) {
				for (int j = 0; j < s1.cols; j++) {
					result.a[i][j] = s1.a[i][j] + s2.a[i][j];
				}
			}
			return result;
		}

		// Dang la nhan ma tran binh thuong
		friend Signal operator*(Signal s1, const Signal& s2) {
			if (s1.cols != s2.rows) {
				throw "Illegal argument";
			}

			Signal result(s1.rows, s2.cols);
			for (int i = 0; i < s1.rows; i++) {
				for (int j = 0; j < s2.cols; j++) {
					for (int k = 0; k < s1.cols; k++) {
						result.a[i][j] += s1.a[i][k] * s2.a[k][j];
					}
				}
			}
			return result;
		}
};