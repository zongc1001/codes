#include <iostream>
#include <fstream>

using namespace std;

bool arr[32][52];



int main(int argc, char const *argv[])
{
    ifstream input;
    input.open("maze.text");
    char temp = 0;
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= 50 ; j++)
        {
            while(temp != '0' || temp != '1')
            {
                input >> temp;
            }
            arr[i][j] = temp == '0';
            temp = 0;
        }
    }
    
    cout << *(arr[1 * 52]) << endl;

    return 0;
}
