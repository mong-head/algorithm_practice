#include <string>
#include <iostream>
#include <cmath>
using namespace std; 

int main(){
	string n;
	cin >> n;

	int count[10] = {0,};
	for(int i=0;i<n.length();i++){
		count[n[i]-'0']++;
	}
	
	int max = 0;
	int max_index = 0;
	for(int i=0;i<size(count);i++){
		if(max <= count[i]){
			max = count[i];
			max_index = i;
		}
	}
	cout << max_index << endl;

	return 0;
}