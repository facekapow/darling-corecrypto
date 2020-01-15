#include <stdlib.h>
#include <ctest.h>
#include <corecrypto/ccn.h>

#define ASSERT_CCN_UNIT(exp, act, n) ASSERT_DATA((const uint8_t *)exp,\
	ccn_sizeof_n(n),\
	(const uint8_t *)act,\
	ccn_sizeof_n(n))

CTEST(ccn, ccn_shift_right) {
	const cc_size units = 16;
	const cc_size shift = 24;

#ifdef __LP64__
	cc_unit input[] = {
		0x179b057f4285e0f4,
		0x6373d54a49b82048,
		0x574f7cc723891999,
		0x7def9e087e705fcf,
		0x3a24fe3152ac1f2,
		0x2a2301b960462e4b,
		0x1f896f4e77ea7a0e,
		0x42f36aa37ade15ab,
		0xa60cc9259168a90,
		0x56e321a159b4fd97,
		0x7974f2836cddb4c0,
		0x4f85e1165e7c9423,
		0x44e1b64b3e871941,
		0x178b1a792d770a02,
		0x6232209f48fbd916,
		0xe6958c92643fb83
	};

	const cc_unit expected[] = {
		0xb82048179b057f42,
		0x8919996373d54a49,
		0x705fcf574f7cc723,
		0x2ac1f27def9e087e,
		0x462e4b03a24fe315,
		0xea7a0e2a2301b960,
		0xde15ab1f896f4e77,
		0x168a9042f36aa37a,
		0xb4fd970a60cc9259,
		0xddb4c056e321a159,
		0x7c94237974f2836c,
		0x8719414f85e1165e,
		0x770a0244e1b64b3e,
		0xfbd916178b1a792d,
		0x43fb836232209f48,
		0xe6958c926
	};
	cc_unit expected_ret = 0x85e0f40000000000;
#endif

	cc_unit actual_ret = ccn_shift_right(units, input, input, shift);

	ASSERT_EQUAL_U(expected_ret, actual_ret);
	ASSERT_CCN_UNIT(expected, input, units);
}

CTEST(ccn, ccn_shift_left) {
	const cc_size units = 16;
	const cc_size shift = 24;

#ifdef __LP64__
	cc_unit input[] = {
		0x2252d3ec6bd73c8e,
		0x7fc8c5f1563b92c1,
		0x611fe9217602a757,
		0x28387d4814a91699,
		0x690aa16738eaa711,
		0x357e6a487e73b867,
		0x5f4fb30c697409b6,
		0x4129c1d01c73601c,
		0x5aaadcdb0789dc5e,
		0x6be2a32f6c4799fe,
		0x50cf2a3b50ddb0ef,
		0xa8b44633d36c4fd,
		0x56bedd700cbc108e,
		0xee2e12a512c9408,
		0x45aac2da4dde99f1,
		0x514cc5270723ad24
	};
	const cc_unit expected[] = {
		0xec6bd73c8e000000,
		0xf1563b92c12252d3,
		0x217602a7577fc8c5,
		0x4814a91699611fe9,
		0x6738eaa71128387d,
		0x487e73b867690aa1,
		0xc697409b6357e6a,
		0xd01c73601c5f4fb3,
		0xdb0789dc5e4129c1,
		0x2f6c4799fe5aaadc,
		0x3b50ddb0ef6be2a3,
		0x633d36c4fd50cf2a,
		0x700cbc108e0a8b44,
		0x2a512c940856bedd,
		0xda4dde99f10ee2e1,
		0x270723ad2445aac2
	};
	cc_unit expected_ret = 0x514cc5;
#endif

	cc_unit actual_ret = ccn_shift_left(units, input, input, shift);

	ASSERT_EQUAL_U(expected_ret, actual_ret);
	ASSERT_CCN_UNIT(expected, input, units);
}
