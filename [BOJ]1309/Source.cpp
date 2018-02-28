//https://www.acmicpc.net/problem/1309

/*
����
� �������� ���η� ��ĭ ���η� Nĭ�� �Ʒ��� ���� �츮�� �ִ�.

�� ���������� ���ڵ��� ��� �ִµ� ���ڵ��� �츮�� ���� ��, ���ηε� ���ηε� �پ� �ְ� ��ġ�� ���� ����. �� ������ ���û�� ���ڵ��� ��ġ ���� ������ ��Ӹ��� �ΰ� �ִ�.

������ ���û��� �Ӹ��� ������ �ʵ��� �츮�� 2*N �迭�� ���ڸ� ��ġ�ϴ� ����� ���� �� ���������� �˾Ƴ��� ���α׷��� �ۼ��� �ֵ��� ����. ���ڸ� �� ������ ��ġ���� �ʴ� ��쵵 �ϳ��� ����� ���� ģ�ٰ� �����Ѵ�.

�Է�
ù° �ٿ� �츮�� ũ�� N(1��N��100,000)�� �־�����.

���
ù° �ٿ� ���ڸ� ��ġ�ϴ� ����� ���� 9901�� ���� �������� ����Ͽ���.

���� �Է�  ����
4
���� ���  ����
41
*/
#include <iostream>
#include <cstring> //memset

using namespace std;

const int mod = 9901;

int dp[100001];
int main() {
	int N;

	memset(dp, 0, sizeof(dp));

	cin >> N;

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; i++) {
		dp[i] = (2 * dp[i-1]) % mod + (dp[i - 2]) % mod;
	}

	cout << dp[N] % mod;
}