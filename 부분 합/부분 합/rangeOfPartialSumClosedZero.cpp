#include <iostream>
using namespace std;

int main() {
	양수와 음수가 모두 포함된 배열 A[]가 있을 때, 그 합이 0에 가장 가까운 구간을 찾는 문제
		예를 들어서 다음과 같은 A[]가 있다
		A[i] = { -14, 7, 2, 3, -8, 4, -6, 8, 9, 11 }
		A[]에는 합이 0인 구간은 없지만, 0에 가장 가까운 구간은 A[2]~A[5]이다.
		psum = { -14, -7, -5, -2, -10, -6, -12, -4, 5, 16 }
		정렬된 psum = { -14, -12, -10, -7, -6, -5, -4, -2, 5, 16 }
}