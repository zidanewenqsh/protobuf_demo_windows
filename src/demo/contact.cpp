#include <iostream>
#include <string>
#include "contact.pb.h"  // 引入由 protoc 生成的头文件

int main() {
    // 创建 Contact 对象并设置 email
    Contact contact_email;
    contact_email.set_email("example@email.com");

    // 检查 contact_type 是否为 email
    if (contact_email.contact_type_case() == Contact::kEmail) {
        std::cout << "Email: " << contact_email.email() << std::endl;
    }

    // 创建另一个 Contact 对象并设置 phone
    Contact contact_phone;
    contact_phone.set_phone("123-456-7890");

    // 检查 contact_type 是否为 phone
    if (contact_phone.contact_type_case() == Contact::kPhone) {
        std::cout << "Phone: " << contact_phone.phone() << std::endl;
    }

    return 0;
}
