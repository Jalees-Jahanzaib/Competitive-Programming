/* USER: 308958 (osdajigu) */
/* PROBLEM: 3503 (1062 - Containers) */
/* SUBMISSION: 14428306 */
/* SUBMISSION TIME: 2014-10-26 21:53:18 */
/* LANGUAGE: 3 */

#include<iostream>
#include<vector>
using namespace std;

vector<char> stacks;
int N, nTest;
bool flag = false;
string s;
int main(){
    cin >> s;
    int idCase = 0;
    while(s != "end") {
        stacks.clear();
        stacks.push_back(s[0]);
        for(int i = 1; i < s.size(); i++) {
            flag = false;
            for(int j = 0; j < stacks.size(); j++) {
                if(s[i] <= stacks[j]) {
                    stacks[j] = s[i];
                    flag = true;
                    break;
                }
            }
            if(!flag)
                stacks.push_back(s[i]);
        }
        cout << "Case " << ++idCase << ": " << stacks.size() << endl;
        cin >> s;
    }
}
