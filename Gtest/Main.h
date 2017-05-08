#ifndef MAIN_H
#define MAIN_H

#include "Header.h"
#include "gtest/gtest.h"
#include "Output.h"
#include "ParserHeader.h"


::testing::AssertionResult naturalMatch(const BigNatural & expected,
	const BigNatural & actual);

::testing::AssertionResult integerMatch(const BigInteger & expected,
	const BigInteger & actual);


#endif