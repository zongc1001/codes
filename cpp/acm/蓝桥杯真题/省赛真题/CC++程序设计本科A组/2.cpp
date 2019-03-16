#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //个位可能的数字有2 3 4 7 8 9
    int a, b, c, d, e, f;
    for(int a = 2; a <= 9; a++)
        for(int b =0; b != a && b <= 9; b++)
            for(int c = 0; c != a && c!= b && c <= 9; c++)
                for(int d = 0; d != a && d != b && d !=c && d<=9;d++)
                    for(int e = 0; e != a && e != b && e!=c && e != d && e <= 9;e++)
                        for(int f =1; f != a && f != b && f != c && f != d && f !=e && f <= 9;f++)
                        {
                            int sum = f*100000 + e * 10000 + d*1000 + c*100 + b*10 + a;
                            cout << sum << endl;
                            if(sum == 203879)
                            {
                                cout << "-------------------------------------------------------" << endl;
                            }
                            unsigned long long sq = sum * sum;
                          //  cout << "sq: " << sq << endl;
                            bool is = true;
                            while(sq != 0)
                            {
                                int temp = sq % 10;
                                sq /= 10;
                           //     cout << "temp: "<< temp << "   sq: "<< sq << endl;
                                if(temp == a || temp == b || temp ==c || temp == d ||
                                    temp == e || temp == f)
                                {
                                        is = false;
                                        break;
                                }
                            }
                            if(is)
                            {
                            //    cout << endl<<sum<<endl << endl;
                            }


                        }
   


    return 0;
}
