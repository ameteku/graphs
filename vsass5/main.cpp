#include <iostream>
#include <fstream>
#include <vector>
#include<bits/stdc++.h>
#include "node.h"


int main()
{
    //initialization
    std::ifstream in;
    int optionselected;
    std::vector<edgecontainer> graph; // the adj list

    loadgraph(in,graph); //adding values from file to the graph

    //performing the rest of the actions based on user input
    while(true)
    {
        optionselected= option(); //asking user for option
        if(optionselected==0)
            return 0;
        decision(optionselected,graph); //perform action
        std::cout<<std::endl;
    }



    return 0;
}
