#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>



//node for holding vertex
struct node{
 int number;
 node* ptr = nullptr;
};

//class for holding all the connected vertex
class edgecontainer{
private:
    int number;
    int totalconnection=0;
    node *head= nullptr;
    node * tail = head;
public:

    void printall(std::vector<edgecontainer>);
    void pushnode(int); // push a node
    int getnode(int ); //return the node
    void setnum(int ); // set the main number
    int getnum(); //return the main number
    int gettotconnect(); //get totalconnections value


};



bool findingb(std::vector<edgecontainer> ,int); //checking if node is already in graph returns boolean
int finding(std::vector<edgecontainer> ,int); //checking if node is already in graph returns boolean
int inDegree( std::vector<edgecontainer> ,int); //find total number of vertices following number
void maxfollowers(std::vector<edgecontainer>); //find the max followers
void bubble(std::vector<int> &,std::vector<int> &, int); //sorting vertex from descending to ascending
void median(std::vector<edgecontainer>); //finding the middle value of  connections
#endif // NODE_H_INCLUDED
