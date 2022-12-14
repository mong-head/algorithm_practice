#include <string>
#include <iostream>
#include <cmath>
using namespace std; 

int reverse(int x){
	int reverse_num = 0;
	while(x != 0){
		int current_num = x % 10;
		x /= 10;
		reverse_num *= 10;
		reverse_num += current_num;
	}
	return reverse_num;
}

bool isPrime(int x){
	if(x <= 1){
		return false;
	}
	int sqrt_x = sqrt(x);
	for(int i=2;i<=sqrt_x;i++){
		if(x%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;

	string result = "";
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		int reverse_num = reverse(num);
		if(isPrime(reverse_num)){
			result.append(to_string(reverse_num)).append(" ");
		}
	}
	result.pop_back();
	cout << result <<endl;

	return 0;
}