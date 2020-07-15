//https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Format
{
    string origin;
    vector<char> res;
    int posOfPoint;
    int numStart;
    int rank;

    void init(int saveNum)
    {
        bool isZero = true;
        for(int i = 0; i < origin.size();i++)
        {
            if(origin[i] != '0' && origin[i] != '.')
            {
                isZero = false;
                break;
            }
        }
        // cout <<"isZero: " << isZero << endl;

        if (!isZero)
        {
            int tempPointPos = 0;
            int numStartFound = 0;
            int posOfPointFound = 0;
            for (tempPointPos; tempPointPos < origin.size(); tempPointPos++)
            {
                if (!numStartFound && origin[tempPointPos] != '0' && origin[tempPointPos] != '.')
                {
                    numStartFound = 1;
                    numStart = tempPointPos - posOfPointFound;
                }
                if (numStartFound && res.size() < saveNum && origin[tempPointPos] != '.')
                {
                    // cout<< "here" << endl;
                    res.push_back(origin[tempPointPos]);
                }
                if (origin[tempPointPos] == '.')
                {
                    posOfPointFound = 1;
                    posOfPoint = tempPointPos;
                }
            }
            if (!posOfPointFound)
                posOfPoint = tempPointPos;
            if (!numStartFound)
                numStart = 0;
        }
        else
        {
            numStart = 0;
            posOfPoint = 0;
        }
        while (res.size() < saveNum)
        {
            res.push_back('0');
        }
        rank = posOfPoint - numStart;
    }
};

int n;

void printNum(Format &obj)
{
    cout << "0.";
    for (int i = 0; i < n; i++)
        cout << obj.res[i];
    cout << "*10^" << obj.rank;
}
int main(int argc, char const *argv[])
{

    cin >> n;
    Format a, b;
    string temp[2];
    
    cin >> a.origin >> b.origin;
    

    a.init(n);
    b.init(n);


    // cout << "a.origin: " << a.origin << endl
    //      << "a.numStart: " << a.numStart << endl
    //      << "a.posOfPoint: " << a.posOfPoint << endl
    //      << "a.rank: " << a.rank << endl;

    bool yes = true;

    for (int i = 0; i < n; i++)
    {
        if (a.res[i] != b.res[i])
        {
            yes = false;
            break;
        }
    }

    if (yes && a.rank == b.rank)
    {
        cout << "YES ";
        printNum(a);
    }
    else
    {
        cout << "NO ";
        printNum(a);
        cout << " ";
        printNum(b);
    }
    cout << endl;
    return 0;
}
