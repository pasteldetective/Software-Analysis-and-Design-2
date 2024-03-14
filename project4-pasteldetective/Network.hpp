/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: Network.hpp 
 * @version 0.5
 * @date 2022-10-25
 * 
 *Network Header file includes Network class private and public members
 **/

#ifndef Network_H 
#define Network_H 

#include "Post.hpp"
#include "LinkedList.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


template<class ItemType>
class Network
{
    private:
        static const int MAXIM = 200;
        ItemType* pointerArr[MAXIM];

        int numAcc;

        //changed for project 4
        LinkedList<Post*>postStored; 

        //Private Function
        int getIndexOf(const std::string& userItemInd) const;

    public:
        Network(); //default constructor
        int getSizeOfNetwork() const;
        bool isEmpty() const;
        bool addAccount(ItemType* anEntry_);//pointer to an item that will bre added to net
        bool removeAccount(const ItemType* anEntry_); //pointer to item that will be removed from Network
        void clear();
        bool containsAccount(const ItemType* anEntry_) const; 

        //Network Functions
        void populateNetwork(const std::string fileName_); //param has string name prints inproper format 
        void operator-=(Network<ItemType>& networkEquals_);

        void printFeedForAccount(ItemType& refAcc); 
        bool authenticateFollow(ItemType& acc_, const std::string& usrname_);
        
        
        //Project 4
        int removeIfContains(const std::string &flagged); //funct to remove flagged keywords
        bool addToFeed(Post* newerPost); //funct to add post to feed
        void moveItemToTop(Post* object); 
        void updateFeed(Post * list);
    


};
#include "Network.cpp"
#endif