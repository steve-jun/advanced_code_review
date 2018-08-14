// Copyright 2018 Taesoo Jun

#include "node.h"

Node::Node(char data) {
	c = data;
	prev = nullptr;
	next = nullptr;
	return;
}

char Node::GetData() {
	return c;
}

Node* Node::GetPreviousNode() {
	return prev;
}

Node* Node::GetNextNode() {
	return next;
}

Node* Node::InsertPreviousNode(char data) {
	Node* node = new Node(data);
	node->prev = this->prev;
	node->next = this;
	if (this->prev)
		this->prev->next = node;
	this->prev = node;
	return node;
}

Node* Node::InsertNextNode(char data) {
	Node* node = new Node(data);
	node->prev = this;
	node->next = this->next;
	if (this->next)
		this->next->prev = node;
	this->next = node;
	return node;
}

bool Node::ErasePreviousNode() {
	Node* prev = this->prev;
	if (!prev) return false;

	if (prev->prev)
		prev->prev->next = this;
	this->prev = prev->prev;
	delete prev;
	return true;
}

bool Node::EraseNextNode() {
	Node* next = this->next;
	if (!next) return false;

	if (next->next)
		next->next->prev = this;
	this->next = next->next;
	delete next;
	return true;
}

