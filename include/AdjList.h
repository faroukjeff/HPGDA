#ifndef ORACLE_CONTEST_ADJLIST_H
#define ORACLE_CONTEST_ADJLIST_H


#include <list>
#include <vector>
#include <functional>

// Adjacency list implementation of Graph
class AdjList{

    uint64_t v, e;
    std::list<std::pair<uint64_t, double> >* adj;


public:

    AdjList(uint64_t v, uint64_t e) : v(v), e(e){
        adj =  new std::list<std::pair<uint64_t, double> > [v + 2];
    }

    ~AdjList(){
        for(int i = 0; i <= v; ++i)
            adj[i].clear();
        delete[] adj;
    }

  std::list<std::pair<uint64_t, double>> get_neighbors(int idx){
        std::list<std::pair<uint64_t, double>> temp;
        for (auto it = adj[idx].begin(); it!=adj[idx].end(); it++)
            {
                temp.push_back(std::make_pair(it->first, it->second));
            }
        return temp;
    }


    void add_edge(uint64_t u, uint64_t v, double weight = 0);

    void finished();

    void populate(std::tuple<uint64_t, uint64_t, double>* e_list);

    void sortEdgesByNodeId();

    
};


#endif