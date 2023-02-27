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

class Entity {
public:
    Entity(){
        cout << "created entity" << endl;
    }
    ~Entity(){
        cout << "destroy entity" << endl;
    }
}
;

class ScopePtr{
private:
    Entity* m_ptr;

public:
    ScopePtr(Entity* e)
        :m_ptr(e) {};
    
    ~ScopePtr(){
        delete m_ptr;
    }
}
;

int main() {
    {
        ScopePtr e = new Entity();
    }
}
;

 
