
#include "Main.h"


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	int a = RUN_ALL_TESTS();

	system("pause");

	return 0;
}


