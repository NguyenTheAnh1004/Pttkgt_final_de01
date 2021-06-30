#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
int M, N, n;
int W[100], value[100], tui[100], dp[100][100];
int kq=0;
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
		cin >> value[i];
		cout << endl;
	}
}

void caituiqhd() {
	//Tim gia tri lon nhat
	for (int i = 1; i <= N; i++) {                                                        //C1=N+1
		for (int j = 1; j <= M; j++) {                                                    //C2=N(M+1)
				if (j < W[i - 1]) {                                                       //C3=N*M
					dp[i][j] = dp[i - 1][j];                                              //C4=N*M
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + value[i - 1]); //C5=N*M
					kq= max(kq,dp[i][j]);                                                 //C6=N*M
				}
			
		}
	}
	
	// Xac dinh cac mon hang duoc chon
	n = 0; int Mtemp = M;                                                                  //C7=2
	for (int i = N; i >= 1; i--) {                                                         //C8=N+1
		if (dp[i][Mtemp] != dp[i - 1][Mtemp]) {                                            //C9=N
			tui[n] = i;                                                                    //C10=N
			Mtemp = Mtemp - W[i - 1];                                                      //C11=N
			n++;                                                                           //C12=N
		}
		else continue;                                                                     //C13=N
	}
		
}
void Xuat() {
	
	cout << "Tong gia tri lon nhat la: " << dp[N][M] << endl;
	cout << "trong tui gom: ";
	for (int i = 0; i < n; i++) {
		cout << "goi hang " << tui[i];
		if (i < n - 1) cout << ", ";
	}
}



int main() {
	nhap();
	caituiqhd();
    Xuat();
}
