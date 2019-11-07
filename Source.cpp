#include <iostream>
#include <experimental/filesystem>
#include <string>
using namespace std;
using namespace std::experimental::filesystem;

int main() {
	string path = ".";
	for (auto entry : directory_iterator(path)) {
		cout << entry.path() << endl;
	}

	system("pause");
	return 0;
}
