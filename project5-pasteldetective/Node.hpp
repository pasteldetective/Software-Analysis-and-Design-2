/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: Node.hpp 
 * @version 0.5
 * @date 2022-10-25
 * 
 *Node header file includes Node class private and public members
 **/

#ifndef Node_
#define Node_

#include <iostream>

template<typename ItemType>
class Node {

    public:
        /*
            Default Constructor
        */
        Node();

        /*
            Parametarized Constructor
            @param item - the item to be constructed
            @param next_node - the next node to point to
         */
        Node(const ItemType& item, Node<ItemType> *next_node = nullptr);

        /*
            Setter function for node item
            @param anItem - the item to be set in item_
        */
        void setItem(const ItemType &anItem);

        /*
            Setter function for pointer to next node in chain
            @param nextNodePtr - the nextNodePtr to be set in next_
        */
        void setNext(Node<ItemType> *nextNodePtr);

        /*
            @return returns the value for item_
        */
        ItemType getItem() const;

        /*
            @return returns the value for next_
        */
        Node<ItemType> *getNext() const;

        //Project 5 helper function(?)
        //void swapBetweenNodes(int &incremental);

    private:
        ItemType item_;
        Node<ItemType> *next_;
};

#include "Node.cpp"
#endif