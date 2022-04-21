#include "Maze.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    ifstream cin("mazeTest.txt");
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int length, width;
        cin >> length >> width;
        // cout << length << width << endl;
        int **matrix = (int **)calloc(length, sizeof(int *));
        for (int i = 0; i < length; ++i)
        {
            matrix[i] = (int *)calloc(width, sizeof(int));
            for (int j = 0; j < width; ++j)
            {
                cin >> matrix[i][j];
                //cout << matrix[i][j] << " ";
            }
            //cout << "" << endl;
        }
        int start[2];
        int end[2];
        cin >> start[1] >> start[0];
        cin >> end[1] >> end[0];

        cout << endl;
        Maze *k = new Maze(matrix, length, width);
        vector<int *> *coordinates = k->solve(start, end);
        int expectedsize;
        cin >> expectedsize;
        int x, y;
        bool failed = false;
        if (expectedsize != coordinates->size())
        {
            failed = true;
        }
        for (int i = 0; i < expectedsize; i++)
        {
            cin >> x >> y;

            if (x != coordinates->at(i)[1] || y != coordinates->at(i)[0])
            {
                cout << "Test Failed" << endl;
                failed = true;
                break;
            }
        }

        if (!failed)
        {
            cout << "Test Successful" << endl;
        }
    }

    return 0;
}
