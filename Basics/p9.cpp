#include <iostream>
using namespace std;
int main() {
		int n;
		cin >> n;

		for(int i=0;i<n;i++) {
				for(int j=0;j<n-i-1;j++) {
						cout << " ";
				}

				for(int k=0;k<2*i+1;k++) {
						cout << "*";
				}
				for(int j=0;j<n-i-1;j++) {
						cout << " ";
				}
				cout << "\n";

				
		}
		for(int m=n;m>=0;m--) {
				for(int j=0;j<n-m-1;j++) {
						cout << " ";
				}

				for(int k=0;k<2*m+1;k++) {
						cout << "*";
				}
				for(int j=0;j<n-m-1;j++) {
						cout << " ";
				}
				cout << "\n";
				
		}
		return 0;
}
