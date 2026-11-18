#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream source;
	ofstream target;

	string srcFileName = argv[1];
	string tgtFileName = argv[2];

    source.open(srcFileName.c_str(), ios::binary);
    target.open(tgtFileName.c_str(), ios::binary);

	if(source.is_open() && target.is_open())
	{
		while(!source.eof())
		{
			target.put(source.get());
		}
	}

	source.close();
	target.close();
}
