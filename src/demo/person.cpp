#include "person.pb.h"
#include <iostream>
#include <fstream>

int main() {
    Person person;

    person.set_name("Alice");
    person.set_id(123);
    person.set_email("alice@example.com");

    // 序列化
    std::string serialized;
    person.SerializeToString(&serialized);

    // 反序列化
    Person person2;
    person2.ParseFromString(serialized);

    std::cout << "Name: " << person2.name() << std::endl;
    
    return 0;
}
