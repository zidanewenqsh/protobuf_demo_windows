#include <iostream>
#include <string>
#include "item.pb.h"  // 引入由 protoc 生成的头文件

int main() {
    // 创建 Item 对象并设置属性
    Item book;
    book.set_name("The Great Gatsby");
    book.set_type(Item::BOOK);

    // 输出 Item 信息
    std::cout << "Item Name: " << book.name() << std::endl;
    std::cout << "Item Type: ";
    switch (book.type()) {
        case Item::UNKNOWN:
            std::cout << "Unknown";
            break;
        case Item::BOOK:
            std::cout << "Book";
            break;
        case Item::ELECTRONIC:
            std::cout << "Electronic";
            break;
        default:
            // 处理未知或未显式处理的枚举值
            std::cout << "Other";
            break;
    }
    std::cout << std::endl;

    return 0;
}
