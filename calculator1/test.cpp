#include <iostream>
#include <vector>
#include <string>
#include "calculator.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

#define EXPECT_BASE(equality, expect, actual) \
	do {\
		++test_count;\
		if (equality)\
			++test_pass;\
		else \
			std::cerr << __FILE__ << __LINE__ << "expect:" << expect << "actual" << actual << std::endl;\
	}while(0)
#define EXPECT_TEST(expect, actual) EXPECT_BASE((expect)==(actual), expect, actual)

//extern Stack_char S_c_all;/*先将所有符号push进这个栈*/
//extern Stack_int S_i_all;/*先将所有数字push进这个栈*/
//extern Stack_char S_c_deal;
//extern Stack_int S_i_deal;

int test_count = 0, test_pass = 0;

int main() {
	TEST();
	std::cout << "test:\t" << test_count
			<< "\tpass:\t" << test_pass
			<< "\t比例:\t" << test_pass*1.00 / test_count
			<< endl;
}


void TEST() {
	EXPECT_TEST(10, calculator("5+5="));
	EXPECT_TEST(5, calculator("8-3="));
	EXPECT_TEST(69, calculator("23*3="));
	EXPECT_TEST(9, calculator("27/3="));
	EXPECT_TEST(3, calculator("5+4-3*2="));
	EXPECT_TEST(3, calculator("7+6-5*4/2="));
	EXPECT_TEST(5, calculator("5+3*2-6="));
}












