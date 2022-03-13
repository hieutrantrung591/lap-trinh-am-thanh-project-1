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
                cout << values[i] << " ";
            }
            cout << "Chi so goc toa do: " << origin_index << endl; 
        }
};