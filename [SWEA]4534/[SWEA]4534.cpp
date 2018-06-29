#include <cstdio>
#include <vector>

using namespace std;

const int mod = 1000000007;

int solution(vector<pair<int, bool>> &tree,
	           int idx) {
	int result = 0;

	//idx node, idx node와 연결된 node가 둘 다 검은색 일 경우 
	if (tree[tree[idx].first].second && tree[idx].second)	return 0;

	//leaf node까지 탐색을 한 경우 종료
	if (idx == tree.size() - 1) return 1;

	tree[idx + 1].second = true;
	result += ((solution(tree, idx + 1) % mod) + (result % mod)) % mod;
	tree[idx + 1].second = false;
	result += ((solution(tree, idx + 1) % mod) + (result % mod)) % mod;

	return result % mod;
}

int main() {
	int test_case_num;
	int N;
	int x, y;

	//tree = { index, false = white, true = black }
	vector<pair<int, bool>> tree;

	int result;

	scanf("%d", &test_case_num);

	for (int test_case = 1; test_case <= test_case_num; test_case++) {
		scanf("%d", &N);
		tree = vector<pair<int, bool>>(N + 1);
		result = 0;

		//tree[x] = y, x and y is connected
		for (int edge_num = 1; edge_num < N; edge_num++) {
			scanf("%d %d", &x, &y);

			tree[x] = make_pair(y, false);
		}
		
		tree[1].second = true;
		result = ((solution(tree, 1) % mod) + (result % mod)) % mod;
		tree[1].second = false;
		result = ((solution(tree, 1) % mod) + (result % mod)) % mod;

		printf("#%d %d\n", test_case, result);
	}
	system("pause");

	return 0;
}