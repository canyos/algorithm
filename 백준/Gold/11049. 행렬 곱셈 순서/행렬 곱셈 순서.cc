#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class triple {
public:
	int first;
	int second;
	int third;
	triple(int f, int s, int t){
		this->first = f;
		this->second = s;
		this->third = t;
	}
	triple(){
		this->first = 0;
		this->second = 0;
		this->third = 0;
	}
};

triple arr[500][500];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		arr[i][i] = { r,c,0 };
	}

	for (int i = 1; i < n; i++) {//offset
		for (int j = 0; j + i < n; j++) {//갱신할 위치 arr[j][i+j]
			arr[j][j + i].first = arr[j][j].first;
			arr[j][j + i].second = arr[j + i][j + i].second;
			arr[j][j + i].third = INF;
			for (int k = j; k < j+i; k++) {//비교에 쓸 인덱스
				arr[j][j + i].third = min(arr[j][j+i].third, 
					arr[j][k].third + arr[k+1][i + j].third + arr[j][k].first * arr[j][k].second * arr[k+1][j+i].second);
			}
		}
	}

	cout << arr[0][n - 1].third;


	return 0;
}
