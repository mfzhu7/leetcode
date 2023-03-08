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
#include<functional>



namespace apple {
    void print(const std::string& text){
        std::cout << text << std::endl;
    }
}
namespace orange {
    void print(const char* text){
        std::string temp = text;
        reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}


int main() {
    using namespace orange;
    using namespace apple;
    apple::print("HELLO");
}
;

 
