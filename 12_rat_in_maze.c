#include <stdio.h>
#include <stdbool.h>

#define MAZE_SIZE (6) // Size of the maze 4x4 (4 rows, 4 columns, 2 for borders)
#define MAZE_BORDER (0) // Value of the maze border
#define MAZE_START (1) // Value of the maze start
#define MAZE_END (16) // Value of the maze end

void printSolution(int sol[MAZE_SIZE][MAZE_SIZE])
{
    printf("\nMaze solved!\n");
    // Loop through each row
    for(int i = 0; i < MAZE_SIZE; i++)
    {
        // Loop through each column
        for(int j = 0; j < MAZE_SIZE; j++)
        {
            // Print the value of the solution at the current row and column
            printf("%d ", sol[i][j]);
        }
        // Print a new line after each row
        printf("\n");
    }
}

bool solveMazeUtil(int maze[MAZE_SIZE][MAZE_SIZE], int x, int y, int sol[MAZE_SIZE][MAZE_SIZE])
{
    static int iteration = 1;
    printf("| %d | %d |   %d |\n", x, y, iteration);
    // Check if the current position is the destination
    if(maze[x][y] == MAZE_END)
    {
        // Mark the current position as part of the solution
        sol[x][y] = MAZE_END;
        return true;
    }

    // Check if the current position is valid
    if(x > 0 &&
       x < MAZE_SIZE &&
       y > 0 &&
       y < MAZE_SIZE &&
       maze[x][y] != 0  &&
       maze[x][y] == iteration
      )
    {
        iteration++;
        // Mark the current position as part of the solution
        sol[x][y] = 1;
        if (x > 1 && y > 1)
        {
            if(solveMazeUtil(maze, x-1, y, sol) ||
               solveMazeUtil(maze, x, y-1, sol) ||
               solveMazeUtil(maze, x+1, y, sol) ||
               solveMazeUtil(maze, x, y+1, sol) ||
               solveMazeUtil(maze, x+1, y+1, sol) ||
               solveMazeUtil(maze, x-1, y-1, sol)
              )
            {
                return true;
            }
        }
        else if (y > 1)
        {
          if(
           solveMazeUtil(maze, x, y-1, sol) ||
           solveMazeUtil(maze, x+1, y, sol) ||
           solveMazeUtil(maze, x, y+1, sol) ||
           solveMazeUtil(maze, x+1, y+1, sol)
            )
            {
                return true;
            }
        }
        else if (x > 1)
        {
          if(
           solveMazeUtil(maze, x-1, y, sol) ||
           solveMazeUtil(maze, x, y+1, sol) ||
           solveMazeUtil(maze, x+1, y, sol) ||
           solveMazeUtil(maze, x+1, y+1, sol)
            )
            {
                return true;
            }
        }
        else if (x == 1 && y == 1)
        {
          if(
           solveMazeUtil(maze, x, y+1, sol) ||
           solveMazeUtil(maze, x+1, y, sol) ||
           solveMazeUtil(maze, x+1, y+1, sol)
            )
            {
                return true;
            }
        }
        
        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(int maze[MAZE_SIZE][MAZE_SIZE])
{
    // Declare a 2D array to store the solution
    int sol[MAZE_SIZE][MAZE_SIZE];
    int start_location_x;
    int start_location_y;

    // Initialize the solution array to 0
    for(int i = 0; i < MAZE_SIZE; i++)
    {
        for(int j = 0; j < MAZE_SIZE; j++)
        {
            if(maze[i][j] == MAZE_START)
            {
                start_location_x = i;
                start_location_y = j;
            }

            sol[i][j] = 0;
        }
    }

    // If the maze is solved, then return true.
    printf("---- Trial Steps---- \n");
    printf("__X____Y___Num__ \n");
    if(!solveMazeUtil(maze, start_location_x, start_location_y, sol))
    {
        printf("Solution doesn't exist");
        return false;
    }

    // Print the solution
    printSolution(sol);
    return true;
}

int main()
{
     int maze[MAZE_SIZE][MAZE_SIZE] = { { 0, 0, 0, 0, 0, 0 },
                                        { 0, 9, 11, 12, 16, 0 },
                                        { 0, 8, 10, 13, 15, 0 },
                                        { 0, 7, 5, 2, 14, 0 },
                                        { 0, 6, 4, 3, 1, 0 },
                                        { 0, 0, 0, 0, 0, 0 }
                                      };
    return solveMaze(maze);
}