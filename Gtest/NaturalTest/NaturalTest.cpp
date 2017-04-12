#include "../Main.h"



TEST(NaturalAdd, simple)
{
	BigNatural one = BigNatural(12);
	BigNatural two = BigNatural(12);

	EXPECT_TRUE(naturalMatch(BigNatural(24), ADD_NN_N(one, two)));
}


TEST(NaturalAdd, oneZero)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural(12);

	EXPECT_TRUE(naturalMatch(BigNatural(12), ADD_NN_N(one, two)));
}


TEST(NaturalAdd, bothZero)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural();

	EXPECT_TRUE(naturalMatch(BigNatural(), ADD_NN_N(one, two)));
}

TEST(NaturalAdd, longNum)
{
	BigNatural one = BigNatural(431243214);
	BigNatural two = BigNatural(675475437);

	EXPECT_TRUE(naturalMatch(BigNatural("1106718651"), ADD_NN_N(one, two)));
}

TEST(NaturalAdd, longlongNum1)
{
	BigNatural one = BigNatural("542356346745243674564321106718651423643657546436");
	BigNatural two = BigNatural("110671865154325432562346436342643634634");

	EXPECT_TRUE(naturalMatch(BigNatural("542356346855915539718646539280997859986301181070"), ADD_NN_N(one, two)));
}

TEST(NaturalAdd, longlongNum2)
{
	BigNatural one = BigNatural("6757234896957823465347563245723465234534756324573215025562381065043652348634542356346855915539718646539280997859986301181070");
	BigNatural two = BigNatural("1654744354432686143526143646487367443561446361435446434644368943463426134262932163456134626134256434626434526342466534246543264634246");

	EXPECT_TRUE(naturalMatch(BigNatural("1654744361189921040483967111834930689284911595970202759217583969025807199306584512090676982481112350166153172881747532106529565815316"), ADD_NN_N(one, two)));
}


//***************************************************************************************

TEST(NaturalCom)
{
	BigNatural one = BigNatural(431243);
	BigNatural two = BigNatural(675463464);

	ASSERT_EQ(1, COM_NN_D(one, two));
	ASSERT_EQ(2, COM_NN_D(two, one));
	ASSERT_EQ(0, COM_NN_D(one, one));
}

//***************************************************************************************


TEST(NaturalDiv, simple1)
{
	BigNatural one = BigNatural(1010);
	BigNatural two = BigNatural(10);

	EXPECT_TRUE(naturalMatch(BigNatural(101), DIV_NN_N(one, two)));
}


TEST(NaturalDiv, simple2)
{
	BigNatural one = BigNatural(123123);
	BigNatural two = BigNatural(123);

	EXPECT_TRUE(naturalMatch(BigNatural(1001), DIV_NN_N(one, two)));
}

TEST(NaturalDiv, simple3)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural(10);

	EXPECT_TRUE(naturalMatch(BigNatural(), DIV_NN_N(one, two)));
}

TEST(NaturalDiv, simple4)
{
	BigNatural one = BigNatural(1234);
	BigNatural two = BigNatural(12345);

	EXPECT_TRUE(naturalMatch(BigNatural(1234), DIV_NN_N(one, two)));
}

TEST(NaturalDiv, simple5)
{
	BigNatural one = BigNatural(6534);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(1), DIV_NN_N(one, two)));
}

TEST(NaturalDiv, simple6)
{
	BigNatural one = BigNatural("5643254356794356347856349785634757346250000793456934563475643927532479853247659000002347865893465734265000003427535732453425");
	BigNatural two = BigNatural("999347892657005623478");

	EXPECT_TRUE(naturalMatch(BigNatural("5646936765724710346765354105282115601580392966454306025003439601568983107160357473047041278182670944053"), DIV_NN_N(one, two)));
}


