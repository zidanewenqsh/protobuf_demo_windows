#include <iostream>
#include <string>
#include "phonebook.pb.h"  // 引入由 protoc 生成的头文件

int main() {
    // 创建 Person 对象
    Person person;
    person.set_name("John Doe");
    person.set_id(1234);

    // 添加一个手机号码
    PhoneNumber* mobile_phone = person.add_phones();
    mobile_phone->set_number("123-456-7890");
    mobile_phone->set_type(PhoneNumber::MOBILE);

    // 添加一个家庭电话号码
    PhoneNumber* home_phone = person.add_phones();
    home_phone->set_number("555-555-5555");
    home_phone->set_type(PhoneNumber::HOME);

    // 输出 Person 信息
    std::cout << "Name: " << person.name() << std::endl;
    std::cout << "ID: " << person.id() << std::endl;
    for (const PhoneNumber& phone : person.phones()) {
        std::cout << "Phone Number: " << phone.number();
        switch (phone.type()) {
            case PhoneNumber::MOBILE:
                std::cout << " (Mobile)";
                break;
            case PhoneNumber::HOME:
                std::cout << " (Home)";
                break;
            case PhoneNumber::WORK:
                std::cout << " (Work)";
                break;
            default:
                // 处理未知或未显式处理的枚举值
                std::cout << " (Other)";
                break;
        }
        std::cout << std::endl;
    }

    return 0;
}
