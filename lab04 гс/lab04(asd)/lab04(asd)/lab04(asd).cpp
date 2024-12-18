#include <iostream>
using namespace std;

int main()
{
	int N, a[10000];
	cout << "Enter number of prod: ";
	cin >> N;

	srand(time(NULL));
	rand();

	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << " ";
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	cout << endl;

	int maxSum = 0, count;
	if (N % 2 == 0) {
		count = N / 2; //кол-во элементов чётное => половина N//
	}
	else {
		count = N / 2 + 1; //иначе с добавлением одного//
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
		if (i < count) {
			maxSum += a[i];
		}
	}

	cout << endl << "Max sum: " << maxSum;
}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int N, a[10000];
//	cout << "Enter num of peop: ";
//	cin >> N;
//
//	srand(time(NULL));
//	rand();
//
//	for (int i = 0; i < N; i++) {
//		a[i] = rand() % 101;
//		cout << a[i] << " ";
//	}
// 
//	for (int i = 0; i < N; i++) {
//		for (int j = i; j < N; j++) {
//			if (a[i] < a[j]) {
//				swap(a[i], a[j]);
//			}
//		}
//	}
//
//	int count = 0, gg;
//	cout << endl;
//	
//	for (int i = 0; i < N; i++)
//	{
//		cout << a[i] << " ";
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (a[i] != a[i - 1])
//		{
//			if (count < 3)
//			{
//				cout << endl << ":) " << a[i] << endl;
//			}
//			count += 1;
//		}
//		if (count == 3)gg = i + 1; //сколько прошло//
//	}
//		 
//	cout << endl << "Count:" << gg;
//}