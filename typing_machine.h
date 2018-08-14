// Copyright 2018 Taesoo Jun

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

class TypingMachine {
private:
	int len;
	Node *head, *tail;
	Node* cursor;
	std::string str;
public:
	TypingMachine();
	void HomeKey();
	void EndKey();
	void LeftKey();
	void RightKey();
	bool TypeKey(char key);
	bool EraseKey();
	std::string Print(char separator);
};

#endif  // TYPING_MACHINE_H_
