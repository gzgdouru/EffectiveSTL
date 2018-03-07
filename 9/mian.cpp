#include "../../StandardLibrary/public/headfile.hpp"

//删除容器中特定值的所有对象
void test1()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 9);
	vtInt.erase(remove(vtInt.begin(), vtInt.end(), 5), vtInt.end());
	printSTL(vtInt, "vector:");

	list<int> lstInt;
	insert_elements(lstInt, 1, 9);
	lstInt.remove(5);
	printSTL(lstInt, "list:");

	set<int> stInt;
	insert_elements(stInt, 1, 9);
	stInt.erase(5);
	printSTL(stInt, "set:");
}

//删除容器中满足特定判别式(条件)的所有对象
void test2()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 9);
	vtInt.erase(remove_if(vtInt.begin(), vtInt.end(), [](int x) { return x > 5; }), vtInt.end());
	printSTL(vtInt, "vector:");

	list<int> lstInt;
	insert_elements(lstInt, 1, 9);
	lstInt.remove_if([](int x) {return x > 5; });
	printSTL(lstInt, "list:");

	set<int> stInt;
	insert_elements(stInt, 1, 9);
	for (auto pos = stInt.begin(); pos != stInt.end();)
	{
		if (*pos > 5)
		{
			stInt.erase(pos++);
		}
		else
		{
			++pos;
		}
	}
	printSTL(stInt, "set:");
}

//在循环内部做某些(除了删除对象操作以外的)操作
void test3()
{
	vector<int> vtInt;
	insert_elements(vtInt, 1, 9);
	for (auto pos = vtInt.begin(); pos != vtInt.end();)
	{
		if (*pos > 5)
		{
			cout << "vector delete: " << *pos << endl;
			pos = vtInt.erase(pos);
		}
		else
		{
			++pos;
		}
	}
	printSTL(vtInt, "vector:");

	set<int> stInt;
	insert_elements(stInt, 1, 9);
	for (auto pos = stInt.begin(); pos != stInt.end();)
	{
		if (*pos > 5)
		{
			cout << "set delete: " << *pos << endl;
			stInt.erase(pos++);
		}
		else
		{
			++pos;
		}
	}
	printSTL(stInt, "set:");
}

int main(int argc, char *argv[])
{
	test3();

	getchar();
	return 0;
}