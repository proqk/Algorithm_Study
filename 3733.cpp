#include <stdio.h>
#define MN 10000000
long long int sum = 0, ss, x, y;
int s, e;

int dp[MN + 1] = { 1,1, };

int change(long long int  k) {
	int  result;
	if (k < MN && dp[k] != 0) return dp[k];
	if (k % 2 == 0) {
		if (k < MN) {
			return dp[k]  = change(k / 2)+1;
		}
		else {
			return change(k / 2)+1;
		}
	}
	else{
		if (k < MN) {
			return dp[k] = change(k *3 +1 )+1;
		}
		else {
			return change(k * 3 + 1)+1;
		}
	}
}

int main() {
	scanf("%d %d", &s, &e);
	for (int i = s; i <= e; i++) {
		change(i);
		int q = dp[i];
		if (q > sum) {
			ss = i;
			sum = q;
		}
	}
	printf("%lld %lld", ss, sum);
}
