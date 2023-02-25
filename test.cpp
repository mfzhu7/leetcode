#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<sstream>
#include<stack>
#include<unordered_map>
#include<stdlib.h>

using namespace std;

class Example {
public:
    Example() {
        cout << "created Entity" << endl;
    }
    Example(int x) {
        cout << "created entity with" << x << endl;
    }
}
;

class Entity {
    private:
    string m_name;

    public:
    Entity(): m_name("unknown"){};
    Entity(const string& name){
        m_name = name;
    }
    const string& getName() const { return m_name;}
}
;

int main() {
    cout<< INT_MIN << endl;
    cout << INT_MIN / 10 << endl;
    cout << INT_MIN % 10 << endl;

}

 
