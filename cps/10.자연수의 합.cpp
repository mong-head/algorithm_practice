#include <string>
#include <regex>
#include <iostream>
#include <stack>
using namespace std; 

int cnt[50001]; // 전역 모두 0으로 초기화

int main(){
	int n;
	cin >> n;

	int max_sum = -1;
	int max_num = -1;
	for(int i=0;i<n;i++){
		int num, sum=0;
		cin >> num;
		int tmp = num;
		while(tmp > 0){
			sum += tmp % 10;
			tmp /= 10;
		}
		
		if(max_sum == sum && max_num < num){
			max_num = num;
		}
		if(max_sum < sum){
			max_sum = sum;
			max_num = num;
		}
	}
	cout << max_num <<endl;
	return 0;
}