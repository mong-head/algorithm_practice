#include <string>
#include <iostream>
#include <cmath>
using namespace std; 

int main(){
	long n=0;
	cin >> n;
	long result = 0;
	// 1자리수 : 1~9 (9-0 = 9, 9*(10*0))
	// 2자리수 : 10~99 (99-9 = 90, 9*(10^1))
	// 3자리수 : 100~999 (999-99 = 900, 9*(10^2))
	// 4자리수 : 1000~9999 (9999-999 = 9000)
	// 5자리수 : 10000~99999 (99999-9999 = 90000)
	
	// 자리수 구하기
	long tmp = n;
	int count = 0;
	while(tmp > 0){
		tmp /= 10;
		count++;
	}

	for(int i=1;i<count;i++){
		int subResult = 9*(pow(10,i-1))*i;
		result = result + subResult;
	}
	result = result + (n - (pow(10,count-1)-1))*count;

	cout << result <<endl;
	return 0;
}