/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: LinkedList.cpp
 * @version 0.5
 * @date 2022-10-25
 * 
 * LinkedList class provided by Professor includes class functions of LinkedList 
 **/

#include <iostream>

template <typename ItemType>
LinkedList<ItemType>::LinkedList() : head_{nullptr}, size_{0} {} //constructor

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList &list) : head_{nullptr}, size_{0}
{
	if (!list.isEmpty())
	{
		Node<ItemType> *copyHead = list.getHeadPtr();
		int counter = 0;

		while (counter < list.getSize())
		{
			insert(copyHead->getItem(), counter);
			counter++;
			copyHead = copyHead->getNext();
		}
	}
}

template <typename ItemType>
Node<ItemType> *LinkedList<ItemType>::getHeadPtr() const //gets Head pointer
{
	return head_;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() //clears list
{
	Node<ItemType> *curr_item = head_;
	Node<ItemType> *temp = curr_item;
	for (int i = 0; i < size_; i++)
	{
		temp = curr_item;
		curr_item = curr_item->getNext();
		delete temp;
	}
	temp = nullptr;
	size_ = 0;
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() //destructor
{
	clear();
}

// Function inserts item at a position
template <typename ItemType>
bool LinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
	if ((position < 0 || position > size_))
	{
		return false;
	}

	Node<ItemType> *node = new Node<ItemType>();
	node->setItem(item);

	if (size_ == 0)
	{
		head_ = node;
	}
	else
	{
		Node<ItemType> *iterator;

		if (position == 0)
		{
			node->setNext(head_);
			head_ = node;
		}

		else if (position == size_)
		{
			iterator = getAtPos(size_ - 1);
			iterator->setNext(node);
		}
		else
		{
			iterator = getAtPos(position - 1);
			node->setNext(iterator->getNext());
			iterator->setNext(node);
		}
	}
	size_++;
	return true;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(const int &position) //removes list pointer node
{
	if (position < 0 || position >= size_)
	{
		return false;
	}

	Node<ItemType> *iterator;

	if (position == 0)
	{
		iterator = head_;
		head_ = head_->getNext();
	}
	else
	{
		iterator = getAtPos(position - 1);
		iterator->setNext(iterator->getNext()->getNext());
		iterator = iterator->getNext();
	}

	size_--;
	return true;
}

//Project 4
/*
Sets the current LinkedList with the same items as the provided LinkedList
but in reverse order
*/
template <typename ItemType>
void LinkedList<ItemType>::reverseCopy(const LinkedList<ItemType> &a_list)
{
	clear(); 
	Node<ItemType> *current = a_list.getHeadPtr(); //Node templateItemtype points to a_list head pointer
	while (current != nullptr){ //while != nullptr iterates through and copys the list
		head_ = new Node<ItemType>(current->getItem(),head_);
		current = current->getNext();
		//insert(current->getItem(), START);
		//current = current->getNext();
		//remove(END);
		// next = current->getNext();
		// current->setNext(prev);
		// prev = current;
		// current = next;
	}
	size_ = a_list.getSize();
	// head_ = prev;
}

template <typename ItemType>
int LinkedList<ItemType>::getIndexOf(const ItemType &item) const //function gets index of list
{
	Node<ItemType> *curr_item = head_; //at current item
	int counter = 0; //counter
	while (curr_item != nullptr)
	{
		if (curr_item->getItem() == item)
		{
			return counter;
		}
		counter++;
		curr_item = curr_item->getNext();
	}
	return -1;
}

template <typename ItemType>
Node<ItemType> *LinkedList<ItemType>::getAtPos(const int &pos) const //function gets current item position
{

	if (pos < 0 || pos >= size_)
	{
		return nullptr;
	}

	Node<ItemType> *curr_item = head_;
	int counter = 0;
	while (counter < pos && curr_item != nullptr)
	{
		counter++;
		curr_item = curr_item->getNext();
	}
	return curr_item;
}

template <typename ItemType>
int LinkedList<ItemType>::getSize() const
{
	return size_;
}

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const //checks if list is empty
{
	return size_ == 0 ? true : false;
}

template <typename ItemType>
bool LinkedList<ItemType>::moveItem(int &current_position, int &new_position)
{
	if (
		(current_position > -1 && current_position < size_) &&
		(new_position > -1 && new_position < size_))
	{
		if (new_position != current_position)
		{
			if (new_position < current_position)
			{
				ItemType temp = this->getAtPos(current_position)->getItem();
				this->getAtPos(current_position)->setItem(this->getAtPos(current_position - 1)->getItem());
				this->getAtPos(current_position - 1)->setItem(temp);
				current_position--;
			}
			else
			{
				ItemType temp = this->getAtPos(current_position)->getItem();
				this->getAtPos(current_position)->setItem(this->getAtPos(current_position + 1)->getItem());
				this->getAtPos(current_position + 1)->setItem(temp);
				current_position++;
			}

			return moveItem(current_position, new_position);
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*
This function will take the item from its current position and move it to the front
of the list.
*/
template <typename ItemType>
bool LinkedList<ItemType>::moveItemToTop(const ItemType &item)
{
	if (getIndexOf(item) < 1) // If the item does not exist or it is already on top, return false
	{
		return false;
	}
	else
	{
		Node<ItemType> *new_head = new Node<ItemType>(); // Create a new head Node
		new_head->setItem(item);						 // Set the value of the new head Node to the item you want to move
		remove(getIndexOf(item));						 // Remove the item you want to move from the List
		new_head->setNext(head_);						 // Set the new head pointer's next value to the current head pointer
		head_ = new_head;								 // Set the List's head to the new head pointer
		return true;
	}
}