#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void main()
{
	int firstNum, numForSearch, startNum, endNum, i, num, choice;

	cout << "enter your num: ";
	cin >> firstNum;
	if (firstNum == NULL) {
		cout << "gg" << endl;
		exit(69);
	}

	srand(time(NULL));
	rand();

	numForSearch = rand() % firstNum + 1;
	cout << endl << numForSearch;

	startNum = 1;
	endNum = firstNum;
	i = 0;

	while (true)
	{
		i += 1;
		num = ((endNum - startNum) / 2 + startNum);

		cout << endl << num << "?" << endl << "1.its my num" << endl << "2.is more" << endl << "3.is less" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "you win!!" << endl << "count of max steps: " << int(log(firstNum) / log(2)) + 1 << endl << "count of steps: " << i;
			exit(69);
		}
		case 2:
		{
			startNum = num;
			break;
		}
		case 3:
		{
			endNum = num;
			break;
		}

		}
	}
}