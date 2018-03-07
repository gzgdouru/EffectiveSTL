#include "../../StandardLibrary/public/headfile.hpp"

struct referenceLess
{
	template<typename PtrType>
	bool operator()(PtrType pT1, PtrType pT2)
	{
		return *pT1 < *pT2;
	}
};

struct Dereference
{
	template<typename T>
	const T& operator()(const T* ptr) const
	{
		return *ptr;
	}
};

struct SreferenceEqual
{
	template<typename PtrType>
	bool operator()(PtrType pT1, PtrType pT2)
	{
		return *pT1 < *pT2;
	}
};

template<typename PtrType>
bool refenceEqual(PtrType p1, PtrType p2)
{
	return *p1 == *p2;
}

template<typename PtrType>
void print(PtrType p1)
{
	cout << *p1 << endl;
}

struct SPrint
{
	template<typename PtrType>
	void operator() (const PtrType ptr) const
	{
		cout << *ptr << endl;
	}
};

void test1()
{
	vector<shared_ptr<int> > vtpInt;
	vtpInt.push_back(make_shared<int>(1));
	vtpInt.push_back(make_shared<int>(2));
	vtpInt.push_back(make_shared<int>(3));
	vtpInt.push_back(make_shared<int>(4));
	vtpInt.push_back(make_shared<int>(5));

	/*auto pos = find_if(vtpInt.begin(), vtpInt.end(),
		[](int *p1) {return *p1 == 2; });*/
	//function<bool(int*)> func = bind([](int *p1, int p2) {return *p1 < p2; }, std::placeholders::_1, 2);
	shared_ptr<int> spInt(new int(2));
	auto pos = find_if(vtpInt.begin(), vtpInt.end(), bind(refenceEqual<shared_ptr<int> >, std::placeholders::_1, spInt));
	if (pos != vtpInt.end())
	{
		cout << "have value as 2..." << endl;
	}
	else
	{
		cout << "not have value as 2!!!" << endl;
	}
}

void test2()
{
	int *pX = new int(1);
	int *pY = new int(2);
	cout << refenceEqual(pX, pY) << endl;

	double *pdX = new double(1.0);
	double *pdY = new double(1.0);
	cout << refenceEqual(pdX, pdY) << endl;
}

void test3()
{
	set<shared_ptr<string>, referenceLess> ssp;
	ssp.insert(make_shared<string>("Anteater"));
	ssp.insert(make_shared<string>("Wombat"));
	ssp.insert(make_shared<string>("Lemur"));
	ssp.insert(make_shared<string>("Penguin"));
	//for_each(ssp.begin(), ssp.end(), print<shared_ptr<string>>);
	for_each(ssp.begin(), ssp.end(), SPrint());

	/*set<string*, referenceLess> ssp;
	ssp.insert(new string("Anteater"));
	ssp.insert(new string("Wombat"));
	ssp.insert(new string("Lemur"));
	ssp.insert(new string("Penguin"));
	transform(ssp.begin(), ssp.end(), ostream_iterator<string>(cout, "\n"), Dereference());*/
}

int main(int argc, char *argv[])
{
	test3();

	getchar();
	return 0;
}