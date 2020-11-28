#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include<bits/stdc++.h>
#include "node.h"

using namespace std;

int main()
{
    //initialization
    ifstream in;
    int totalvertices=0;
    string firstwords;
    int numbers;
    int fnum;
    int snum;
    int fpos;
    int spos;

    vector<edgecontainer> graph; // the adj list

    in.open("github-graph_V1.0.txt"); //opening file

    //taking out string
    getline(in, firstwords,'\n');


    //adding numbers to the list
    while(!in.eof())
    {
        in>>numbers;
        if(!findingb(graph, numbers))
        {
            edgecontainer newnod;
            newnod.setnum(numbers);
            graph.push_back(newnod);
        }
    }
    in.close();

   /* for(int i =0; i<graph.size();i++)
    cout<<graph[i].getnum()<<" " ;*/

    cout<<"size: "<<graph.size()<<endl;


    //opening it up again
    in.open("github-graph_V1.0.txt");
    getline(in, firstwords,'\n');


    while(!in.eof())
    {
        in>>fnum;
        in>>snum;
        fpos =finding(graph, fnum);
        spos= finding(graph, snum);
        if(graph[fpos].getnode(snum)==-1)
        {
            graph[fpos].pushnode(spos);
        }
    }
    in.close();
    //testing
   /* for(int i=0; i<graph.size();i++)
    graph[i].printall(graph);
    */



    //maxfollowers(graph);
    median(graph);









    return 0;
}
