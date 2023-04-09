#include <bits/stdc++.h>
using namespace std;
class String
{
public:
    String(const char *str = nullptr);
    String(const String &str);
    ~String();

    int size() const;
    const char *c_str() const;
    String &operator=(const String &str);
    bool operator==(const String &str) const;
    String &operator+=(const String &str);
    String operator+(const String &str) const;
    char &operator[](int n) const;
    friend ostream &operator<<(ostream &os, const String &str);

private:
    int len;
    char *data;
};
String::String(const char *str)
{
    if (str == nullptr)
    {
        data = new char[1];
        len = 0;
        *data = '\0';
    }
    else
    {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
}
String::String(const String &str)
{
    len = str.size();
    data = new char[len + 1];
    strcpy(data, str.c_str());
}
String::~String()
{
    delete[] data;
    len = 0;
}
int String::size() const
{
    return len;
}
const char *String::c_str() const
{
    return data;
}
String &String::operator=(const String &str)
{
    if (this == &str)
    {
        return *this;
    }
    delete[] data;
    len = str.size();
    data = new char[len + 1];
    strcpy(data, str.c_str());
    return *this;
}
bool String::operator==(const String &str) const
{
    if (len != str.size())
    {
        return false;
    }
    return strcmp(data, str.c_str()) ? false : true;
}
String &String::operator+=(const String &str)
{
    len += str.size();
    char *newdata = new char[len + 1];
    strcpy(newdata, data);
    strcat(newdata, str.data);
    delete[] data;
    data = newdata;
    return *this;
}
String String::operator+(const String &str) const
{
    String newString;
    newString.len = len + str.len;
    newString.data = new char[newString.len + 1];
    strcpy(newString.data, data);
    strcat(newString.data, str.data);
    return newString;
}
char &String::operator[](int n) const
{
    if (n >= len)
    {
        return data[len - 1];
    }
    return data[n];
}
ostream &operator<<(ostream &os, const String &str)
{
    os << str.c_str();
    return os;
}
int main()
{
    char a[] = "Hello", b[] = "World!";
    String s1(a), s2(b);
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    s1 += s2;
    cout << s1.c_str() << endl;
    s1 = s2;
    cout << s1.c_str() << endl;
    cout << (s1 + s2).c_str() << endl;
    cout << s1.size() << endl;
    cout << s1[1] << endl;
    cout << s1 << endl;

    if (s1 == s2)
        cout << "ssss" << endl;
    return 0;
}
