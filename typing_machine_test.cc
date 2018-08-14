// Copyright 2018 Taesoo Jun, Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"
//#define MYMAIN

class TmConstructorTestSuite
{
private:
	static void BarSeparatorTest() {
		TypingMachine tm;
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}
	static void TmConstructorTest() {
		TypingMachine tm;
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}
	static void TmTypeTest() {
		TypingMachine tm;
		bool ret = tm.TypeKey(0x1F);
		ASSERT_TRUE(ret == false);
		ret = tm.TypeKey(0x7F);
		ASSERT_TRUE(ret == false);

		std::string str;
		for (int i = 0; i < 100; ++i) {
			char c = (i % 10 + '0');
			tm.TypeKey(c);
			str += c;
		}
		str += "|";
		ASSERT_EQ(tm.Print('|'), str);
	}
	static void TmEraseTest() {
		TypingMachine tm;
		bool ret = tm.EraseKey();
		ASSERT_TRUE(ret == false);
		tm.TypeKey('1');
		ret = tm.EraseKey();
		ASSERT_TRUE(ret == true);
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}
	static void TmCursorTest() {
		TypingMachine tm;
		tm.TypeKey('1');
		tm.TypeKey('2');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|12"));
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("12|"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("1|2"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("12|"));
	}
	static void TmStressTest() {
		TypingMachine tm;
		std::string str;
		for (int i = 0; i < 100; ++i) {
			char c = (i % 10 + '0');
			tm.TypeKey(c);
			str += c;
		}
		str += "|";
		bool ret = tm.TypeKey('1');
		ASSERT_TRUE(ret == false);
		ASSERT_EQ(tm.Print('|'), str);
	}

public:
  static void RunTest() {
    BarSeparatorTest();
	TmConstructorTest();
	TmTypeTest();
	TmEraseTest();
	TmCursorTest();
	TmStressTest();
    // add more..
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  // add more..
}

#ifdef MYMAIN
int main() {
	TypingMachineTest();
	return 0;
}
#endif