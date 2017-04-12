#include "Main.h"


::testing::AssertionResult naturalMatch(const BigNatural & expected,
	const BigNatural & actual)
{
	if (expected.size != actual.size)
		return ::testing::AssertionFailure() << bigNaturalToString(expected) << "!=" << bigNaturalToString(actual);

	for (int i = 0; i < expected.size; ++i) {
		if (expected.coef[i] != actual.coef[i]) {
			return ::testing::AssertionFailure() << bigNaturalToString(expected) << "!=" << bigNaturalToString(actual);
		}
	}

	return ::testing::AssertionSuccess();
}


::testing::AssertionResult integerMatch(const BigInteger & expected,
	const BigInteger & actual)
{
	if (expected.sign != actual.sign)
		return ::testing::AssertionFailure() << bigIntegerToString(expected) << "!=" << bigIntegerToString(actual);

	return naturalMatch(expected.number, actual.number);
}
