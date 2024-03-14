/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 3: Network.hpp 
 * @version 0.5
 * @date 2022-10-06
 * 
 * 
 **/

#ifndef Network_H 
#define Network_H 

#include "Post.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


template<class T>
class Network
{
    private:
        static const int MAXIM = 200;
        T* pointerArr[MAXIM];

        int numAcc;

        std::vector<Post> postStored;

        //Private Function
        int getIndexOf(const std::string& userItemInd) const;

    public:
        Network(); //default constructor
        int getSizeOfNetwork() const;
        bool isEmpty() const;
        bool addAccount(T* anEntry_);//pointer to an item that will bre added to net
        bool removeAccount(const T* anEntry_); //pointer to item that will be removed from Network
        void clear();
        bool containsAccount(const T* anEntry_) const; 

        //Network Functions
        void populateNetwork(const std::string fileName_); //param has string name prints inproper format 
        void operator-=(Network<T>& networkEquals_);

        void printFeedForAccount(T& refAcc); 
        bool authenticateFollow(T& acc_, const std::string& usrname_);
        bool addToFeed(const Post& post);
        

    


};
#include "Network.cpp"
#endif