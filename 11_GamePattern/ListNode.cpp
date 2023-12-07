#include "ListNode.h"

ListNode::ListNode()
{
	data = -1;
	next = nullptr;
}

void ListNode::setValue(int value)
{
	
	data = value;
	next = make_shared<ListNode>();

}


