#ifndef ORACLE_CONTEST_ADJNEW_H
#define ORACLE_CONTEST_ADJNEW_H


#include <list>
#include <vector>
#include <functional>
#include <algorithm>

// Adjacency list implementation of Graph
class AdjNew{

    uint64_t v, e;
    std::vector<std::pair<uint64_t, double> >* adj;


public:

    AdjNew(uint64_t v, uint64_t e) : v(v), e(e){
        adj =  new std::vector<std::pair<uint64_t, double> > [v + 2];
    }

    ~AdjNew(){
        for(int i = 0; i <= v; ++i)
            adj[i].clear();
        delete[] adj;
    }
//since we use the same format as requested by graphalgorithm.h, all the neighbors are already in adj[vertex]
  std::vector<std::pair<uint64_t, double>> get_neighbors(int idx){
        return adj[idx];
    }


    void add_edge(uint64_t u, uint64_t v, double weight = 0);

    void finished();

    void populate(std::tuple<uint64_t, uint64_t, double>* e_list);

    void sortEdgesByNodeId();

    
};


#endif //ORACLE_CONTEST_ADJNEW_H