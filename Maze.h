#include <iostream>
#include <fstream>
#include <vector>
#include <utility>


class Maze {
public:
    Maze(int** matrix,int length,int width); // default constructor

    // solves the maze and returns it in an array of coordinates
    std::vector<int*>* solve(int start[],int end[]);
    

private:
    void recursiveSolve(int*** solution, int before[],int start[],int finish[],int length);

    int** matrix; // the maze

    int height; // bounds of the maze
    int width;



};


    
    