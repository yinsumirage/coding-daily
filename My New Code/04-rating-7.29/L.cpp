#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500005 * 4;
int n, k, L, R, A[maxn];
int sum[maxn], ST[maxn][20], pos[maxn][20];

void init(){
	memset(sum, -127 / 3, sizeof(sum));
	memset(ST, -127 / 3, sizeof(ST));
	cin >> n >> k >> L >> R;
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> A[i];
		sum[i] = sum[i - 1] + A[i];
	}
	for (int i = n; i > 0; i--){
		ST[i][0] = sum[i]; pos[i][0] = i;
		for (int j = 1; i + (1 << j) - 1 <= n; j++){
			ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
			pos[i][j] = ST[i][j - 1] > ST[i + (1 << (j - 1))][j - 1] ? pos[i][j - 1] : pos[i + (1 << (j - 1))][j - 1];
		}
	}
}

int qr(int o, int l, int r){
	int bm = int(log(r - l + 1) / log(2));
	int maxsumk = ST[l][bm] > ST[r - (1 << bm) + 1][bm] ?pos[l][bm] : pos[r - (1 << bm) + 1][bm];
	return maxsumk;
}

struct node{
	int o, l, r, k;
	bool operator <(const node b) const{
		return sum[k] - sum[o - 1] < sum[b.k] - sum[b.o - 1];
	}
} bm, bm2;
priority_queue<node> hp;
int main(){
	init();
	for (int o = 1; o + L - 1 <= n; o++){
		bm.o = o;
		bm.l = o + L - 1;
		bm.r = min(n, o + R - 1);
		bm.k = qr(o, bm.l, bm.r);
		hp.push(bm);
	}
	ll ans = 0;
	while (k--){
		bm = hp.top(); hp.pop();
		ans += sum[bm.k] - sum[bm.o - 1];
		if (bm.k != bm.r){
			bm2 = bm;
			bm2.l = bm.k + 1;
			bm2.k = qr(bm2.o, bm2.l, bm2.r);
			hp.push(bm2);
		}
		if (bm.k != bm.l){
			bm.r = bm.k - 1;
			bm.k = qr(bm.o, bm.l, bm.r);
			hp.push(bm);
		}
	}
    printf("%lld\n",ans);
	return 0;
}