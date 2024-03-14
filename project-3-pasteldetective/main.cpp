#include <iostream>
#include "Post.hpp"
#include "Account.hpp"
#include "Network.hpp"


int main()
{

    /* std::cout << "TASK 1: TEST POST CLASS" << std::endl;
    // Test constructor
    Post post1("Chicken came before the egg confirmed!", "A new story just released where we finally get the answer of who came first.");
    // Test constructor and accessor functions
    std::cout << post1.getTitle() << std::endl;
    std::cout << post1.getBody() << std::endl;
    //post1.getTimeStamp();
    // Test mutator functions
    post1.setTitle("Actually the egg came first!");
    post1.setBody("Ok, maybe the decision is not final.");
    // Test display
    std::cout << std::endl;
    post1.displayPost();
    std::cout << std::endl
              << "TASK2: TEST ACCOUNT CLASS" << std::endl
              << std::endl;
    //Test Constructor and mutator functions
    Account yash;
    yash.setUsername("yashi");
    yash.setPassword("testing123");
    //Test accessor functions:
    std::cout << yash.getUsername() << std::endl;
    std::cout << yash.getPassword() << std::endl;
    //Test parameterized constructor
    Account lenti("lenti", "testing456");
    std::cout << std::endl
              << lenti.getUsername() << std::endl;
    std::cout << lenti.getPassword() << std::endl
              << std::endl;
    // Test addPost and viewFeed
    std::cout << "PRINTING FEED: " << std::endl;
    lenti.addPost("The moon is made of cheese", "Scientific discoveries about the moon have finally revealed that the moon is actually made of cheese, confirmed.\nSource: Trust me G");
    lenti.addPost("Chicken came before the egg confirmed!", "A new story just released where we finally get the answer of who came first.");
    lenti.viewPosts(); */

    /*Post post1("Chicken came before the egg confirmed!", "A new story just released where we finally get the answer of who came first.", "gatlingGun32");
    cout << "change name: ";
    string userInput;
    cin >> userInput;
    post1.setUsername(userInput);
    cout << post1.getUsername() << " posts: " << post1.getTitle() << '\n'
         << post1.getBody(); */
    Network<Account> networkTest;
    cout << "Size: " << networkTest.getSizeOfNetwork() << '\n';
    cout << "Empty? ";
    if (networkTest.isEmpty())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << '\n';

    const string test = "a.txt";
    networkTest.populateNetwork(test);
    cout << "Empty? ";
    if (networkTest.isEmpty())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << '\n';
    cout << "Size: " << networkTest.getSizeOfNetwork() << '\n';
    //networkTest.printItems();
    Network<Account> networkTest2; // new network to compare
    const string test2 = "b.txt";
    networkTest2.populateNetwork(test2);
    //networkTest2.printItems();
    networkTest.operator-=(networkTest2);
    cout << "Size: " << networkTest.getSizeOfNetwork() << '\n';
    //networkTest.printItems();
}
