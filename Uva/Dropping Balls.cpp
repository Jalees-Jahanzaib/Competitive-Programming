#include<iostream>
#include<stdio.h>

using namespace std;

int nTest, iter, depth;

int main() {
    scanf("%d", &nTest);
    while(nTest--) {
        scanf("%d%d", &depth, &iter);
        int node = 1, pos;
        while(--depth) {
            if(iter % 2 == 0) node = 2 * node + 1;
            else node = 2 * node;
            iter = (iter + 1) / 2;
        }
        printf("%d\n", node);
    }
    scanf("%d", &nTest);
}
