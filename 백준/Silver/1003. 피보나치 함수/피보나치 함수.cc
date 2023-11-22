#include <iostream>
#include <vector>

using namespace std;
using std::vector;

vector<int> numvec;

int zerocnt[41];
int onecnt[41];

int main()
{
	zerocnt[0] = 1;
	zerocnt[1] = 0;
	onecnt[0] = 0;
	onecnt[1] = 1;

	for (int i = 2; i <= 40; i++)
	{
		zerocnt[i] = zerocnt[i - 1] + zerocnt[i - 2];
		onecnt[i] = onecnt[i - 1] + onecnt[i - 2];
	}

	int num;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		numvec.push_back(num);
	}

	for (int i = 0; i < n; i++)
	{
		cout << zerocnt[numvec[i]] << " " << onecnt[numvec[i]] << "\n";
	}

	return 0;
}