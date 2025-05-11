#include <stdio.h>
#include <stdbool.h>

#define SIZE 8
#define MAX_PATH_LENGTH 64

bool isValid(char maze[SIZE][SIZE], int x, int y, bool visited[SIZE][SIZE]){
    return (x >= 0 && x < SIZE &&  y >= 0 && y < SIZE && maze[x][y] == ' ' && !visited[x][y]);
}

bool solveMaze(char maze[SIZE][SIZE], int x, int y, bool visited[SIZE][SIZE], int pathX[], int pathY[], int* pathLength){
    if(x == 7 && y == 7){
        pathX[*pathLength] = x;
        pathY[*pathLength] = y;
        (*pathLength)++;
        return true;
    }

    if(!isValid(maze, x, y, visited)){
        return false;
    }

    visited[x][y] = true;

    pathX[*pathLength] = x;
    pathY[*pathLength] = y;
    (*pathLength)++;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(solveMaze(maze, newX, newY, visited, pathX, pathY, pathLength)){
            return true;
        }
    }

    (*pathLength)--;
    visited[x][y] = false;
    return false;
}

void findPath(char maze[SIZE][SIZE]) {
    if (maze[0][1] == 'X') {
        printf("Error: Starting position (0,1) is blocked!\n");
        return;
    }

    if (maze[7][7] == 'X') {
        printf("Error: End position (7,7) is blocked!\n");
        return;
    }

    int pathX[MAX_PATH_LENGTH] = {0};
    int pathY[MAX_PATH_LENGTH] = {0};
    int pathLength = 0;
    bool visited[SIZE][SIZE] = {false};

    if(solveMaze(maze, 0, 1, visited, pathX, pathY, &pathLength)){
        char mazeCopy[SIZE][SIZE];
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                mazeCopy[i][j] = maze[i][j];
            }
        }

        for(int i = 0; i < pathLength; i++){
            mazeCopy[pathX[i]][pathY[i]] = '*';
        }

        printf("\nMaze with path (* represents the path):\n");
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                printf("%c", mazeCopy[i][j]);
            }
            printf("\n");
        }

        printf("\nPath coordinates:\n");
        for(int i = 0; i < pathLength; i++){
            printf("(%d,%d) ", pathX[i], pathY[i]);
        }
        printf("\n");
    } 
    else{
        printf("No path exists through the maze!\n");
    }
}

int main(){
    char maze[SIZE][SIZE];
    printf("Enter the maze (8x8 grid using 'X' for walls and ' ' for paths):\n");
    printf("Enter row by row, using X for walls and space for paths.\n");
    printf("Example row: X XXX XX\n");

    bool inputValid = true;

    for(int i = 0; i < SIZE; i++) {
        char line[SIZE * 2]; 
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error reading input!\n");
            return 1;
        }

        int charCount = 0;
        for(int j = 0; j < SIZE * 2 && line[j] != '\n' && line[j] != '\0'; j++){
            if(line[j] == 'X' || line[j] == ' '){
                if(charCount < SIZE){
                    maze[i][charCount] = line[j];
                    charCount++;
                }
            }
        }

        if(charCount != SIZE){
            printf("Error: Row %d has incorrect number of characters!\n", i + 1);
            printf("Each row must contain exactly 8 characters (X or space)\n");
            inputValid = false;
            break;
        }
    }

    if(!inputValid){
        return 1;
    }

    printf("\nInput maze:\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    findPath(maze);
    return 0;
}
