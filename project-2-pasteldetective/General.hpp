/*
Jackie Yee CSCI 235 Professor Ligorio
General.hpp
9/20/2022
This file contains the class for General and inheritance post 
*/

#ifndef GENERAL_HPP_ 
#define GENERAL_HPP_

#include "Post.hpp"
#include <iostream>
using namespace std;

//create enum out of class and name Reactions
enum Reactions {LIKE, DISLIKE, LAUGH, WOW, SAD, ANGRY}; 

class General : public Post //gen class inherits post class
{
    private:
        int reactionArr[6];  //An integer array of size 6 that, indexed by Reactions, will store the number of reactions of each type the post has received.   
    public:
        General(string name, string body, string username); 
        bool reactToPost(const Reactions& makeReaction);
        void getReactions() const;
        void displayPost() const; //function prints Posts

};

#endif