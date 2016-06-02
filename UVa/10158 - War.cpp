#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<bitset>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ii pair<int, int>
#define PB push_back
#define MAX 10000 + 10

using namespace std;

int n, op, from, to, label = -10000;
int father[MAX], seen[MAX], range[MAX];
vector<int> enemies[MAX];

void init() {
    for(int i = 0; i <= n; i++) father[i] = i, range[i] = 0;
}

int find(int x) {
    return father[x] = (x == father[x] ? x : find(father[x]));
}

void merge(int a, int b) {
    if(range[a] > range[b]) {
        father[a] = b;
        for(int i = 0; i < enemies[a].size(); i++) enemies[b].PB(enemies[a][i]);
        //set<int> s(enemies[b].begin(), enemies[b].end());
        //enemies[b].assign(s.begin(), s.end());

    }
    else {
        father[b] = a;
        for(int i = 0; i < enemies[b].size(); i++) enemies[a].PB(enemies[b][i]);
        //set<int> s(enemies[a].begin(), enemies[a].end());
        //enemies[a].assign(s.begin(), s.end());
        if(range[a] == range[b]) range[a]++;
    }

}

bool areFriends(int a, int b) {
    int A = find(a), B = find(b);
    if(B == A) return true;
    label++;
    if(label == 0) label++;
    for(int i = 0; i < enemies[A].size(); i++) seen[find(enemies[A][i])] = label;
    for(int i = 0; i < enemies[B].size(); i++)
        if(seen[find(enemies[B][i])] == label) {
            merge(A, B);
            return true;
        }
    return false;
}

bool areEnemies(int a, int b) {
    int A = find(a);
    int B = find(b);
    for(int i = 0; i < enemies[A].size(); i++){
        if(enemies[A][i] == B) return true;
        if(areFriends(enemies[A][i], B)) {
            enemies[A].PB(B);
            enemies[B].PB(A);
            return true;
        }
    }
    for(int i = 0; i < enemies[B].size(); i++){
        if(enemies[B][i] == A) return true;
        if(areFriends(enemies[B][i], A)) {
            enemies[A].PB(B);
            enemies[B].PB(A);
            return true;
        }
    }
    return false;
}

void setFriends(int a, int b) {
    if(areEnemies(a, b)) {
        printf("-1\n");
        return;
    }
    int A = find(a);
    int B = find(b);
    if(A != B) {
        merge(A, B);
    }
}

void setEnemies(int a, int b) {
    if(areFriends(a, b)) {
        printf("-1\n");
        return;
    }
    if(!areEnemies(a, b)){
        enemies[find(a)].PB(find(b));
        enemies[find(b)].PB(find(a));
    }
}


int main() {
    scanf("%d", &n);
    init();
    while(scanf("%d%d%d", &op, &from, &to) > 0 && (op != 0 || from != 0 || to != 0)) {
        if(op == 1) setFriends(from, to);
        if(op == 2) setEnemies(from, to);
        if(op == 3) printf("%d\n", areFriends(from, to));
        if(op == 4) printf("%d\n", areEnemies(from, to));
    }

}
