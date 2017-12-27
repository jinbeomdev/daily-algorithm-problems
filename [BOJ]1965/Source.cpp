//https://www.acmicpc.net/problem/1965

/*
문제
정육면체 모양의 상자들이 일렬로 늘어서 있다. 상자들마다 크기가 주어져 있는데, 앞에 있는 상자의 크기가 뒤에 있는 상자의 크기보다 작으면, 앞에 있는 상자를 뒤에 있는 상자 안에 넣을 수가 있다. 예를 들어 앞에서부터 순서대로 크기가 (1, 5, 2, 3, 7)인 5개의 상자가 있다면, 크기 1인 상자를 크기 5인 상자에 넣고, 다시 이 상자들을 크기 7인 상자 안에 넣을 수 있다. 하지만 이렇게 상자를 넣을 수 있는 방법은 여러 가지가 있을 수 있다. 앞의 예에서 차례대로 크기가 1, 2, 3, 7인 상자들을 선택하면 총 4개의 상자가 한 개의 상자에 들어가게 된다.

상자들의 크기가 주어질 때, 한 번에 넣을 수 있는 최대의 상자 개수를 출력하는 프로그램을 작성하시오.

입력
파일의 첫 번째 줄은 상자의 개수 n (1≤n ≤1000)을 나타낸다. 두 번째 줄에는 각 상자들의 크기가 순서대로 주어진다.

출력
첫째 줄에 한 줄에 넣을 수 있는 최대의 상자 개수를 출력한다.

예제 입력  복사
8
1 6 2 5 7 3 5 6
예제 출력  복사
5
*/
#include <iostream>

using namespace std;

int main() {
	int n;
	int boxes[1000];
	int dp[1000];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> boxes[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (boxes[j] < boxes[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout << answer;
}