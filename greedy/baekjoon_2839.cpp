#include <iostream>

using namespace std;

int main()
{
        int N; //무게
        cin >> N;

        int num_5 = N/5;
        int tmp;
        for(; num_5>0; num_5--)
        {
                tmp = N;
                tmp = tmp - 5*num_5;
                if(tmp%3 == 0)
                {
                        cout << num_5 + tmp/3;
                        break;
                }
        }

        if(num_5 == 0)
        {
                if(N%3 == 0)
                        cout << N/3;
                else
                        cout << -1;
        }

        return 0;
}
