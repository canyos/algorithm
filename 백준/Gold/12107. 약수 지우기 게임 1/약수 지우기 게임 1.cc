#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n;
int arr[17][17];
queue<tuple<int, int, int>> qu;
int answer = 0;

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	cin >> n;
    if(n==1)cout<<"B";
    else
	cout <<"A";
	return 0;
}