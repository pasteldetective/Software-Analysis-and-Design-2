#ifndef Network_HPP_
#define Network_HPP_

#include "Account.hpp"
#include <vector>

template<class ItemType>
class Network
{
    public:
        Network(); //default constructor
        int getSizeOfNetwork() const;
        bool isEmpty() const;
        bool addAccount(const ItemType &newItem);//pointer to an item that will bre added to net
        bool removeAccount(const ItemType &anEntry); //pointer to item that will be removed from Network
        void clear();
        bool containsAccount(const ItemType &anEntry) const; 
        void populateNetwork(const std::string fileName); //param has string name prints inproper format 
        void operator-=(const std::string networkEquals);
    private:
        int pointArr[200];
        int numAcc;
        vector<int> postStored;
        int getIndexOf(const std::string userItemInd) const;


};
#endif