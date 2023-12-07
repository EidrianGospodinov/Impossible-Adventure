#include "ListNode.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
void produce(shared_ptr<ListNode> temp, shared_ptr<bool> keepGoing)
{
			
	int k = 1;
	while (*keepGoing) {
		m.lock();
		temp->setValue(k * k);
		temp = temp->getNext();
		k++;
		m.unlock();
	}
}

void consume(shared_ptr<ListNode> temp, shared_ptr<bool> keepGoing, int targetNum) {
	int latest = -1;
	
	{
		while (latest<targetNum) {
			m.lock();

			latest = temp->getData();
			if (latest > 0) 
			{
				//cout << "Consumer value" << latest << "\n";
				temp = temp->getNext();

			}
		
			m.unlock();
		}

		*keepGoing = false;

	}

}


int main() {
	shared_ptr<ListNode> initial = make_shared<ListNode>();
	shared_ptr<bool> keepGoing = make_shared<bool>(true);
	thread producer(produce, initial, keepGoing);
	thread consumer(consume, initial, keepGoing, 25);
	initial = nullptr;
	producer.join();

	consumer.join();




	/*shared_ptr<ListNode> reading = make_shared<ListNode>();
	shared_ptr<ListNode> writing = reading;
	for (int i : {3, 5, 7, 9}) {
		cout << "Adding " << i << " to the list" << endl;
		writing->setValue(i);
		writing = writing->getNext();
	}
	int v = reading->getData();
	while (v > -1) {
		cout << "Read value " << v << " from the list" << endl;
		reading = reading->getNext();
		v = reading->getData();
	}*/



}