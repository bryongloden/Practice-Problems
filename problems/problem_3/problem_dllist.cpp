#include <iostream>
#include <string>
#include "DLList.h"

// Constructor
// DO NOT CHANGE
DLList::DLList()
{
    head = new ListNode();
    head->next = head;
    head->prev = head;
}

// Prints the list
// DO NOT CHANGE
void DLList::print_list()
{
    std::cout << "Printing List..." << std::endl;
    if ( head->next == head ) {
	std::cout << "Empty List" << std::endl;
    }
    else {
	ListNode * e = head->next;
	while ( e != head) {
	    if ( e->next != head )
		std::cout << e->value << ", ";
	    else
		std::cout << e->value;
	    e = e->next;
	}
	std::cout << std::endl;
    }
}

// Prints the list given a list name
// DO NOT CHANGE
void DLList::print_list( std::string list_name )
{
    std::cout << "Printing " << list_name << "..." << std::endl;
    if ( head->next == head ) {
	std::cout << "Empty List" << std::endl;
    }
    else {
	ListNode * e = head->next;
	while ( e != head) {
	    if ( e->next != head )
		std::cout << e->value << ", ";
	    else
		std::cout << e->value;
	    e = e->next;
	}
	std::cout << std::endl;
    }
}

// Problem (1/5)
/******************************************************************************
 * TODO: Write the destructor. The destructor should delete all of the
 * list nodes from the list.
 *****************************************************************************/
DLList::~DLList()
{
    // Write Your Code Here
    ListNode *last = NULL;
    ListNode *newLast = NULL;
    while ( head != NULL) {
      last = head->prev;
      newLast = last->prev;
      head->prev = newLast;
      if (last == head) { delete head; head = NULL; last = NULL; }
      delete last;
      last = NULL;
    }
    last = NULL;
    newLast = NULL;
    head = NULL;
}

// Problem (2/5)
/******************************************************************************
 * TODO: Insert a new ListNode to the end of the double linked list.
 * Remember the list head is a sentinel node, do not change head.
 * Set the value of the new node to the parameter 'value'.
 *
 * Parameters: value -- set the value of the node equal to this
 *
 * Return: void
 *
 * Return Type: void
 *****************************************************************************/
 void DLList::insert_last( int value )
 {
   // Write Your Code Here
   if (head->next == head) {
     ListNode *last = new ListNode();
     head->value = 0;
     last->value = value;
     last->next = head;
     last->prev = head;
     head->next = last;
     head->prev = last;
   } else {
     ListNode *oldLast = head->prev;
     ListNode *newLast = new ListNode();
     newLast->value = value;
     newLast->next = head;
     newLast->prev = oldLast;
     oldLast->next = newLast;
     head->prev = newLast;
   }
   return;
 }

// Problem (3/5)
/******************************************************************************
 * TODO: Remove the node from the double linked list whose value equals the
 * parameter 'value', return true after deleting the node. If the node does not
 * exist in the list or the list is empty, return false;
 *
 * Parameters: value -- remove the node whose value is equal to this
 *
 * Return: true if the node was removed successfully
 *         false if the value does not exist in the list or the list is empty
 *
 * Return Type: void
 *****************************************************************************/
bool DLList::remove( int value )
{
  // Write Your Code Here
  ListNode *deleteMe = head->next;
  while(deleteMe != head) {
    if(deleteMe->value == value) {
      (deleteMe->next)->prev = deleteMe->prev;
      (deleteMe->prev)->next = deleteMe->next;
      delete deleteMe;
      deleteMe = NULL;
      return true;
    }
    deleteMe = deleteMe->next;
  }
  return false;
}

// Problem (4/5)
/*****************************************************************************
* TODO: Return the ith node inside of the double linked list. If the list is
* empty or has less than 'ith' entries, return NULL.
*
* Return: the 'ith' node in the list
*         NULL if the node does not exist
*
* Return Type:
*****************************************************************************/
ListNode * DLList::get_ith( int ith ) const
{
    // Write Your Code Here
    int iterator = 0;
    ListNode *currentNode = head->next;
    while(currentNode!=head) {

      if (iterator == ith) {
        break;
      }

      iterator++;
      currentNode = currentNode->next;
    }

    if (currentNode!=head) {
      return currentNode;
    }

   return NULL;
}

// Problem (5/5)
/*****************************************************************************
* TODO: Overload the operator '==' for comparison. The comparison operator
* should compare the two lists to check if they have the all of the same
* elements. Return true if the two lists are equal, return false otherwise.
*****************************************************************************/
bool DLList::operator == (const DLList & listB)
{
    // Write Your Code Here
    int i = 0;
    int valueA = 0;
    int valueB = 0;

    ListNode *nodeA = NULL;
    ListNode *nodeB = NULL;

    while(true) {
      nodeA = get_ith(i);
      nodeB = listB.get_ith(i);
      if (nodeA == NULL && nodeB == NULL) { return true;}
      if (nodeA == NULL || nodeB == NULL) { return false;}
      if (nodeA->value != nodeB->value) { return false;}
      i++;
    }
}
