#include<iostream>

using namespace std; 

int main(){
	int n;
	cin >> n;

	int max_age = 0;
	int min_age = 1000;
	int age;
	for(int i=0;i<n;i++){
		cin >> age;
		if(age > max_age) max_age = age;
		if(age < min_age) min_age = age;
	}
	cout << max_age - min_age << endl;
	return 0;
}