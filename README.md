# Data Structure Contest - Spring 2022
In the Data Structure track of the contest you will have the chance to play with different **sparse graph representations** and explore their runtime performance. 

## Description
The goal of this challenge consists in implementing a graph data structure to store a graph, 
and an algorithm to efficiently populate your data structure with real graph data.

## Dataset
You will work on datasets provided by the [Linked Data Benchmark Council (LDBC)](https://ldbcouncil.org/).
In particular, you will work on graphs from the [LDBC Graphanalytics Benchmark suite](https://ldbcouncil.org/benchmarks/graphalytics/).
Some example graphs are already available in the ```data``` subfolder.
The data format is described in the [LDBC Graphanalytics Benchmark Specification](https://arxiv.org/pdf/2011.15028.pdf).
The data loader is already provided in  ```include/utils.h```, and you can use it as it is, unless you want to make it faster (but it's just a side quest)!

### Evaluation Graphs
The graphs employed for the evaluation are available in the ``` eval_graphs.tar.gz``` archive on [Google Drive](https://drive.google.com/file/d/15vjYvcNAt7FODQqu4kma3X8jXnxTC6J1/view?usp=sharing).
You can download and extract the archive by running (in this folder):
```
wget -O eval_graphs.tar.gz "https://drive.google.com/uc?export=download&id=15vjYvcNAt7FODQqu4kma3X8jXnxTC6J1&confirm=yes" && tar -xzvf eval_graphs.tar.gz
```

In the ```eval_graphs``` folder you will find 3 real graphs from the LDBC Graphanalytics Benchmark suite:

| Graph | # Nodes | # Edges | Directed |
|---|---|---|---|
| wiki-Talk | 2,394,385 | 5,021,410 | True |
| cit-Patents | 3,774,768 | 16,518,947 | True |
| dota-league | 61,170 | 50,870,313 | False |

For each graph, there is a folder containing 3 files:
- *graph_name*`.v`: containing the set of nodes;
- *graph_name*`.e`: containing the set of edges;
- *graph_name*`.properties`: summarizing the properties of the graph. It also provides the source vertex chosen by LDBC to ease the reproducibility and comparability of different implementations. In your experiments, you can use other source vertices, but we recommend including in your sets of tested vertices the ones reported in the `.properties` file.   

## Challenge
The contest consists in implementing an graph data structure that is efficient both in terms of memory usage and runtime performance.
You can use every graph representation you want (e.g. AdjacencyList, CSR, COO), **except the Adjacency Matrix**.
Your implementation must interface with the ```GraphAlgorithm``` class, by exposing the following public methods:
* populate 
* get_neighbors
* finished

You can implement any other methods you may need.
An example implementation is provided in ```AdjacencyList.h```  and ```AdjacencyList.cpp```. 
You must update ```src/main.cpp``` to use your data structure during the execution.
You are not required to update the ```GraphAlgorithm``` class (if you do, tell us how you changed it and why).

```src/main.cpp``` takes five positional arguments:
1. *path to graph* (required);
1. *source vertex* for BFS and DFS (required);
1. *number of iterations* of graph population, BFS and DFS (required);
1. `-U` if the graph is undirected (default is directed);
1. `-d` for debugging mode (default is no debugging)

To build the example, just run ```make``` in this folder.

To run the example (3 iterations) on the ```example_directed``` graph, with source vertex 2:
``` 
bin/exe data/example_directed 2 3 -d
```
To run the example (3 iterations) on the ```example_undirected``` graph, with source vertex 2:
``` 
bin/exe data/example_undirected 2 3 -U -d
```
To run the example (1 iteration) on the ```wiki-Talk``` graph (from the Evaluation Graphs suite), with source vertex 2:
``` 
bin/exe eval_graphs/wiki-Talk/wiki-Talk 2 1 -d
```

To run an evaluation-like script:
``` 
bash run.sh
```

## Evaluation
Your solution will be evaluated w.r.t. the following metrics:
* graph population time
* graph size in memory (that's why you don't want to use the Adjacency Matrix!)
* execution time of the BFS and DFS algorithms implemented in ```GraphAlgorithm```.

The ```src/main.cpp``` code already measures all this values. 
If not in debug mode, the code prints (for each iteration) a .CSV line containing the following values:

| Source vertex | Populate Time (ms) | Memory Usage (MB) | BFS Time (ms) | BFS Sum | DFS Time (ms) | DFS Sum |
|---|---|---|---|---|---|---|
