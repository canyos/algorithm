# [Gold V] 평범한 배낭 - 12865 

[문제 링크](https://www.acmicpc.net/problem/12865) 

### 성능 요약

메모리: 41476 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2024년 8월 19일 03:44:42

### 문제 설명

<p>이 문제는 아주 평범한 배낭에 관한 문제이다.</p>

<p><span style="line-height:1.6em">한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.</span></p>

<p><span style="line-height:1.6em">준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.</span></p>

### 입력 

 <p>첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.</p>

### 풀이
01냅색문제 

bfs로 풀려고 1차 시도-> 무게가 1인 아이템이 100개있으면 마지막엔 2^100개의 노드가 필요됨 ->메모리 초과

힌트 봐서 dp로 풀어야함을 인지-> dp배열의 열은 무게로 고정 

행을 index의 아이템무게라고 가정 -> 같은 무게의 아이템이있으면 불가능

행을 index번째 아이템이라고 가정 -> dp[i][j]는 i번째 아이템까지 사용해서 만들 수 있는 j무게에서의 최대 가치

점화식 dp[i][j] = max(dp[i-1][j], dp[i-1][j-i번째 아이템 무게) + i번째아이템 가치)

만약 j보다 i번째 아이템 무게가 크다면 out of range나오므로 예외처리 -> dp[i-1][j]

푸는데 3시간 걸림
