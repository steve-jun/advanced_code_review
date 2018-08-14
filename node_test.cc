// Copyright 2018 Taesoo Jun, Minkyu Jo
//#define MYMAIN

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }
  static void InsertNextNodeTest0() {
	  Node *node1 = new Node('A');
	  Node *node2 = node1->InsertNextNode('B');
	  ASSERT_TRUE(node2);
	  EXPECT_EQ(node1->GetData(), 'A');
	  EXPECT_EQ(node2->GetData(), 'B');
	  ASSERT_EQ(node1->GetNextNode(), node2);
	  ASSERT_EQ(node2->GetPreviousNode(), node1);
	  delete node1;
	  delete node2;
  }
  static void InsertNextNodeTest1() {
	  Node *node1 = new Node('A');
	  Node *node2 = node1->InsertNextNode('C');
	  Node *node3 = node1->InsertNextNode('B');
	  ASSERT_TRUE(node2&&node3);
	  EXPECT_EQ(node1->GetData(), 'A');
	  EXPECT_EQ(node2->GetData(), 'C');
	  EXPECT_EQ(node3->GetData(), 'B');
	  ASSERT_EQ(node1->GetNextNode(), node3);
	  ASSERT_EQ(node3->GetNextNode(), node2);
	  ASSERT_EQ(node2->GetPreviousNode(), node3);
	  ASSERT_EQ(node3->GetPreviousNode(), node1);
	  delete node1;
	  delete node2; 
	  delete node3;
  }
  static void InsertPrevNodeTest0() {
	  Node *node1 = new Node('A');
	  Node *node2 = node1->InsertPreviousNode('B');
	  ASSERT_TRUE(node2);
	  EXPECT_EQ(node1->GetData(), 'A');
	  EXPECT_EQ(node2->GetData(), 'B');
	  ASSERT_EQ(node1->GetPreviousNode(), node2);
	  ASSERT_EQ(node2->GetNextNode(), node1);
	  delete node1;
	  delete node2;
  }
  static void InsertPrevNodeTest1() {
	  Node *node1 = new Node('A');
	  Node *node2 = node1->InsertPreviousNode('C');
	  Node *node3 = node1->InsertPreviousNode('B');
	  ASSERT_TRUE(node2&&node3);
	  EXPECT_EQ(node1->GetData(), 'A');
	  EXPECT_EQ(node2->GetData(), 'C');
	  EXPECT_EQ(node3->GetData(), 'B');
	  ASSERT_EQ(node1->GetPreviousNode(), node3);
	  ASSERT_EQ(node3->GetPreviousNode(), node2);
	  ASSERT_EQ(node3->GetNextNode(), node1);
	  ASSERT_EQ(node2->GetNextNode(), node3);
	  delete node1;
	  delete node2;
	  delete node3;
  }
  static void EraseNextTest0() {
	  Node *node = new Node('A');
	  ASSERT_EQ(node->EraseNextNode(), false);
	  delete node;
  }
  static void ErasePrevTest0() {
	  Node *node = new Node('A');
	  ASSERT_EQ(node->ErasePreviousNode(), false);
	  delete node;
  }
  static void EraseNextTest1() {
	  Node *node1 = new Node('A');
	  node1->InsertNextNode('B');
	  ASSERT_EQ(node1->EraseNextNode(), true);
	  ASSERT_TRUE(node1->GetNextNode() == nullptr);
	  delete node1;
  }
  static void ErasePrevTest1() {
	  Node *node1 = new Node('A');
	  node1->InsertPreviousNode('B');
	  ASSERT_EQ(node1->ErasePreviousNode(), true);
	  ASSERT_TRUE(node1->GetPreviousNode() == nullptr);
	  delete node1;
  }
  static void EraseNextTest2() {
	  Node *node1 = new Node('A');
	  Node *node2 = node1->InsertNextNode('B');
	  Node *node3 = node2->InsertNextNode('C');
	  EXPECT_EQ(node1->GetData(), 'A');
	  EXPECT_EQ(node2->GetData(), 'B');
	  EXPECT_EQ(node3->GetData(), 'C');
	  ASSERT_EQ(node1->EraseNextNode(), true);
	  ASSERT_TRUE(node1->GetNextNode() == node3);
	  ASSERT_TRUE(node3->GetPreviousNode() == node1);
	  delete node1;
	  delete node3;
  }
  static void ErasePrevTest2() {
	  Node *node1 = new Node('A');
	  Node *node2 = node1->InsertPreviousNode('B');
	  Node *node3 = node2->InsertPreviousNode('C');
	  EXPECT_EQ(node1->GetData(), 'A');
	  EXPECT_EQ(node2->GetData(), 'B');
	  EXPECT_EQ(node3->GetData(), 'C');	
	  ASSERT_EQ(node1->ErasePreviousNode(), true);
	  ASSERT_TRUE(node1->GetPreviousNode() == node3);
	  ASSERT_TRUE(node3->GetNextNode() == node1);
	  delete node1;
	  delete node3;
  }

public:
  static void RunTest() {
    SingleNodeTest();
	InsertNextNodeTest0();
	InsertNextNodeTest1();
	InsertPrevNodeTest0();
	InsertPrevNodeTest1();
	EraseNextTest0();
	EraseNextTest1();
	EraseNextTest2();
	ErasePrevTest0();
	ErasePrevTest1();
	ErasePrevTest2();
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

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  // add more..
}

#ifdef MYMAIN
int main() {
	NodeTest();
	return 0;
}
#endif