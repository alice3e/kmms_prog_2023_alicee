#include <gtest/gtest.h>

#include "long_number.hpp"

using IBusko::LongNumber;

TEST(default_constructor, rank) {
	LongNumber x;
	ASSERT_EQ(1, x.get_digits_number())
		<< "По умолчанию число инициализируется нулём и иметь один разряд едениц.";
}

TEST(default_constructor, sign) {
	LongNumber x;
	ASSERT_FALSE(x.is_negative())
		<< "По умолчанию число инициализируется нулём и является неотрицательным.";
}

TEST(default_constructor, value) {
	LongNumber x;
	ASSERT_EQ(0, x.get_rank_number(1))
		<< "По умолчанию число инициализируется нулём.";
}

TEST(constructor, default_) {
	LongNumber x;
	EXPECT_FALSE(x.is_negative())
		<< "По умолчанию число инициализируется нулём и является неотрицательным.";
	ASSERT_EQ(1, x.get_digits_number())
		<< "По умолчанию число инициализируется нулём и иметь один разряд единиц.";
	ASSERT_EQ(0, x.get_rank_number(1))
		<< "По умолчанию число инициализируется нулём.";
}

class FConstructor : public testing::Test {
	public:
		LongNumber
			vn{"-1234567890"}, vd, vp{"1234567890"},
			vp_copy{vp}, vp_move{std::move(LongNumber("1234567890"))};
};

TEST_F(FConstructor, str_positive) {
	EXPECT_FALSE(vp.is_negative())
		<< "Инициализировано число 1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, vp.get_digits_number())
		<< "Инициализировано число 1234567890.";
	EXPECT_EQ(8, vp.get_rank_number(3))
		<< "Инициализировано число 1234567890. Третий разряд равен 8.";
}

TEST_F(FConstructor, str_negative) {
	EXPECT_TRUE(vn.is_negative())
		<< "Инициализировано число -1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, vn.get_digits_number())
		<< "Инициализировано число -1234567890.";
	EXPECT_EQ(8, vn.get_rank_number(3))
		<< "Инициализировано число -1234567890. Третий разряд равен 8.";
}

TEST_F(FConstructor, copy) {
	EXPECT_FALSE(vp_copy.is_negative())
		<< "Инициализировано число 1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, vp_copy.get_digits_number())
		<< "Инициализировано число 1234567890.";
	EXPECT_EQ(8, vp_copy.get_rank_number(3))
		<< "Инициализировано число 1234567890. Третий разряд равен 8.";
}

TEST_F(FConstructor, move) {
	EXPECT_FALSE(vp_move.is_negative())
		<< "Инициализировано число 1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, vp_move.get_digits_number())
		<< "Инициализировано число 1234567890.";
	EXPECT_EQ(8, vp_move.get_rank_number(3))
		<< "Инициализировано число 1234567890. Третий разряд равен 8.";
}

TEST(assignment, str) {
	LongNumber x;
	x = "1234567890";
	EXPECT_FALSE(x.is_negative())
		<< "Инициализировано число 1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, x.get_digits_number())
		<< "Инициализировано число 1234567890.";
	EXPECT_EQ(8, x.get_rank_number(3))
		<< "Инициализировано число 1234567890. Третий разряд равен 8.";
}

TEST(assignment, copy) {
	LongNumber x("1234567890");
	LongNumber y;
	y = x;
	EXPECT_FALSE(y.is_negative())
		<< "Инициализировано число 1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, y.get_digits_number())
		<< "Инициализировано число 1234567890.";
	EXPECT_EQ(8, y.get_rank_number(3))
		<< "Инициализировано число 1234567890. Третий разряд равен 8.";
}

TEST(assignment, move) {
	LongNumber x;
	x = LongNumber("1234567890");
	EXPECT_FALSE(x.is_negative())
		<< "Инициализировано число 1234567890. Оно неотрицательное.";
	ASSERT_EQ(10, x.get_digits_number())
		<< "Инициализировано число 1234567890.";
	EXPECT_EQ(8, x.get_rank_number(3))
		<< "Инициализировано число 1234567890. Третий разряд равен 8.";
}

class FComparisons : public testing::Test {
	public:
		LongNumber
			n_2{"-2"}, n_1{"-1"}, n_1_copy{"-1"},

			p_1{"1"}, p_1_copy{"1"}, p_12{"12"};
};

TEST_F(FComparisons, equal) {
	EXPECT_TRUE(p_1 == p_1_copy) << "EXPECT_TRUE: 1 == 1";
	EXPECT_FALSE(n_1 == p_1) << "EXPECT_FALSE: -1 == 1";
	EXPECT_FALSE(p_1 == p_12) << "EXPECT_FALSE: 1 == 12";
	EXPECT_EQ(p_1, p_1_copy) << "EXPECT_EQ: 1 == 1";
	EXPECT_EQ(n_1, n_1_copy) << "EXPECT_EQ: -1 == -1";
}

TEST_F(FComparisons, not_equal) {
	EXPECT_TRUE(n_1 != p_1) << "EXPECT_TRUE: -1 != 1";
	EXPECT_TRUE(p_1 != p_12) << "EXPECT_TRUE: 1 != 12";
	EXPECT_FALSE(p_1 != p_1_copy) << "EXPECT_FALSE: 1 == 1";
	ASSERT_NE(p_1, p_12) << "ASSERT_NE: 1 != 12";
	ASSERT_NE(n_1, p_1) << "ASSERT_NE: -1 != 1";
}

TEST_F(FComparisons, more) {
	EXPECT_TRUE(p_12 > p_1) << "12 > 1";
	EXPECT_TRUE(p_1 > n_1) << "1 > -1";
	EXPECT_TRUE(n_1 > n_2) << "-1 > -2";
	EXPECT_FALSE(p_1_copy > p_1) << "1 > 1";
	EXPECT_FALSE(p_1 > p_12) << "1 > 12";
}

TEST_F(FComparisons, less) {
	EXPECT_TRUE(p_1 < p_12) << "1 < 12";
	EXPECT_TRUE(n_1 < p_1) << "-1 < 1";
	EXPECT_TRUE(n_2 < n_1) << "-2 < -1";
	EXPECT_FALSE(p_1_copy < p_1) << "1 < 1";
	EXPECT_FALSE(p_12 < p_1) << "12 < 1";
}

class FArithmetic : public testing::Test {
	public:
		LongNumber
			n_19602{"-19602"}, n_99{"-99"}, n_87{"-87"}, n_15{"-15"},
			n_7{"-7"}, n_4{"-4"}, n_3{"-3"}, n_2{"-2"}, n_1{"-1"},

			p_0{"0"}, p_1{"1"}, p_1_copy{"1"}, p_2{"2"}, p_3{"3"},
			p_4{"4"}, p_6{"6"}, p_12{"12"}, p_99{"99"}, p_99_copy{"99"},
			p_113{"113"}, p_198{"198"}, p_1188{"1188"}, p_19602{"19602"},

			n_100{"-100"}, n_6{"-6"}, p_100{"100"}, p_{"6"};
};

TEST_F(FArithmetic, summ) {
	EXPECT_EQ(p_2, p_1 + p_1_copy) << "1 + 1 = 2";
	EXPECT_EQ(p_0, p_1 + n_1) << "1 + (-1) = 0";
	EXPECT_EQ(p_198, p_99 + p_99_copy) << "99 + 99 = 198";
	EXPECT_EQ(n_87, n_99 + p_12) << "-99 + 12 = -87";
	EXPECT_EQ(n_87, p_12 + n_99) << "12 + (-99) = -87";
}

TEST_F(FArithmetic, substraction) {
	EXPECT_EQ(p_0, p_1 - p_1_copy) << "1 - 1 = 0";
	EXPECT_EQ(p_2, p_1 - n_1) << "1 + (-1) = 2";
	EXPECT_EQ(n_87, p_12 - p_99) << "12 - 99 = -87";
}

TEST_F(FArithmetic, multiply) {
	EXPECT_EQ(p_1, p_1 * p_1_copy) << "1 * 1 = 1";
	EXPECT_EQ(n_1, p_1 * n_1) << "1 * (-1) = -1";
	EXPECT_EQ(p_0, p_0 * p_99) << "0 * 99 = 0";
	EXPECT_EQ(p_1188, p_12 * p_99) << "12 * 99 = 1188";
	EXPECT_EQ(n_19602, p_198 * p_99 * n_1) << "198 * 99 * -1 = -19602";
}

TEST_F(FArithmetic, division) {
	EXPECT_EQ(p_2, p_2 / p_1) << "2 / 1 = 2";
	EXPECT_EQ(p_198, p_19602 / p_99) << "19602 / 99 = 198";
	EXPECT_EQ(p_99, n_19602 / p_198 / n_1) << "-19602 / 198 / -1  = 99";
}

TEST_F(FArithmetic, remainder) {
	EXPECT_EQ(p_1, p_3 % p_2) << "3 % 2 = 1";
	EXPECT_EQ(p_6, p_19602 % p_12) << "19602 % 12 = 6";
	EXPECT_EQ(p_1, n_15 % p_4) << "-15 % 4 = 1";
	EXPECT_EQ(p_2, p_113 % n_3) << "113 % -3 = 2";
	EXPECT_EQ(p_6, n_15 % n_7) << "-15 % -7 = 6";
}

TEST_F(FArithmetic, remainder_full_sign_example) {
	EXPECT_EQ(p_4, p_100 % p_6) << "100 % 6 = 4";
	EXPECT_EQ(p_4, p_100 % n_6) << "100 % -6 = 4";
	EXPECT_EQ(p_2, n_100 % p_6) << "-100 % 6 = 2";
	EXPECT_EQ(p_2, n_100 % n_6) << "-100 % -6 = 2";
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
