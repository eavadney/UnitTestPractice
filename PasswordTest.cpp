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
TEST(PasswordTest, empty_string_leading)
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
TEST(PasswordTest, lower_then_cap)
{
	Password pass;
	bool both = pass.has_mixed_case("zzzzzZ");
	ASSERT_EQ(true, both);
}
TEST(PasswordTest, empty_string_caps)
{
	Password pass;
	bool both = pass.has_mixed_case("");
	ASSERT_EQ(false, both);
}
TEST(PasswordTest, cap_then_lower)
{
	Password pass;
	bool both = pass.has_mixed_case("ZZZZZZz");
	ASSERT_EQ(true, both);
}
TEST(PasswordTest, only_lower)
{
	Password pass;
	bool both = pass.has_mixed_case("zzz");
	ASSERT_EQ(false, both);
}
TEST(PasswordTest, only_upper)
{
	Password pass;
	bool both = pass.has_mixed_case("ZZZ");
	ASSERT_EQ(false, both);
}
TEST(PasswordTest, caps_if_non_aphanum)
{
	Password pass;
	bool both = pass.has_mixed_case("!@#$%^&a");
	ASSERT_EQ(false, both);
}
TEST(PasswordTest, set_too_short)
{
	Password pass;
	pass.set("12345aA");
	bool authed = pass.authenticate("12345aA");
	ASSERT_EQ(authed, false);
}
TEST(PasswordTest, set_too_many_leading)
{
	Password pass;
	pass.set("aaaaBbbbbbb");
	bool authed = pass.authenticate("aaaaBbbbbbb");
	ASSERT_EQ(authed, false);
}
TEST(PasswordTest, set_not_mixed_case)
{
	Password pass;
	pass.set("aaabbbbbbb");
	bool authed = pass.authenticate("aaabbbbbbb");
	ASSERT_EQ(authed, false);
}
TEST(PasswordTest, set_already_password)
{
	Password pass;
	pass.set("myPassword");
	pass.set("myPassword");
	bool authed = pass.authenticate("myPassword");
	ASSERT_EQ(authed, true);
}
TEST(PasswordTest, auth_newest_pass)
{
	Password pass;
	pass.set("myPassword");
	pass.set("myNewPassword");
	bool authed = pass.authenticate("myNewPassword");
	ASSERT_EQ(authed, true);
}
TEST(PasswordTest, auth_old_pass)
{
	Password pass;
	pass.set("myPassword");
	pass.set("myNewPassword");
	bool authed = pass.authenticate("myPassword");
	ASSERT_EQ(authed, false);
}
TEST(PasswordTest, auth_none_set)
{
	Password pass;
	bool authed = pass.authenticate("myPasword");
	ASSERT_EQ(authed, false);
}

