#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>

#include <iostream>
#include <fstream>
#include<bits/stdc++.h>



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



void loadgraph(std::ifstream &,std::vector<edgecontainer> &); //load all values into the graph including their connections
bool findingb(std::vector<edgecontainer> ,int); //checking if node is already in graph returns boolean
int finding(std::vector<edgecontainer> ,int); //checking if node is already in graph returns boolean
int inDegree( std::vector<edgecontainer> ,int); //find total number of vertices following number
void maxfollowers(std::vector<edgecontainer>); //find the max followers
void bubble(std::vector<int> &,std::vector<int> &, int); //sorting vertex from descending to ascending
void median(std::vector<edgecontainer>); //finding the middle value of  connections
void average(std::vector<edgecontainer>); //finding the average value of  connections
void shortestpath(int, int , std::vector<edgecontainer>); //finds and prints the shortest path between two nodes
int option(); //asks user for input option
void decision(int NumOfNums, std::vector<edgecontainer> all); //performs action based on user input

#endif // NODE_H_INCLUDED
