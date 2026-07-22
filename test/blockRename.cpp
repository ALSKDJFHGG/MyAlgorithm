#include <string>
#include <iostream>

/**
 * 消除字符之间的空格
 */
class MyString
{
private:
    std::string strs;
    size_t length;

public:
    MyString() {}
    MyString(std::string &input):strs{input} {
        this->length = input.size();
    }
    ~MyString() = default;

    std::string missBlock() {
        std::string blockString;
        for (auto str: strs) {
            if (str == ' ') {
                continue;
            }
            blockString.push_back(str);
        }
        return blockString;
    }

    void input() {
        std::getline(std::cin, strs);
    }

    void input(std::string &input) {
        this->strs = input;
    } 

    void output(std::string &&out) {
        std::cout << out << std::endl;
    }

    /**
     * 不传参数默认末尾添加.cpp
     */
    void tailAdd() {
        std::string tailCpp{ ".cpp" };
        strs.append(tailCpp);
    }
    /**
     * 末尾添加
     */
    void tailAdd(std::string &tailValue) {
        strs.append(tailValue);
    }

    void tailAdd(std::string &&tailValue) {
        strs.append(tailValue);
    }

};

int main()
{
    MyString mystring;
    mystring.input();
    mystring.tailAdd();
    mystring.output(mystring.missBlock());
    return 0;
}