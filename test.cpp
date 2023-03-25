#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<memory>
#include<array>
#include<tuple>
#include<string>


std::tuple<std::string, int> createPerson(){

    return { "zhu", 31 };
}

int main() {
    auto person = createPerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    std::string name1;
    int age1;
    std::tie(name1, age1) = createPerson();
    std::cout << "hello world" << std::endl;

    // auto [name, age] = createPerson();
    // std::cout << name << age << std::endl;

}
;

 
