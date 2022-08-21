#include <string>
#include <regex>
#include <iostream>
#include <stack>
using namespace std; 

int cnt[50001]; // 전역 모두 0으로 초기화

int main(){
	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		// i를 약수로 가지는 것들
		for(int j=i;j<=n;j=j+i){
			cnt[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout << cnt[i] << " ";
	}
	cout << endl;
	return 0;
}