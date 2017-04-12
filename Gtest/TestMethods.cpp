#include "Main.h"


::testing::AssertionResult naturalMatch(const BigNatural & expected,
	const BigNatural & actual)
{
	if (expected.size != actual.size)
		return ::testing::AssertionFailure() << "size don't match";

	for (int i = 0; i < expected.size; ++i) {
		if (expected.coef[i] != actual.coef[i]) {
			return ::testing::AssertionFailure() << "numbers dont't match";
		}
	}

	return ::testing::AssertionSuccess();
}


::testing::AssertionResult integerMatch(const BigInteger & expected,
	const BigInteger & actual)
{
	if (expected.sign != actual.sign)
		return ::testing::AssertionFailure() << "sign don't match";

	return naturalMatch(expected.number, actual.number);
}
