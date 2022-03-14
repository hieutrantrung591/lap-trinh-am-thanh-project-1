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
			values.clear();
        }

        // Huy
        ~DS() {}

        void input() {
        	cout << "\nNhap kich thuoc cua mang tin hieu: ";
        	int s;
        	cin >> s;
        	size = s;
        	
            cout << "\nNhap gia tri cua mang tin hieu:\n";
            float x;
            int i = 0;
            do {
            	cin >> x;
            	values.push_back(x);
            	i++;
			} while (i < size);

            cout << "\nNhap chi so goc toa do: ";
            int origin;
            cin >> origin;
            origin_index = origin;
        }

        void output() {
            for(int i = 0; i < values.size(); i++) {
				if (values[i] != 0) {
					cout << values[i] << "; ";
				}                
            }
            cout << "\nChi so goc toa do: " << origin_index << endl; 
        }

		// Tong 2 tin hieu roi rac
		DS tong(const DS& b) {
			DS kq;
			int n = 0, k = 0, i = 0, o1 = origin_index, o2 = b.origin_index;
			n = max(o1,o2) + max(size-o1, b.size-o2);
			int j = 0;
			do {
				kq.values.push_back(0);
				j++;
			} while (j < n);
			i = max(o1,o2);
			kq.origin_index=i;
			while(o1 - k >= 0 || o2 - k >= 0){
				if(o1 - k >= 0 && o2 - k >= 0)
					kq.values[i] = (values[o1 - k] + b.values[o2 - k]);
				else if(o1 - k >= 0)
					kq.values[i] = (values[o1 - k]);
				else
					kq.values[i] = (b.values[o2 - k]);
				i--;
				k++;
			}
			i = max(o1,o2);
			k = 0;
			while(o1 + k < size || o2 + k < b.size){
				if(o1 + k < size && o2 + k < b.size)
					kq.values[i] = (values[o1+k] + b.values[o2+k]);
				else if(o1+k<size)
					kq.values[i] = (values[o1+k]);
				else
					kq.values[i] = (b.values[o2+k]);
				i++;
				k++;
			}
			kq.size = i;
			return kq;
		}

		// Tich 2 tin hieu roi rac
		DS tich(const DS& b) {
			DS kq;
			int n = 0, k = 0, i = 0, o1 = origin_index, o2 = b.origin_index;
			n = max(o1,o2) + max(size-o1, b.size-o2);
			int j = 0;
			do {
				kq.values.push_back(0);
				j++;
			} while (j < n);
			i = max(o1,o2);
			kq.origin_index=i;
			while(o1 - k >= 0 || o2 - k >= 0){
				if(o1 - k >= 0 && o2 - k >= 0)
					kq.values[i] = (values[o1 - k] * b.values[o2 - k]);
				else
					kq.values[i] = 0;
				i--;
				k++;
			}
			i = max(o1,o2);
			k = 0;
			while(o1 + k < size || o2 + k < b.size){
				if(o1 + k < size && o2 + k < b.size)
					kq.values[i] = (values[o1+k] * b.values[o2+k]);
				else
					kq.values[i] = 0;
				i++;
				k++;
			}
			kq.size = i;
			return kq;
		}

		// Nhan tin hieu voi 1 hang so
		void tich_hang() {

		}

		// Dich chuyen thoi gian
		void shifting() {
			cout << "\nNhap gia tri thoi gian dich chuyen: ";
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
			cout << "\nNhap ty so gian: ";
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
			cout << "\nNhap ty so nen: ";
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

		// Tuong quan cheo
		void tuong_quan_cheo() {

		}
};

void menu() {
	cout << "CHUONG TRINH XU LY TIN HIEU ROI RAC HUONG DOI TUONG\n";
	cout << "*************************MENU**************************\n";
	cout << "**  1. Nhap 2 tin hieu.                              **\n";
	cout << "**  2. Cong 2 tin hieu.					          **\n";
	cout << "**  3. Nhan 2 tin hieu.	                          **\n";
	cout << "**  4. Nhan tin hieu voi 1 hang so.                  **\n";
	cout << "**  5. Dich thoi gian.								  **\n";
	cout << "**  6. Dao thoi gian.                   			  **\n";
	cout << "**  7. Tang tan so lay mau (upsampling).             **\n";
	cout << "**  8. Giam tan so lay mau (downsampling).           **\n";
	cout << "**  9. Tich chap.                                    **\n";
	cout << "**  10. Tuong quan cheo giua 2 tin hieu.             **\n";
	cout << "**  0. Thoat.                                        **\n";
	cout << "*******************************************************\n";
	cout << "Nhap tuy chon: ";
}