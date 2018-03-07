#include "../../StandardLibrary/public/headfile.hpp"

void test1()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 9);
	printSTL(vtInt);

	for (vector<int>::const_iterator cit = vtInt.begin(); cit != vtInt.end(); ++cit)
	{
		if (*cit == 8)
		{
			vector<int>::iterator it = vtInt.begin();
			advance(it, distance<vector<int>::const_iterator>(it, cit));
			*it = 12;
		}
	}
	printSTL(vtInt);
}

int main(int argc, char *argv[])
{
	test1();

	getchar();
	return 0;
}