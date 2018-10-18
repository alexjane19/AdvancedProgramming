#include<iostream>
#include<fstream>
#include"Universe.h"

using namespace std;
int main()
{
	Universe uni(3);
	ofstream f1("file.txt", ios::binary);
	int switch_on=1;
	while (1)
	{
		cout << "1.Insert\n2.Show\n3.Edit\n4.exit";
	switch (switch_on)
		{
		case 1:
			uni.createGalaxy();
			uni.enterInfoGalaxy();
			f1.write((char*) &uni, sizeof(uni));
			f1.close();
			break;
		case 2:

			break;
		case 3:
				break;
			case 4:
				break;

		default:
			break;
		}
	}

	return 0;
}
