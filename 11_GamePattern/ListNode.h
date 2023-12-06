#pragma once
#include <memory>
using std::shared_ptr;
using std::make_shared;
//using namespace std;


class ListNode
{
	int data;
	shared_ptr<ListNode> next=make_shared<ListNode>();

public:
	int getData() {
		return data;
	}
	shared_ptr<ListNode> getNext() {
		return next;
	}


	ListNode() {
		data=-1;
		next = nullptr;

	}

	void setValue(int value) {
		data = value;
		
		
		

	}
};

