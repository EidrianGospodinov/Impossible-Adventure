#pragma once
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::make_shared;
using std::cout;
//using namespace std;


class ListNode
{
	int data;
	shared_ptr<ListNode> next;

public:
	int getData() {
		return data;
	}
	shared_ptr<ListNode> getNext() {
		return next;
	}


	ListNode();

	void setValue(int value);




};

