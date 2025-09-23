#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    vector<int> result;
    while (true)
    {
        cin >> a >> b;
        if (a <= 0)
            break;
        result.push_back(a + b);
    }

    for (auto& sum : result)
    {
        cout << sum << endl;
    }
    return 0;
}