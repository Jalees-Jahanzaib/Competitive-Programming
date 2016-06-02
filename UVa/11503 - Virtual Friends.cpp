/* USER: 308958 (osdajigu) */
/* PROBLEM: 2498 (11503 - Virtual Friends) */
/* SUBMISSION: 15099560 */
/* SUBMISSION TIME: 2015-03-07 16:17:37 */
/* LANGUAGE: 3 */

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

#define ii pair<string, int>

using namespace std;

int nTest, F;
map<string, ii> father;
map<string, int> range;
map<string, bool> used;
char a[30], b[30];
string auxA, auxB;

void init() {
    father.clear();
    range.clear();
    used.clear();
}

string find(string x) {
    if(x == father[x].first) return x;
    return father[x].first = find(father[x].first);
}

void merge(string x, string y) {
    string fatherX = find(x), fatherY = find(y);
    if(fatherX == fatherY) {
        printf("%d\n", father[fatherX].second);
        return;
    }
    if(range[fatherX] > range[fatherY]) {
        father[fatherY].first = fatherX;
        father[fatherX].second += father[fatherY].second;
        printf("%d\n", father[fatherX].second);
    }
    else {
        father[fatherX].first = fatherY;
        father[fatherY].second += father[fatherX].second;
        if(range[fatherX] == range[fatherY]) {
            range[fatherY]++;
        }
        printf("%d\n", father[fatherY].second);
    }

    //printf("%d\n", father[find(x)].second);
}


int main() {
    scanf("%d", &nTest);
    while(nTest--) {
        init();
        scanf("%d", &F);
        for(int i = 0; i < F; i++) {
            scanf("%s %s", a, b);
            auxA = string(a);
            auxB = string(b);
            //cout << (father[auxA].first == "" )<< " " << father[auxA].second << endl;
            if(father[auxA].first == "") father[auxA] = ii(auxA, 1);
            if(father[auxB].first == "") father[auxB] = ii(auxB, 1);
            //if(used[auxA + "" + auxB] || used[auxB + "" + auxA]) continue;
            //used[auxA + "" + auxB] = used[auxB + "" + auxA] = true;
            merge(auxA, auxB);
        }
    }
}
