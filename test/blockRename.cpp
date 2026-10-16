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
     * 不传参数时把末尾的.cpp替换为.exe，无.cpp后缀则直接添加.exe
     */
    void tailAdd() {
        static const std::string cppSuffix{ ".cpp" };
        if (strs.size() >= cppSuffix.size() &&
            strs.compare(strs.size() - cppSuffix.size(), cppSuffix.size(), cppSuffix) == 0) {
            strs.replace(strs.size() - cppSuffix.size(), cppSuffix.size(), ".cpp");
        } else {
            strs.append(".cpp");
        }
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

int main(int argc, char** argv)
{
    MyString mystring;
    std::string s;
    for (int i{1}; i < argc; ++i) {
        s.append(argv[i]);
    }
    mystring.input(s);
    mystring.tailAdd();
    mystring.output(mystring.missBlock());
    return 0;
}