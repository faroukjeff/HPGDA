#include "../include/AdjList.h"
#include <algorithm>


void AdjList::add_edge( uint64_t u, uint64_t v,double wt) {
    adj[u].push_back(std::make_pair(v, wt));
}

void AdjList::populate(std::tuple<uint64_t, uint64_t, double>* e_list){
    for(uint64_t i = 0; i < e; i++)
        add_edge(std::get<0>(e_list[i]), std::get<1>(e_list[i]), std::get<2>(e_list[i]));
    //AdjList::sortEdgesByNodeId();
    finished();
}

 void AdjList::sortEdgesByNodeId() {
    for(uint64_t i = 0; i <= v; ++i)
        adj[i].sort();
} 



void AdjList::finished() {}