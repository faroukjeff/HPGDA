#include "../include/AdjNew.h"
#include <algorithm>

//push edge to the source vector
void AdjNew::add_edge( uint64_t u, uint64_t v,double wt) {
    adj[u].push_back(std::make_pair(v, wt));
}
//loops over all edges and uses add_edge function
void AdjNew::populate(std::tuple<uint64_t, uint64_t, double>* e_list){
    for(uint64_t i = 0; i < e; i++)
        add_edge(std::get<0>(e_list[i]), std::get<1>(e_list[i]), std::get<2>(e_list[i]));
    //AdjNew::sortEdgesByNodeId(); //sorting disabled as it only slighlty improves DFS/BFS but heavily impacts populate time
    finished();
}
//if enabled, sorts vectors after population to improve BFS/DFS times
void AdjNew::sortEdgesByNodeId() {
   for(uint64_t i = 0; i <= v; ++i)
        sort(adj[i].begin(),adj[i].end());
}



void AdjNew::finished() {}