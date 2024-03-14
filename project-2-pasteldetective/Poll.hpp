/*
Jackie Yee CSCI 235 Professor Ligorio
Poll.hpp
9/20/2022
This file contains the class for Poll and inheritance post 
*/
#ifndef POLL_HPP_ 
#define POLL_HPP_

#include "Post.hpp"
#include <iostream>
/*
Jackie Yee CSCI 235 Professor Ligorio
Poll.hpp
9/20/2022
This file contains the class for Poll
*/
#include <vector>
using namespace std;

class Poll : public Post //class poll inherits Post class
{
    private:
        vector<string> pollOpt; //vectors declaration
        vector<int> numVotes;
    public:
        Poll(string pollTitle, string pollBody, string pollUsername, vector<string> options); //parameterized constructor 
        bool votePoll(const int& pollOptIn); //function to vote for a poll
        void changePollOption(const string newPollOpt, const int& optInRep ); //change poll opts
        void getPollOptions() const; // gets PollOptions
        int getPollVotes(const int& inOpt); // func get poll votes
        void displayPost() const; //displat post
};
#endif