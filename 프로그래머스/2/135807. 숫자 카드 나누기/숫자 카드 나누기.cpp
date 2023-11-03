#include <string>
#include <vector>

using namespace std;

int gdc(int a, int b)
{
    if(b == 0) return a;
    else
    {
        return gdc(b, a % b);
    }
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int a_gdc = arrayA.size() == 1 ? arrayA[0] : gdc(arrayA[0], arrayA[1]);
    int b_gdc = arrayB.size() == 1 ? arrayB[0] : gdc(arrayB[0], arrayB[1]);

    for(int i = 2; i < arrayA.size(); i++)
    {
        a_gdc = gdc(a_gdc, arrayA[i]);
    }
    
    for(int i = 2; i < arrayB.size(); i++)
    {
        b_gdc = gdc(b_gdc, arrayB[i]);
    }
    
    if(b_gdc != 1)
    {
        for(int i = 0; i < arrayA.size(); i++)
        {
            if(arrayA[i] > b_gdc && arrayA[i] % b_gdc == 0)
            {
                b_gdc = 0;
                break;
            }
        }
    }
    else 
        b_gdc = 0;
    
    if(a_gdc != 1)
    {
        for(int i = 0; i < arrayB.size(); i++)
        {
            if(arrayB[i] > a_gdc && arrayB[i] % a_gdc == 0)
            {
                a_gdc = 0;
                break;
            }
        }
    }
    else
        a_gdc = 0;
    
    return a_gdc > b_gdc ? a_gdc : b_gdc;
}