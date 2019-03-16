#include <iostream>

using namespace std;

struct obj
{
    int cor;  //正确价格
    int err;  //错误价格
    int sub;  //差价
};


obj ans1[10000];
obj ans2[10000];

int main(int argc, char const *argv[])
{
    int num[10] = {1, 2, 5, 6, 8, 9 ,0};
    int cou[10] = {1, 2, 5, 9, 8, 6, 0};
    
    int index1 = 0;
    int index2 = 0;

    for(int a= 0; a < 6;a++)
        for(int b = 0; b < 7;b++)
            for(int c = 0; c < 7;c++)
                for(int d = 0; d < 6;d++)
                {
                    int temp1 = num[a]*1000 + num[b]*100 + num[c]*10 + num[d];  //正确价格
                    int temp2 = cou[a] + cou[b]*10 + cou[c]*100 + cou[d]*1000;
              //      cout << temp1 << "   " << temp2 << endl;
                    
                    if(temp1 - temp2 >= 200 && temp1 -temp2 <300)
                    {
                        ans1[index1].cor = temp1;
                        ans1[index1].err = temp2;
                        ans1[index1].sub = temp1 - temp2;
                        index1++;
                        
                    }
                    if(temp2 - temp1 >= 800 && temp2 -temp1 <900)
                    {
                        ans2[index2].cor = temp1;
                        ans2[index2].err = temp2;
                        ans2[index2].sub = temp2 - temp1;
                        index2 ++;
                        
                    }
                }
    // for(int i = 0; i < index1;i++)
    //     cout << ans1[i].cor << "   " << ans1[i].err << "   " << ans1[i].sub << endl;


    for(int i = 0; i < index1;i++)
        for(int j = 0; j < index2;j++)
        {
            if(ans2[j].sub - ans1[i].sub == 558)
            {
                cout << ans1[i].cor << "   "<< ans2[j].cor << endl;
            }
        }




    return 0;
}
