// Copyright 2018 Taesoo Jun
#include "typing_machine.h"

TypingMachine::TypingMachine() {
	head = new Node(-1);
	tail = head->InsertNextNode(-1);
	cursor = head;
	len = 0;
	return;
}

void TypingMachine::HomeKey() {
	cursor = head;
	return;
}

void TypingMachine::EndKey() {
	cursor = tail->GetPreviousNode();
	return;
}

void TypingMachine::LeftKey() {
	cursor = cursor->GetPreviousNode();
	if (!cursor) cursor = head;
	return;
}

void TypingMachine::RightKey() {
	cursor = cursor->GetNextNode();
	if (cursor == tail) cursor = tail->GetPreviousNode();
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 0x20 || key > 0x7E) return false;
	if (this->len == 100) return false;
	cursor = cursor->InsertNextNode(key);
	this->len++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (cursor == head) return false;
	cursor = cursor->GetPreviousNode();
	bool ret = cursor->EraseNextNode();
	if (this->len > 0) this->len--;
	return ret;
}

std::string TypingMachine::Print(char separator) {
	str.clear();
	if (cursor == head && separator)
		str += separator;
	Node* cur = head-> GetNextNode();
	while (cur != tail) {
		str += cur->GetData();
		if (separator && cur == cursor) str += separator;
		cur = cur->GetNextNode();
	}
	return str;
}
