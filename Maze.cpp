#include "Maze.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
Maze::Maze(int **matrix, int height, int width)
{
    this->matrix = matrix;
    this->height = height;
    this->width = width;
}

std::vector<int *> *Maze::solve(int start[], int end[])
{
    // vector to store the coordinates and to return to the funciton caller
    std::vector<int *> *coordinates = new std::vector<int *>();
    // my matrix of coordinates for the solution
    int ***solution = (int ***)malloc(height * sizeof(int **));

    for (int i = 0; i < height; i++)
    {
        // Assign to array[i], not *array[i] (that would dereference an uninitialized pointer)
        solution[i] = (int **)malloc(width * sizeof(int *));
        for (int j = 0; j < width; j++)
        {
            solution[i][j] = (int *)malloc(3 * sizeof(int));
            solution[i][j][0] = -1;
        }
    }

    int before[2] = {0, 0};

    recursiveSolve(solution, before, start, end, 0);

    if (solution[end[0]][end[1]][0] == -1)
    {
        return coordinates;
    }
    int size = solution[end[0]][end[1]][0];
    int x = end[0];
    int y = end[1];

    for (int i = size; i >= 0; i--)
    {
        int *curr = new int[2]{x, y};
        coordinates->push_back(curr);

        int nX = solution[x][y][1];
        int nY = solution[x][y][2];
        x = nX;
        y = nY;
    }

    std::reverse(coordinates->begin(), coordinates->end());
    return coordinates;
}

void Maze::recursiveSolve(int ***solution, int before[], int start[], int finish[], int length)
{
    if (start[0] < 0 || start[0] >= width || start[1] < 0 || start[1] >= height)
    { // out of bounds
        return;
    }
    if (matrix[start[0]][start[1]] == 1)
    { // hits a wall
        return;
    }

    if (solution[start[0]][start[1]][0] == -1)
    { // new node hit
        solution[start[0]][start[1]][0] = length;
        solution[start[0]][start[1]][1] = before[0];
        solution[start[0]][start[1]][2] = before[1];
    }
    else
    {
        if (solution[start[0]][start[1]][0] < length)
        { // loops back with longer path
            return;
        }
        else
        { // loops back shorter
            solution[start[0]][start[1]][0] = length;
            solution[start[0]][start[1]][1] = before[0];
            solution[start[0]][start[1]][2] = before[1];
        }
    }
    if (start[0] == finish[0] && start[1] == finish[1])
    { // finds the end

        return;
    }
    int k[] = {start[0], start[1]};
    k[1]++;
    recursiveSolve(solution, start, k, finish, length + 1);
    k[1] -= 2;
    recursiveSolve(solution, start, k, finish, length + 1);
    k[1]++;
    k[0]++;
    recursiveSolve(solution, start, k, finish, length + 1);
    k[0] -= 2;
    recursiveSolve(solution, start, k, finish, length + 1);
    return;
}
