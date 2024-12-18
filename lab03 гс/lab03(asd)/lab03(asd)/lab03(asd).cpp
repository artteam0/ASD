#include <iostream>
#include <chrono>
using namespace std;

int n;
int i, j;

void Bubble(long *a);
void Paste(long* b);
void Choose(long *c);
void Quicksort(long *E, int first, int last);

int main()
{
    srand(time(NULL));
    rand();
    float time[5], q, w;
    
    long a[10000], b[10000], c[10000], E[10000], e[10000];

    cout << "xbckj: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
        b[i] = a[i];
        c[i] = a[i];
        e[i] = a[i];
    }
    Bubble(a);
    Paste(b);
    Choose(c);
    q = clock();
    Quicksort(e,0,n);
    w = clock();
    cout << endl;
    cout << "Quicksort time4 = " << (w - q) / 1000 << endl;
}

void Bubble(long *a) {

    float q, w;
    q = clock();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    w = clock();
    for (i = 0; i < n; i++) {
        cout << "" << a[i] << " ";
    }
    cout << endl;
    cout << "Bubble time = " << (w - q)/ 1000 << endl;
}

void Paste(long *b)
{
    int buff;
    float q, w;
    q = clock();

    for (i = 1; i < n; i++) {
        buff = b[i];
        for (j = i - 1; j >= 0 && b[j] > buff; j--)
            b[j + 1] = b[j];

        b[j + 1] = buff;
    }

    w = clock();

    for (i = 1; i < n; i++) {
        cout << "" << b[i] << " ";
    }

    cout << endl;
    cout << "Paste time2 = " << (w - q) / 1000 << endl;
}

void Choose(long* c)
{
    int buf, min;
    float q, w;
    q = clock();

    for (int i = 0; i < n; i++) {
        min = i;

        for (int j = i + 1; j < n; j++)
            min = (c[j] < c[min]) ? j : min;

        if (i != min) {
            buf = c[i];
            c[i] = c[min];
            c[min] = buf;
        }
    }
    w = clock();

    for (i = 0; i < n; i++) {
        cout << "" << c[i] << " ";
    }

    cout << endl;
    cout << "Choose time3 = " << (w - q) / 1000 << endl;
}

void Quicksort(long* E, int first, int last) {     //функция сортировки
    
    float q, w;
    

    int mid, count;
    int f = first, l = last;
    mid = E[(f + l) / 2]; 				//вычисление опорного элемента
    do
    {
        while (E[f] < mid) f++;
        while (E[l] > mid) l--;
        if (f <= l) 				//перестановка элементов
        {
            count = E[f];
            E[f] = E[l];
            E[l] = count;
            f++;
            l--;
        }
    } while (f <= l);
    if (first < l) Quicksort(E, first, l);
    if (f < last) Quicksort(E, f, last);

}
