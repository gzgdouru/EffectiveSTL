#include "../../StandardLibrary/public/headfile.hpp"

template<typename MapType, typename KeyArgType, typename ValueArgType>
typename MapType::iterator efficientAddOrUpdate(MapType &m, const KeyArgType &key, const ValueArgType &value)
{
	auto lb = m.lower_bound(key);

	if (lb != m.end() && !(m.key_comp()(key, lb->first)))
	{
		lb->second = value;
		return lb;
	}
	else
	{
		return m.insert(lb, make_pair(key, value));
	}
}

void test1()
{
	map<int, string> mpStr;
	efficientAddOrUpdate(mpStr, 1, "hello");
	efficientAddOrUpdate(mpStr, 1, "hi");

	for (auto pos : mpStr)
	{
		cout << pos.first << "->" << pos.second << endl;
	}
}

int main(int argc, char *argv[])
{
	test1();

	getchar();
	return 0;
}