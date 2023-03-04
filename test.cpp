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
#include<memory>
#include<string.h>
#include<tuple>

using namespace std;

// class Entity {
// public:
//     Entity(){
//         cout << "created entity" << endl;
//     }
//     ~Entity(){
//         cout << "destroy entity" << endl;
//     }
// }
// ;

// class ScopePtr{
// private:
//     Entity* m_ptr;

// public:
//     ScopePtr(Entity* e)
//         :m_ptr(e) {};
    
//     ~ScopePtr(){
//         delete m_ptr;
//     }
// }
// ;
class String{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(const char* string){
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0;
    }
    String(const String& other)
        :m_size(other.m_size){
        cout << "copy string" << endl;
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size + 1);
    }
    ~String(){
        delete[] m_buffer;
        // cout << "destroyed" << endl;
    }
    char& operator[](unsigned int index){
        return m_buffer[index];
    }
    friend ostream& operator<<(ostream& stream, const String& string);

}
;
ostream& operator<<(ostream& stream, const String& string){
    stream << string.m_buffer;
    return stream;
}

void printString(String string){
    cout << string << endl;
}

// class Entity {
// public:
//     void print() const { cout << "hello world" << endl;}
// }
// ;


// class ScopedPtr{
// private:
//     Entity* m_Obj;
// public:
//     ScopedPtr(Entity* entity)
//         :m_Obj(entity) {};
    
//     ~ScopedPtr(){
//         delete m_Obj;
//     }
//     Entity* operator->(){
//         return m_Obj;
//     }

// };

struct humaninfo
{
    string name;
    int weight;
};


humaninfo getHumaninfo(){
    return {"zhu", 50};
}
;

int main() {
    auto result = getHumaninfo();
    cout << result.name << endl;
    cout << result.weight << endl;

}
;

 
