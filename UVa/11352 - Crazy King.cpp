/* USER: 308958 (osdajigu) */
/* PROBLEM: 2327 (11352 - Crazy King) */
/* SUBMISSION: 14440000 */
/* SUBMISSION TIME: 2014-10-28 20:50:52 */
/* LANGUAGE: 3 */

#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

#define MAX 100 + 5
using namespace std;

char theMap[MAX][MAX];
bool visited[MAX][MAX];
int startX, startY, nTest, R, C;

const int MCX[] = {-2,-1, 1, 2, -2, -1,  1,  2};
const int MCY[] = { 1, 2, 2, 1, -1, -2, -2, -1};
const int DX[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int DY[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct Point{
	int x, y, cost;
	Point(){}
	Point(int x, int y, int cost){
		this -> x = x;
		this -> y = y;
		this -> cost = cost;
	}
	
};

bool check(int x, int y) {
	return x < R && y < C && x >= 0 && y >= 0;
}

void bfs(){
	visited[startX][startY] = true;
	queue<Point> q;
	q.push(Point(startX, startY, 0));
	while(!q.empty()) {
		Point p = q.front();
		q.pop();
		if(theMap[p.x][p.y] == 'B') {
		//	cout << "Minimal possible length of a trip is " << p.cost << endl;
			printf("Minimal possible length of a trip is %d\n", p.cost);
			return;
		}
			
		for(int i = 0; i < 8; i++)
			if(check(p.x + DX[i], p.y + DY[i]) && !visited[p.x + DX[i]][p.y + DY[i]] && theMap[p.x + DX[i]][p.y + DY[i]] != 'Z') {
				q.push(Point(p.x + DX[i], p.y + DY[i], p.cost + 1));
				visited[p.x + DX[i]][p.y + DY[i]] = true;
			}
	}
	//cout << "King Peter, you can't go now!" << endl;
	printf("King Peter, you can't go now!\n");
	
}

void fillMap(int x, int y) {
	for(int i = 0; i < 8; i++)
		if(check(x + MCX[i], y + MCY[i]) && theMap[x + MCX[i]][y + MCY[i]] != 'A' && theMap[x + MCX[i]][y + MCY[i]] != 'B')
			visited[x + MCX[i]][y + MCY[i]] = true;
}

int main() {
	cin >> nTest;
	while(nTest--) {
		memset(visited, false, sizeof(visited));
		//cin >> R >> C;
		scanf("%d%d", &R, &C);
		for(int i = 0; i < R; i ++)
			for(int j = 0; j < C; j++)
				scanf(" %c", &theMap[i][j]);
				//cin >> theMap[i][j];
		
		for(int i = 0; i < R; i ++)
			for(int j = 0; j < C; j++) {
				if(theMap[i][j] == 'Z')	fillMap(i, j);
				if(theMap[i][j] == 'A') startX = i, startY = j;
			}
					
		bfs();
	
	}
	return 0;
}
