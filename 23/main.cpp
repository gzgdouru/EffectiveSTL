#include "../../StandardLibrary/public/headfile.hpp"

typedef pair<string, int> Data;
class DataCompare
{
public:
	// 用于排序
	bool operator()(const Data& lhs, const Data &rhs) const
	{
		return keyLess(lhs.first, rhs.first);
	}

	//用于查找比较
	bool operator()(const Data::first_type &k, const Data rhs) const
	{
		return keyLess(k, rhs.first);
	}

	//用于查找比较
	bool operator()(const Data lhs, const Data::first_type &k) const
	{
		return keyLess(lhs.first, k);
	}

private:
	bool keyLess(const Data::first_type &k1, const Data::first_type &k2) const
	{
		return k1 < k2;
	}
};

void test1()
{
	vector<Data> vd;
	for (int i = 100; i > 0; --i)
	{
		Data data = make_pair(to_string(i), i);
		vd.push_back(data);
	}
	
	sort(vd.begin(), vd.end());

	if (binary_search(vd.begin(), vd.end(), "99", DataCompare()))
	{
		cout << "99 in vd..." << endl;
	}

	auto pos = lower_bound(vd.begin(), vd.end(), "99", DataCompare());
	if (pos != vd.end())
	{
		cout << pos->first << "->" << pos->second << endl;
	}

}

int main(int argc, char *argv[])
{
	test1();

	getchar();
	return 0;
}