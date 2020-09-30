#include <iostream>
using namespace std;

void print_star(int i,int j, int size);
int main()
{
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                        print_star(i,j,n);
                }
                cout << endl;
        }

        return 0;
}
void print_star(int i,int j,int size)
{
        if((i/size)%3==1 && (j/size)%3==1) cout << ' ';
        else if(size/3 == 0) cout << "*";
        else print_star(i,j,size/3);
}
