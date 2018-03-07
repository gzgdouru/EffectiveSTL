#include "../../StandardLibrary/public/headfile.hpp"

void test1()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 100);
	printSTL(vtInt);

	partial_sort(vtInt.begin(), vtInt.begin() + 20, vtInt.end(), greater<int>());
	printSTL(vtInt);
}

void test2()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 50);
	random_shuffle(vtInt.begin(), vtInt.end());
	printSTL(vtInt);

	cout << *(vtInt.begin() + 25) << endl;
	nth_element(vtInt.begin(), vtInt.begin() + 25, vtInt.end(), greater<int>());
	printSTL(vtInt);
	cout << *(vtInt.begin() + 25) << endl;
}

int main(int argc, char *argv[])
{
	test2();

	getchar();
	return 0;
}