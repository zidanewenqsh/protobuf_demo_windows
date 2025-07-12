#include <iostream>
#include <fstream>
#include "addressbook.pb.h"  // 引入由 protoc 生成的头文件

int main() {
    // 创建并填充 Person 对象
    Person person;
    person.set_name("John Doe");
    person.set_id(1234);
    person.mutable_address()->set_street("123 Main Street");
    person.mutable_address()->set_city("Anytown");

    // 序列化 Person 对象到文件
    std::ofstream output("person.bin", std::ios::binary);
    if (!person.SerializeToOstream(&output)) {
        std::cerr << "Failed to write person." << std::endl;
        return -1;
    }
    output.close();

    // 反序列化 Person 对象从文件
    Person person_read;
    std::ifstream input("person.bin", std::ios::binary);
    if (!person_read.ParseFromIstream(&input)) {
        std::cerr << "Failed to read person." << std::endl;
        return -1;
    }

    // 输出反序列化后的数据
    std::cout << "Name: " << person_read.name() << std::endl;
    std::cout << "ID: " << person_read.id() << std::endl;
    std::cout << "Address: " << person_read.address().street() << ", " << person_read.address().city() << std::endl;

    return 0;
}