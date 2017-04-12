
#include "Main.h"


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	int a = RUN_ALL_TESTS();

	system("pause");

	return 0;
}

TEST(BigNaturalTest, adding)
{
	BigNatural one = BigNatural(12);
	BigNatural two = BigNatural(12);

	EXPECT_TRUE(naturalMatch(BigNatural(24), ADD_NN_N(one, two)));
}

