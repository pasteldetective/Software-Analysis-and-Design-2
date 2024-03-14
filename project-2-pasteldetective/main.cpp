#include <iostream>
#include "Post.hpp"
#include "General.hpp"
#include "Poll.hpp"

int main()
{   
    std::cout << "TASK 0: TEST" << std::endl;

    // Test constructor
    Post post1("Chicken came before the egg confirmed!", "A new story just released where we finally get the answer of who came first.","sam chiu");

    // Test constructor and accessor functions
    std::cout << post1.getTitle() << std::endl;
    std::cout << post1.getBody() << std::endl;
    std::cout << post1.getUsername() << std::endl;
    post1.getTimeStamp();

    // Test mutator functions
    post1.setTitle("Actually the egg came first!");
    post1.setBody("Ok, maybe the decision is not final.");

    // Test display
    std::cout << std::endl;
    post1.displayPost();

    //Task 1
    std::cout << "TASK 1: TEST" << std::endl;
    
    General monicaCarvel("monica","carveldsa","monicaCarvel");//test constructor

    //Test mutator functions
    monicaCarvel.reactToPost(SAD);

    //Test accessor functions
    monicaCarvel.getReactions();

    //Task 2
    std::cout << "TASK 2: TEST" << std::endl;

    Poll somePoll("Hello World?","Hell?","sammieevee",{"Hello?","Goodbye","What"});//test constructor
    somePoll.changePollOption("UHHH",3);

    somePoll.votePoll(0);
    somePoll.votePoll(0);
    somePoll.votePoll(2);
    somePoll.votePoll(3);

    somePoll.getPollOptions();



}