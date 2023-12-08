#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

	for (int i = 1; i <= r2; i++)
    {
		int _r1_x = 0;
		int _r2_x = floor(sqrt((long long)r2 * r2 - (long long)i * i));

		if (r1 >= i)
			_r1_x = ceil(sqrt((long long)r1 * r1 - (long long)i * i));

		answer += _r2_x - _r1_x + 1;
	}

	return answer * 4;
}