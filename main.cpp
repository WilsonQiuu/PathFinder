#include "Maze.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("mazeInput.txt");

    int length, width;
    cin >> length >> width;

    int **matrix = (int **)calloc(length, sizeof(int *));
    for (int i = 0; i < length; ++i)
    {
        matrix[i] = (int *)calloc(width, sizeof(int));
        for (int j = 0; j < width; ++j)
        {
            cin >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << "" << endl;
    }
    int start[2];
    int end[2];
    cin >> start[1] >> start[0] ;
    cin >> end[1] >> end[0] ;
    cout << "Start: " << start[0] << " " << start[1] << endl;
    cout << "End: " << end[0] << " " << end[1] << endl;

    cout << endl;
    Maze *k = new Maze(matrix, length, width);
    vector<int *> *coordinates = k->solve(start, end);
    for (int i = 0; i < coordinates->size(); i++)
    {
        cout << "{" << coordinates->at(i)[1] << " " << coordinates->at(i)[0] << "} ";
    }

    return 0;
}