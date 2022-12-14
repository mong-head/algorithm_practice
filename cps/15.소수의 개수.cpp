#include <string>
#include <iostream>
#include <cmath>
using namespace std; 

/* 에라토스테네스의 체 */
bool not_prime_list[200001] = {false};

void check_prime(int n){
	for(int i=2;i<=n;i++){
		for(int j=2;i*j<=n;j++){
			not_prime_list[i*j] = true;
		}
	}
}

int main(){
	int n;
	cin >> n;
	check_prime(n);
	int result = 0;
	for(int i=2;i<=n;i++){
		if(!not_prime_list[i]) result++;
	}
	cout << result;
	
}