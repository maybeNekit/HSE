#include <iostream>
using namespace std;
/*
Целые типы — int, short, long, long long
Числа с плавающей точкой — float, double, long double
Символьные типы — char, char8_t, char16_t, char32_t
Логический тип — bool
«Пустой» тип void
Нулевой указатель — std::nullptr_t
*/
int main() {
    //int
    int num = 42;
    long n = 99999999;
    long long a = -123456789012345;
    short b = -244;
    cout << "целый" << num << endl;
    cout << "длинное: " << n << endl;
    cout << "очень длинное" << a << endl;
    cout << "короткое" << b << endl;
    // символы
    string text = "fndfj";
    cout << text << endl;
    //Числа с плавающей точкой
    float f = 3.14f; // литерал с суффиксом f
    cout << "Вещественная переменная float: " << f << endl;
    double d = 1234.56789; // литерал без суффикса по умолчанию double
    cout << "Вещественная переменная double: " << d << endl;
    long double l = 9876543210.123456789L; // литерал с суффиксом L
    cout << "Вещественная переменная long double: " << l << endl;



    return 0;
}