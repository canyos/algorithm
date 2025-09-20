#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll INF = 1e9;

#define left 0
#define right 1
#define up 2
#define down 3

int R, C;
char arr[26][26];
pair<int, int> m, z;
bool flag;
pair<int, int> flagPos;
char flagChar;
tuple<int, int, char> answer;
int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };
int cnt;

int nextDir(int r, int c, int dir) {
    switch (arr[r][c]) {
    case '|':
        if (dir == up) return up;
        if (dir == down) return down;
    case '-':
        if (dir == left)return left;
        if (dir == right)return right;
    case '+':
        if (dir == up) return up;
        if (dir == down) return down;
        if (dir == left)return left;
        if (dir == right)return right;
    case '1':
        if (dir == up) return right;
        if (dir == left) return down;
    case '2':
        if (dir == down) return right;
        if (dir == left) return up;
    case '3':
        if (dir == down) return left;
        if (dir == right) return up;
    case '4':
        if (dir == right)return down;
        if (dir == up) return left;
    }
    return -1;
}

bool checkPos(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

vector<char> nextChar(int r, int c, int dir) {

    switch (dir) {
    case up:
        return { '|',  '1','4','+' };
    case down:
        return { '|',  '2','3','+' };
    case left:
        return { '-','1','2','+' };
    case right:
        return { '-', '3','4','+' };
    }
    return {};
}
bool checkDir(int r, int c, int dir) {
    switch (arr[r][c]) {
    case '|':
        if (dir == left) return false;
        if (dir == right) return false;
        break;
    case '-':
        if (dir == up)return false;
        if (dir == down)return false;
        break;
    case '+':
        return true;
        break;
    case '1':
        if (dir == down) return false;
        if (dir == right) return false;
        break;
    case '2':
        if (dir == up) return false;
        if (dir == right) return false;
        break;
    case '3':
        if (dir == up) return false;
        if (dir == left) return false;
        break;
    case '4':
        if (dir == left)return false;
        if (dir == down) return false;
        break;
    }
    return true;
}
bool dfs(int r, int c, int dir, int depth) {
    if (z.first == r && z.second == c ) {
        if ((flagChar!='+' && depth == cnt + 1) || (flagChar == '+' && depth == cnt + 2 ) ){
            answer = { flagPos.first, flagPos.second, flagChar };
            return true;
        }
        return false;
    }

    bool res = false;;
    if (arr[r][c] != '.') {
        if (!checkDir(r, c,dir))return false;
        int nDir = nextDir(r, c, dir);
        if (nDir == -1) 
            return false;

        int nr = r + dr[nDir], nc = c + dc[nDir];
        if (checkPos(nr, nc) && !res) {
            res = dfs(nr, nc, nDir, depth+1);
        }
    }
    else {
        if (flag) 
            return false;
        flag = true;
        flagPos = { r,c };
        for (char ch : nextChar(r, c, dir)) {
            arr[r][c] = ch;
            flagChar = ch;

            int nDir = nextDir(r, c, dir);
            if (nDir == -1) 
                continue;

            int nr = r + dr[nDir], nc = c + dc[nDir];
            if (checkPos(nr, nc) && !res) {
                res = dfs(nr, nc, nDir, depth+1);
                if (res)
                    return true;
            }
        }

        flag = false;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'M')
                m = { i,j };
            else if (arr[i][j] == 'Z')
                z = { i,j };
            if (arr[i][j] != '.') {
                if (arr[i][j] == '+')
                    cnt += 2;
                else
                    cnt++;
            }
        }
    }

    int r, c;
    tie(r, c) = m;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (checkPos(nr, nc)) {
            if (k == 0) {//왼쪽
                if (arr[nr][nc] == '-')
                    dfs(nr, nc, left,2);
                if (arr[nr][nc] == '+')
                    dfs(nr, nc, left,2);
                if (arr[nr][nc] == '1')
                    dfs(nr, nc, left,2);
                if (arr[nr][nc] == '2')
                    dfs(nr, nc, left,2);
            }
            else if (k == 1) {//오른쪽
                if (arr[nr][nc] == '-')
                    dfs(nr, nc, right,2);
                if (arr[nr][nc] == '+')
                    dfs(nr, nc, right,2);
                if (arr[nr][nc] == '3')
                    dfs(nr, nc, right,2);
                if (arr[nr][nc] == '4')
                    dfs(nr, nc, right,2);
            }
            else if (k == 2) {//위
                if (arr[nr][nc] == '|')
                    dfs(nr, nc, up, 2);
                if (arr[nr][nc] == '1')
                    dfs(nr, nc, up, 2);
                if (arr[nr][nc] == '+')
                    dfs(nr, nc, up, 2);
                if (arr[nr][nc] == '4')
                    dfs(nr, nc, up, 2);
            }
            else {//아래
                if (arr[nr][nc] == '|')
                    dfs(nr, nc, down, 2);
                if (arr[nr][nc] == '+')
                    dfs(nr, nc, down, 2);
                if (arr[nr][nc] == '2')
                    dfs(nr, nc, down, 2);
                if (arr[nr][nc] == '3')
                    dfs(nr, nc, down, 2);
            }
        }
    }
    cout << get<0>(answer) + 1 << " " << get<1>(answer) + 1 << " " << get<2>(answer);
    return 0;

}
/*
9 10
..........
..........
..Z-4.....
....|.....
.....4....
....13....
....M.....
..........
..........
*/