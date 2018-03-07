#include "../../StandardLibrary/public/headfile.hpp"

void test1()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 5);
	printSTL(vtInt);

	vector<int>::reverse_iterator rIt = find(vtInt.rbegin(), vtInt.rend(), 3);
	cout << *rIt << endl;
	cout << *rIt.base() << endl;

	vtInt.insert(rIt.base(), 1, 99);
	printSTL(vtInt);

	rIt = find(vtInt.rbegin(), vtInt.rend(), 3);
	/*vtInt.erase(rIt.base());*/
	vtInt.erase((++rIt).base());
	printSTL(vtInt);
}

int main(int argc, char *argv[])
{
	test1();

	getchar();
	return 0;
}