#include "node.h"
#include <vector>
#include <iostream>


//precondition: pass two vectors( one for postions of vertices and the other for value) and the size of the vector
//postcond: sorts the whole array
void bubble(std::vector<int> &Arr,std::vector<int> &pos, int len)
{
    bool notSorted=true;
    int previous;

    for(int i =0; i<len;i++)
    {

        for(int counting=0; counting<len-1; counting++)
        {
            int previous = Arr[counting];
           // std::cout<<"previous"<<previous<<std::endl;
            int prev2 = pos[counting];
            if(Arr[counting]>Arr[counting+1])
            {
                Arr[counting] =Arr[counting+1];
                pos[counting] =pos[counting+1];
                Arr[counting+1]= previous;
                pos[counting+1]= prev2;
            }
        }
    }
}

//precondition: pass number in
//post: sets mian number as number passed
void edgecontainer::setnum(int num)
{
    number = num;
}

//precondition: call function
//postcondition: returns main number
int edgecontainer::getnum()
{
    return number;
}

//precondition: call function
//postcondition: returns total number of connections number
int edgecontainer::gettotconnect()
{
    return totalconnection;
}

//precondition: pass number to be found
//postcondition: reutrn number if found and -1 if not
int edgecontainer::getnode(int num)
{
    node * finder = head;
    while(finder!=nullptr)
    {
        if(finder->number==num)
            return num;
        finder = finder->ptr;
    }
    return -1;
}


//precondition: pass number to be placed in node
//postcondition: place number in node and push it to back of list
void edgecontainer::pushnode(int newn)
{
    node * newnode = new node;
    newnode->number= newn;
    if(head==nullptr)
    {
        head= newnode;
        tail = head;
        totalconnection+=1;
    }
    else
    {

        tail->ptr= newnode;
        tail = tail->ptr;
        totalconnection+=1;
    }
}

//precondition:call function
//postcondition:print all connections
void edgecontainer::printall(std::vector<edgecontainer> all)
{
    node * finder = head;
    std::cout<<std::endl<<number <<"follows: \n";
    if(head==nullptr)
    {
        std::cout<<"empty\n";
        return;
    }


    while(finder!=nullptr)
    {


        std::cout<<all[finder->number].getnum()<<" ";
        finder = finder->ptr;
    }
}

//precondition: pass graph vector of edge class and number
//postcondition: returns true if number is found in class and false if not
bool findingb(std::vector<edgecontainer> graph, int number)
{
    for(int i=0; i<graph.size();i++)
    {
        if(graph[i].getnum() ==number)return true;
    }
    return false;
}


//precondition: pass vector of edge classes and number
//postcondition: return position of value if found and -1 if not
int finding(std::vector<edgecontainer> graph, int number)
{
    for(int i=0; i<graph.size();i++)
    {
        if(graph[i].getnum()==number)return i;
    }
    return -1;
}

//precondition: pass vector of edges and targeted number
//postcondition: return total number of pointers to number
int inDegree(std::vector<edgecontainer> all, int number)
{
    int total=0;
    for(int i=0; i<all.size();i++)
    {
        if(all[i].getnode(number)!=-1)
            total++;
    }
    return total;
}


//precondition: pass the graph into the function
//postcondition: prints out the top ten vertices with top ten followers
void maxfollowers(std::vector<edgecontainer> all)
{
    int TOPTEN = 10; //top ten indegrees
    int total;
    std::vector<int> totfollows; //for storing the indegree values and their vertices
    std::vector<int> bundle; //for holding corresponding positions
    for(int i =0; i<all.size();i++)
    {

        total = inDegree(all,i);
        bundle.push_back(i); // associated value or vertex
        totfollows.push_back(total);
    }

    //test for correct values
    //for(int i=0;i<totfollows.size();i++)
       // std::cout<<bundle[i]<<": "<<totfollows[i]<<std::endl;

    bubble(totfollows,bundle,totfollows.size()); //sorting the vector
    //std::cout<<"size " <<totfollows.size(); //test for size of vector

   /* for(int i=0;i<totfollows.size();i++)
       std::cout<<bundle[i]<<": "<<totfollows[i]<<std::endl;*/

    //print out the first ten
    int maxsiz= bundle.size()-1;
    std::cout<<"The top ten numbers with the most followers are: \n"
            <<"-------------------------------------------\n";
    for(int i=0; i<TOPTEN;i++)
        std::cout<<all[bundle[maxsiz-i]].getnum()<<": "<<totfollows[maxsiz-i]<<" followers"<<std::endl;


}

//precondtion: pass graph in
//postcondtion: returns the median of all connections
void median(std::vector<edgecontainer> all)
{
    int total; //value for storing all connections
    std::vector<int> totfollows; //for storing the indegree values and their vertices
    std::vector<int> bundle; //for holding corresponding positions

    for(int i =0; i<all.size();i++)
    {

        total = all[i].gettotconnect(); //getting total connections
        bundle.push_back(i); // associated value or vertex
        totfollows.push_back(total);
    }

    bubble(totfollows,bundle,totfollows.size()); //sorting the vector

   /* for(int i=0;i<totfollows.size();i++)
       std::cout<<bundle[i]<<": "<<totfollows[i]<<std::endl;*/

    //find the median
    int sizeofvec = totfollows.size();
    int med;
    int pos;
    if(sizeofvec%2==0)
    {
        pos = sizeofvec/2;
        med = (totfollows[pos]+totfollows[pos+1])/2;
        std::cout<<"The median of all connections is : "<<med<< " with vertices of : "<<bundle[pos]<<", "<<bundle[pos+1]<<std::endl;
    }
    else
    {
        pos = (sizeofvec/2) + 1;
        med = totfollows[pos];
        std::cout<<"The median of all connections is : "<<med<< " at the vertex: "<<bundle[pos]<<std::endl;

    }


}
