/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, caps_diffrent)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zzZ");
	ASSERT_EQ(2,actual);

}
TEST(PasswordTest, empty_string)
{
	Password pass;
	int actual = pass.count_leading_characters("");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, later_rep)
{
	Password pass;
	int actual = pass.count_leading_characters("abbbbbc");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, lower_and_cap)
{
	Password pass;
	bool both = pass.has_mixed_case("zZ");
	ASSERT_EQ(true, both);
}

