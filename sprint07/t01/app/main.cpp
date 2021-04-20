#include <iostream>
#include <string>

#include "CBLString.h"
#include "CBLWString.h"

void    constructorTest() {
    {
        CBL::String str = "Hello Tamriel";
        auto strCpy = str;
        assert(str == strCpy);
        str = CBL::String(str, 2);
        assert(str == "llo Tamriel");
        str = CBL::String(strCpy, 2, 3);
        assert(str == "llo");
        CBL::String itStr(strCpy.begin() + 6, strCpy.end());
        assert(itStr == "Tamriel");
        assert(itStr.front() == 'T');
        assert(itStr.back() == 'l');
        str = CBL::String(5, 'm');
        assert(str == "mmmmm");
        str = '!';
        assert(str == "!");
    }
    {
        CBL::WString str = L"Hello Tamriel";
        auto strCpy = str;
        assert(str == strCpy);
        str = CBL::WString(str, 2);
        assert(str == L"llo Tamriel");
        str = CBL::WString(strCpy, 2, 3);
        assert(str == L"llo");
        CBL::WString itStr(strCpy.begin() + 6, strCpy.end());
        assert(itStr == L"Tamriel");
        assert(itStr.front() == 'T');
        assert(itStr.back() == 'l');
        str = CBL::WString(5, 'm');
        assert(str == L"mmmmm");
        str = '!';
        assert(str == L"!");
    }
}

void    concatTest() {
    std::cout << "\n------------ concat ------------" << std::endl;
    {
        CBL::String str1("Hello");
        CBL::String str2(" Tamriel");
        str1 += str2;
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel");
        str1 += '!';
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel!");
        str1 += "!!";
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel!!!");
    }
//     // append
    {
        CBL::String str1("Hello");
        CBL::String str2(" Tamriel");
        str1.append(str2);
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel");
        str1.append("... hidden", 3);
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel...");
        str1.append(2, '!');
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel...!!");
        str1.append("!");
        std::cout << str1 << std::endl;
        assert(str1 == "Hello Tamriel...!!!");
    }
//     // concat operators
    {
        CBL::String str;
        str += CBL::String("1") + "2";
        str += "3" + CBL::String("4");
        str += CBL::String("5") + CBL::String("6");
        str += CBL::String("7") + '8';
        str += '9' + CBL::String("0");
        std::cout << str << std::endl;
        assert(str == "1234567890");
    }
    std::cout << "--wstring--" << std::endl;
    {
        CBL::WString str1(L"Hello");
        CBL::WString str2(L" Tamriel");
        str1 += str2;
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel");
        str1 += L'!';
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel!");
        str1 += L"!!";
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel!!!");
    }
//     // append
    {
        CBL::WString str1(L"Hello");
        CBL::WString str2(L" Tamriel");
        str1.append(str2);
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel");
        str1.append(L"... hidden", 3);
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel...");
        str1.append(2, '!');
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel...!!");
        str1.append(L"!");
        std::wcout << str1 << std::endl;
        assert(str1 == L"Hello Tamriel...!!!");
    }
}

void    findTest() {
    std::cout << "\n------------ find ------------" << std::endl;
    {
        CBL::String str(
            "The class template basic_string stores and manipulates sequences of char-like objects, "
            "which are non-array objects of trivial standard-layout type. "
            "The class is dependent neither on the character type nor on the nature of operations on that type. "
            "The definitions of the operations are supplied via the Traits template parameter - "
            "a specialization of std::char_traits or a compatible traits class. "
            "Traits::char_type and CharT must name the same type; otherwise the program is ill-formed."
        );

        std::cout << str.find('p') << std::endl;
        std::cout << str.find('p', 30) << std::endl;
        std::cout << std::boolalpha << (str.find('p', 465) == CBL::String::npos) << std::endl;
        std::cout << str.find("class") << std::endl;
        std::cout << str.find(CBL::String("class"), 20) << std::endl;
        std::cout << str.find("of") << std::endl;
        std::cout << str.find("of", 170) << std::endl;
    }
    std::cout << "--wstring--" << std::endl;
    {
        CBL::WString str(
            L"The class template basic_string stores and manipulates sequences of char-like objects, "
            "which are non-array objects of trivial standard-layout type. "
            "The class is dependent neither on the character type nor on the nature of operations on that type. "
            "The definitions of the operations are supplied via the Traits template parameter - "
            "a specialization of std::char_traits or a compatible traits class. "
            "Traits::char_type and CharT must name the same type; otherwise the program is ill-formed."
        );

        std::cout << str.find('p') << std::endl;
        std::cout << str.find('p', 30) << std::endl;
        std::cout << std::boolalpha << (str.find('p', 465) == CBL::WString::npos) << std::endl;
        std::cout << str.find(L"class") << std::endl;
        std::cout << str.find(CBL::WString(L"class"), 20) << std::endl;
        std::cout << str.find(L"of") << std::endl;
        std::cout << str.find(L"of", 170) << std::endl;
    }
}

void    compareTest() {
    CBL::String str("some string");
    CBL::String str1("one");
    CBL::String str2("two");

    assert(!(str1 == str2));
    assert(str1 != str2);
    assert(str.compare("some string") == 0);
    assert(str.compare(str) == 0);
    assert(str.compare("some stri") > 0);
    assert(str.compare("sOme string") > 0);
    assert(str.compare("zzzzzzzzzzzzzzzzzzzzz") < 0);
}

int main() {
    std::string s = "Hello Tamriel";
    CBL::String str("aaa");
    constructorTest();
    concatTest();
    findTest();
    compareTest();
    return 0;
}
