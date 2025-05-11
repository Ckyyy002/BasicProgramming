#include <stdio.h>

#define MAX_SIZE 100
int rows, cols;

int is_valid(int x, int y){
    return (x >= 0 && x < cols && y >= 0 && y < rows);
}

void mark_blob(int grid[MAX_SIZE][MAX_SIZE], int x, int y){
    if(!is_valid(x, y) || grid[y][x] != 1){
        return;
    }

    grid[y][x] = -1;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            mark_blob(grid, x+j, y+i);
        }
    }
}

int count_total_blobs(int grid[MAX_SIZE][MAX_SIZE]) {
    int blob_count = 0;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 1){
                blob_count++;
                mark_blob(grid, j, i);
            }
        }
    }
    
    return blob_count;
}

int main() {
    int grid[MAX_SIZE][MAX_SIZE];
    
    do{
        printf("Enter number of rows (1-%d): ", MAX_SIZE);
        scanf("%d", &rows);
        printf("Enter number of columns (1-%d): ", MAX_SIZE);
        scanf("%d", &cols);
        
        if(rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE){
            printf("Invalid dimensions! Please try again.\n");
        }

    } while(rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE);

    printf("\nEnter the grid values (0 for empty, 1 for filled):\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            do{
                printf("Enter value for position (%d,%d): ", j, i);
                scanf("%d", &grid[i][j]);
                
                if(grid[i][j] != 0 && grid[i][j] != 1) {
                    printf("Invalid input! Please enter 0 or 1.\n");
                }

            } while(grid[i][j] != 0 && grid[i][j] != 1);
        }
    }

    printf("\nInput Grid:\n");

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int num_blobs = count_total_blobs(grid);
    printf("\nTotal number of separate blobs: %d\n", num_blobs);

    return 0;
}
