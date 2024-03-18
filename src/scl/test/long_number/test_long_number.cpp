#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
	SCL::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
	SCL::LongNumber x("-1");
	ASSERT_EQ(1, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
	public:
		SCL::LongNumber one = SCL::LongNumber("1");
		SCL::LongNumber one_v2 = SCL::LongNumber("1");
		SCL::LongNumber nineteen = SCL::LongNumber("19");
		SCL::LongNumber nineteen_v2 = SCL::LongNumber("19");
		SCL::LongNumber nineteen_negative = SCL::LongNumber("-19");
		SCL::LongNumber long_positive = SCL::LongNumber("12345");
		SCL::LongNumber long_positive_bigger = SCL::LongNumber("54321");
		SCL::LongNumber long_negative = SCL::LongNumber("-12345");
		SCL::LongNumber long_negative_bigger = SCL::LongNumber("-54321");
		SCL::LongNumber one_negative = SCL::LongNumber("-1");
};

TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one == one_v2) << "Проверка " << one << " == " << one_v2;
	ASSERT_TRUE(nineteen == nineteen_v2) << "Проверка " << nineteen << " == " << nineteen_v2;
	ASSERT_FALSE(one == long_positive) << "Проверка " << one << " == " << long_positive;
	ASSERT_FALSE(long_positive == one) << "Проверка " << long_positive << " == " << one;
	ASSERT_FALSE(one == one_negative) << "Проверка " << one << " == " << one_negative;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_TRUE(one != nineteen) << "Проверка " << one << " != " << nineteen;
	ASSERT_TRUE(one != one_negative) << "Проверка " << one << " != " << one_negative;
	ASSERT_TRUE(long_positive != long_positive_bigger) << "Проверка " << long_positive << " != " << long_positive_bigger;
}

TEST_F(EqualityFixture, greater_positive) {
	ASSERT_TRUE(long_positive > nineteen) << "Проверка " << long_positive << " > " << nineteen;
	ASSERT_FALSE(nineteen > long_positive) << "Проверка " << nineteen << " > " << long_positive;
	ASSERT_TRUE(long_positive_bigger > long_positive) << "Проверка " << long_positive_bigger << " > " << long_positive;
	ASSERT_FALSE(one > one_v2) << "Проверка " << one << " > " << one_v2;
}

TEST_F(EqualityFixture, greater_negative) {
	ASSERT_TRUE(long_negative > long_negative_bigger) << "Проверка " << long_negative << " > " << long_negative_bigger;
	ASSERT_FALSE(long_negative_bigger > long_negative) << "Проверка " << long_negative_bigger << " > " << long_negative;
	ASSERT_TRUE(nineteen_negative > long_negative) << "Проверка " << nineteen_negative << " > " << long_negative;
	ASSERT_FALSE(long_negative > nineteen_negative) << "Проверка " << long_negative << " > " << nineteen_negative;
}


TEST_F(EqualityFixture, less_positive) {
	ASSERT_FALSE(long_positive < nineteen) << "Проверка " << long_positive << " < " << nineteen;
	ASSERT_TRUE(nineteen < long_positive) << "Проверка " << nineteen << " < " << long_positive;
	ASSERT_FALSE(long_positive_bigger < long_positive) << "Проверка " << long_positive_bigger << " < " << long_positive;
	ASSERT_FALSE(one < one_v2) << "Проверка " << one << " < " << one_v2;
}

TEST_F(EqualityFixture, less_negative) {
	ASSERT_FALSE(one < long_negative) << "Проверка " << one << " < " << long_negative;
	ASSERT_FALSE(one_negative < long_negative) << "Проверка " << one_negative << " < " << long_negative;
	ASSERT_FALSE(long_negative < long_negative_bigger) << "Проверка " << long_negative << " < " << long_negative_bigger;
	ASSERT_TRUE(long_negative_bigger < long_negative) << "Проверка " << long_negative_bigger << " < " << long_negative;
	ASSERT_TRUE(long_negative < nineteen_negative) << "Проверка " << long_negative << " < " << nineteen_negative;
}

TEST_F(EqualityFixture, sum_check_positive) {
	SCL::LongNumber z("12364");
	ASSERT_EQ(z, nineteen+long_positive);
}

TEST_F(EqualityFixture, sum_check_negative) {
	SCL::LongNumber z("-12364");
	ASSERT_EQ(z, nineteen_negative+long_negative);
}

TEST_F(EqualityFixture, sum_check_mixed_poitive_result) {
	SCL::LongNumber z("12326");
	ASSERT_EQ(z, long_positive+nineteen_negative);
}

TEST_F(EqualityFixture, sum_check_mixed_negative_result) {
	SCL::LongNumber z("-12326");
	ASSERT_EQ(z, long_negative+nineteen);
}

TEST_F(EqualityFixture, diff_check_positive_positive_result) {
	SCL::LongNumber z("12326");
	ASSERT_EQ(z, long_positive-nineteen);
}

TEST_F(EqualityFixture, diff_check_positive_negative_result) {
	SCL::LongNumber z("-12326");
	ASSERT_EQ(z, nineteen-long_positive);
}

TEST_F(EqualityFixture, diff_check_negative_positive_result) {
	SCL::LongNumber z("12326");
	ASSERT_EQ(z, nineteen_negative-long_negative);
}

TEST_F(EqualityFixture, diff_check_negative_negative_result) {
	SCL::LongNumber z("-12326");
	ASSERT_EQ(z, long_negative-nineteen_negative);
}

TEST_F(EqualityFixture, diff_check_mixed_poitive_result) {
	SCL::LongNumber z("12364");
	ASSERT_EQ(z, long_positive-nineteen_negative);
}

TEST_F(EqualityFixture, diff_check_mixed_negative_result) {
	SCL::LongNumber z("-12364");
	ASSERT_EQ(z, nineteen_negative-long_positive);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
