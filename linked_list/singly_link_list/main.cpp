#include <iostream>
#include "singly_link_list.h"

using namespace std;

int main(){
	vector<int> arr = {11, 2, 34, 14, 5, 61, 7, 18, 9, 10};
	
	LinkList *list = new LinkList();
	list->createList(arr);
	
// 	list->push_back(101);
// 	list->push_front(0);
	
// 	list->pop_back();
// 	list->pop_front();
	
	list->quick_sort(list->head, list->tail);
	list->printList();
	
	return 0;
}