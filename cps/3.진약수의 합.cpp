#include<iostream>

using namespace std; 

int main(){
	int n;
	int sum = 1;
	cin >> n;

	// 진약수 : 어떤 자연수 n의 약수들 중에서 자기 자신인 n을 제외한 약수를 진약수(proper divisor)라고 한다.
	cout << sum;
	for(int i=2;i<n;i++){
		if(n%i == 0){
			sum += i;
			cout << " + " << i;
		}
	}
	cout << " = " << sum << endl;
	return 0;
}