/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: Node.hpp 
 * @version 0.5
 * @date 2022-10-25
 * 
 * Node class file includes class functions destructors and constructors
 **/
/*
    Default Constructor
*/
template <class ItemType>
Node<ItemType>::Node() : next_{nullptr} {}


/*
    Parametarized Constructor
    @param item - the item to be constructed
    @param next_node - the next node to point to
 */
template <class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType> *next_node) : item_{item}, next_{next_node} {}


/*
    Setter function for node item
    @param anItem - the item to be set in item_
*/
template <class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) {
    item_ = anItem;
}


/*
    Setter function for pointer to next node in chain
    @param nextNodePtr - the nextNodePtr to be set in next_
*/
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr){
    next_ = nextNodePtr;
}

/*
    @return returns the value for item_
*/
template <class ItemType>
ItemType Node<ItemType>::getItem() const { return item_; }


/*
    @return returns the value for next_
*/
template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const { return next_; }


/*
Might comment out Project 5 helper function

template <class ItemTyoe>
template <class Comparator>
void Node<Itemtype>::swapBetweenNodes(int &incremental)
{
    
    
    n->getItem()
    <ItemType> temp = a->getItem()
    temp = a->getItem()
    a->setItem(a-> getNext())->getTotal()
    a->getNext()->setTemp(temp);
    
    



    incremental++;
}
*/