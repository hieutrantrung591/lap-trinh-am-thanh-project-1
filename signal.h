#include <bits/stdc++.h>
using namespace std;

// Tin hieu roi rac - Discrete Signal
class DS {
    private:
        int size;
        vector<float> values;
        int origin_index;
    public:
        // Khoi tao
        DS() {
            size = 0;
        }

        // Huy
        ~DS() {}

        void input() {
        	cout << "Nhap kich thuoc cua mang:\n";
        	int s;
        	cin >> s;
        	size = s;
        	
            cout << "Nhap gia tri cua mang tin hieu:\n";
            float x;
            int i = 0;
            do {
            	cin >> x;
            	values.push_back(x);
            	i++;
			} while (i < size);

            cout << "Nhap chi so goc toa do:\n";
            int origin;
            cin >> origin;
            origin_index = origin;
        }

        void output() {
            for(int i = 0; i < values.size(); i++) {
                cout << values[i] << "; ";
            }
            cout << "\nChi so goc toa do: " << origin_index << endl; 
        }

		// Tong 2 tin hieu roi rac
		void tong(const DS& b) {

		}

		// Tich 2 tin hieu roi rac
		void tich() {

		}

		// Dich chuyen thoi gian
		void shifting() {
			cout << "Nhap gia tri thoi gian dich chuyen:\n";
			int m;
			cin >> m;

			if (m > 0) {
				origin_index = origin_index + m;
			}
			else {
				origin_index = origin_index - m;
			}
		}

		// Dao nguoc thoi gian
		void reversal() {
			reverse(values.begin(), values.end());
			origin_index = values.size() - origin_index - 1;
		}

		// Gian - tang tan so lay mau
		DS upsampling() {
			int l;
			cout << "Nhap ty so gian:\n";
			cin >> l;

			DS result;
			for(int i = 0; i <= values.size(); i++) {
				float x = values[i];
				result.values.push_back(x);
				if (i != values.size()) {
					for (int j = l; j > 1; j--) {
						result.values.push_back(0);
					}
				}	
			}
			result.size = result.values.size();
			result.origin_index = origin_index + l;
			return result;
		}

		// Nen - giam tan so lay mau
		DS downsampling() {
			int m;
			cout << "Nhap ty so nen:\n";
			cin >> m;

			DS result;
			for (int i = 0; i < values.size(); i = i + m) {
				float x = values[i];
				result.values.push_back(x); 
			}
			result.size = result.values.size();
			result.origin_index = origin_index - (m - 1);
			return result;
		}

		// Tich chap
		void tich_chap() {

		}
};