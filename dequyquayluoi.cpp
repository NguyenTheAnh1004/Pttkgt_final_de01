#include <iostream>
using namespace std;
int M, N;
int W[100], Value[100], w[100], value[100], tui[100];
int vmax = 0 ,n;
void nhap() {
	cout << "Nhap so goi hang : ";
	cin >> N;
	cout << "Nhap khoi luong toi da : ";
	cin >> M;
	for (int i = 0; i < N; i++) {
		cout << "Goi hang " << i + 1 << ":" << endl;
		cout << " Khoi luong: ";
		cin >> W[i];
		cout << " Gia tri: ";
		cin >> Value[i];
		cout << endl;
	}
}


void Try(int k) {
	if (k == N) {
		int sumw = 0, sumvalue = 0;              //C1=2
		for (int i = 0; i < N; i++) {            //C2=N+1
			sumw += w[i];                        //C3=N
			sumvalue += value[i];                //C4=N
		}
		if (sumw <= M && sumvalue >= vmax) {     //C5=1
			n = 0;                               //C6=1
			vmax = sumvalue;                     //C7=1
			for (int i = 0; i < N; i++) {        //C8=N+1
				if (w[i] > 0) {                  //C9=N
					tui[n] = i;                  //C10=N
					n++;                         //C11=N
				}
			}
		}
	}
	else {
		w[k] = W[k]; value[k] = Value[k];
		Try(k + 1);
		w[k] = value[k] = 0;
		Try(k + 1);
	}
}
void Xuat() {
	cout << "Tong gia tri lon nhat la: " << vmax << endl;
	cout << "tui gom: ";
	for (int i = 0; i < n; i++) {
		cout << "goi hang " << tui[i] + 1;
		if (i < n - 1) cout << ", ";
	}
}
int main() {
	nhap();
	Try(0);
	Xuat();
}
