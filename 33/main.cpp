#include "../../StandardLibrary/public/headfile.hpp"

struct SDeleteInt
{
	template<typename ptrType>
	bool operator()(ptrType pX)
	{
		return *pX == 3;
	}
};

template<typename ptrType>
bool deleteInt(ptrType pX)
{
	return *pX == 3;
}

template<typename ptrType>
void printInt(ptrType pX)
{
	cout << *pX << " ";
}

void test1()
{
	vector<int*> vtInt;
	for (int i = 1; i < 11; ++i)
	{
		vtInt.push_back(new int(i));
	}
	for_each(vtInt.begin(), vtInt.end(), printInt<int*>);
	cout << endl;

	//vtInt.erase(remove_if(vtInt.begin(), vtInt.end(), deleteInt<int*>));	// 内存泄漏
	vtInt.erase(remove_if(vtInt.begin(), vtInt.end(), SDeleteInt()));	// 内存泄漏
	for_each(vtInt.begin(), vtInt.end(), printInt<int*>);
	cout << endl;
}

void test2()
{
	vector<shared_ptr<int>> vtInt;
	for (int i = 1; i < 11; ++i)
	{
		vtInt.push_back(make_shared<int>(i));
	}
	for_each(vtInt.begin(), vtInt.end(), printInt<shared_ptr<int>>);
	cout << endl;

	//vtInt.erase(remove_if(vtInt.begin(), vtInt.end(), deleteInt<shared_ptr<int>>));	// 不会内存泄漏
	vtInt.erase(remove_if(vtInt.begin(), vtInt.end(), SDeleteInt()));
	for_each(vtInt.begin(), vtInt.end(), printInt<shared_ptr<int>>);
	cout << endl;
}
stricmp()
int main(int argc, char *argv[])
{
	test2();

	getchar();
	return 0;
}