#include <iostream>

class MyClass {
public:
    std::string str;

    MyClass(const std::string& s) : str(s) {
        std::cout << "Constructor called: " << str << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called: " << str << std::endl;
    }
};

void modifyString(MyClass obj) {
    obj.str = "Modified";
    std::cout << "Modified string: " << obj.str << std::endl;
}

int main() {
    MyClass myObj("Original");
    modifyString(myObj);

    std::cout << "Original string: " << myObj.str << std::endl;

    return 0;
}