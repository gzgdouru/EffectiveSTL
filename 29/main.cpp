#include "../../StandardLibrary/public/headfile.hpp"

void test1()
{
	ifstream inputFile("main.cpp");
	/*inputFile.unsetf(ios::skipws);
	string szFileData((istream_iterator<char>(inputFile)), istream_iterator<char>());*/

	string szFileData((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
	cout << szFileData << endl;
}

int main(int argc, char *argv[])
{
	test1();

	getchar();
	return 0;
}