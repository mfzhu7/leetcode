#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;




int main(){
    int left = 18;
    int right = 56688;
    int res = left;
    for (int i = left + 1; i < right; i++){
        res = res & i;
    }
    cout << res << endl;

}
