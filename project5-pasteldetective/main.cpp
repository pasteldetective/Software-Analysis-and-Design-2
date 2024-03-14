#include "Node.hpp"
#include "LinkedList.hpp"
#include "Post.hpp"
#include "General.hpp"
#include "Account.hpp"
#include "Network.hpp"
#include <iostream>
#include <functional>

int main() {

    int counter = 0;
    Post *myPostPointer = new General("T", "B", "4");
    Post *herPostPointer = new General("ye", "yeah", "7");
    Post *hisPostPointer = new General("dasd", "adsad", "3");

    LinkedList<Post*> list;
    list.insert(myPostPointer,0);
    list.insert(herPostPointer,0);    
    list.insert(hisPostPointer,0);

    list.bubbleSort(std::less<Post>{}, &counter);

    auto print = [&]() {
        Node<Post*>* curr = list.getHeadPtr();
        while (curr != nullptr)
        {
            std::cout << curr->getItem()->getUsername() << ' ';
            curr = curr->getNext();
        }
        std::cout << "\nCounter: " << counter << '\n';
    };

    print();

    counter = 0;
    list.bubbleSort(std::greater<Post>{}, &counter);
    print();
}