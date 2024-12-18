//#include <iostream>
//#include <chrono>
//using namespace std;
//
//int number(int n)
//{
//    if (n < 2) return 1;
//    return number(n - 2) + number(n - 1);
//}
//
//int main()
//{
//    setlocale(LC_CTYPE, "rus");
//
//    float a, b;
//
//    int N, i;
//    cout << "Введите количество чисел последовательности: ";
//    cin >> N;
//    
//    a = clock();
//    
//    for (i = 0; i <= N; i++)
//    {
//        cout << number(i) << " ";
//    }
//
//    cout << endl;
//
//    b = clock();
//    cout << "Затраченное время: " << (b - a) / 1000 << "c" << endl;
//
//    return 0;
//}



#include <iostream>
#include <chrono>
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    float a, b;
    long N;
    long i, k = 0, i1 = 0, i2 = 1;
    cout << "Введите количество чисел последовательности: ";
    cin >> N;

    a = clock();

    while (k < N)
    {
        i = i1 + i2;
        i1 = i2;
        i2 = i;
        k += 1;
    }
    cout << i2 << endl;

    b = clock();
    cout << "Затраченное время: " << (b - a) / 1000 << "с" << endl;
}