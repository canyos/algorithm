#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
typedef long long ll;

ll N, ans = LONG_MAX;
ll na, nb, ca, cb; // 묶음개수 ,가격 

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> na >> ca >> nb >> cb;

	//묶음 가성비 B가 더 좋게 설정 
	if (ca * nb < cb * na) {
		ll tmp = na;
		na = nb;
		nb = tmp;

		tmp = ca;
		ca = cb;
		cb = tmp;
	}

	//정확하게 따지면 cb가 아니라 최소공배수 만드는 배수겠지만
	// nb로 해도 답은 나오니까 
	// x : a의 묶음 개수
	// y: b의 묶음 개수 
	for (ll x = 0; x < nb; x++) {
		ll y = (long long)ceil((double)(N - na * x) / (double)nb);

		bool over = false;
		if (y < 0) {
			y = 0;
			over = true;
		}
		ans = min(ans, ca * x + cb * y);
		if (over) break;
	}
	cout << ans << "\n";

	return 0;
}