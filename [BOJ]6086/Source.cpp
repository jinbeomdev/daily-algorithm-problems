//https://www.acmicpc.net/problem/6086

/*
문제
농사꾼 존은 소들이 충분한 물을 마시길 원했다. 그래서 농장에서 우물에서 외양간을 잇는 N개의 배수관의 지도를 만들기로 했다. 존은 아주 다양한 크기의 배수관들이 완전히 우연한 방법으로 연결돼있음을 알았다. 존은 파이프를 통과하는 유량을 계산하고 싶다.

두개의 배수관이 한줄로 연결 돼 있을 때 두 관의 유량 중 최소값으로 흐르게 된다. 예를 들어 용량이 5인 파이프가 용량이 3인 파이프와 연결되면 한개의 용량 3짜리 파이프가 된다.

+---5---+---3---+    ->    +---3---+
게다가, 병렬로 연결돼 있는 배수관들은 각 용량의 합만큼의 물을 보낼 수 있다.

+---5---+
---+       +---    ->    +---8---+
+---3---+
마지막으로, 어떤 것에도 연결돼 있지 않은 파이프는 물을 흐르게 하지 못하므로 제거된다.

+---5---+
---+               ->    +---3---+
+---3---+--
이로 인해 복잡하게 연결된 모든 배수관들은 한개의 최대 유량을 갖는 배수관으로 만들어진다.

주어진 파이프들의 맵으로부터 우물(A)와 외양관(Z) 사이의 유량을 결정하라.

각 노드의 이름은 알파벳으로 지어져 있다.

+-----------6-----------+
A+---3---+B                      +Z
+---3---+---5---+---4---+
C       D
파이프 BC와 CD는 합쳐질 수 있다.

+-----------6-----------+
A+---3---+B                      +Z
+-----3-----+-----4-----+
D
그러면 BD와 DZ 역시 합쳐질 수 있다.

+-----------6-----------+
A+---3---+B                      +Z
+-----------3-----------+
병렬 연결된 BZ 역시 합쳐진다.

B
A+---3---+---9---+Z
그러면 AB와 BZ 역시 합쳐질 수 있고 용량 3인 배수관 하나가 만들어진다.

A+---3---+Z
한 파이프들의 집합을 읽고. 두개의 끝점을 가진 파이프로 만들어놓은 뒤 A부터 Z까지 흐르는 최대 유량을 계산하라. 모든 파이프들은 위의 규칙을 적용시켜 줄일 수 있다.

i번째 파이프는 두개의 다른 노드 a_i와 b_i(a_i in range 'A-Za-z'; b_i in range 'A-Za-z')와 연결돼 있고 F_i(1<=F_i<=1,000)만큼의 유량을 갖는다. 대문자와 소문자로 구성된 이름은 서로 다른 문자로 인식한다.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 700)이 주어진다. 둘째 줄부터 N+1번째 줄까지 파이프의 정보가 주어진다. 첫 번째, 두 번째 위치에 파이프의 이름(알파벳)이 주어지고, 세 번째 위치에 파이프의 용량이 주어진다.

출력
첫째 줄에 A에서 Z까지의 최대 유량을 출력한다.

예제 입력  복사
5
A B 3
B C 3
C D 5
D Z 4
B Z 6
예제 출력  복사
3
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

inline int CtoI(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main() {
	const int size = ('Z' - 'A' + 1) + ('z' - 'a' + 1);
	const int INF = 10e9;
	int N;
	int C[size][size] = { 0 };
	int F[size][size] = { 0 };
	vector<vector<int>> adj;

	cin >> N;

	adj = vector<vector<int>>(size);

	for (int i = 0; i < N; i++) {
		char a, b;
		int f;

		cin >> a >> b >> f;

		a = ctoi(a); b = ctoi(b);
		C[a][b] += f;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int result = 0, S = ctoi('A'), E = ctoi('Z');
	
	while (1) {
		int prev[size];
		queue<int> q;
		q.push(S);
		memset(prev, -1, sizeof(prev));

		while (!q.empty()) {
			int here = q.front();
			q.pop();
			
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i];

				if (C[here][there] - F[here][there] > 0 &&
					prev[there] < 0) {
					prev[there] = here;
					q.push(there);

					if (there == E) break;
				}
			}
		}

		if (prev[E] < 0) break;

		int flow = INF;
		
		for (int i = E; i != S; i = prev[i]) {
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}

		for (int i = E; i != S; i = prev[i]) {
			F[prev[i]][i] += flow;
			F[i][prev[i]] -= flow;
		}

		result += flow;
	}

	cout << result;
}