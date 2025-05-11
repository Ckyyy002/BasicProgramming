#include <stdio.h>

int main() {
    int votes[5][4] = {
        {192, 48, 206, 37},
        {147, 90, 312, 21},
        {186, 12, 121, 38},
        {114, 21, 408, 39},
        {267, 13, 382, 29}
    };
    int totalVotes[4] = {0}, overallVotes = 0;

    printf("Precinct\tA\tB\tC\tD\n");
    for(int i = 0; i < 5; i++){
        printf("%d\t\t", i + 1);
        for(int j = 0; j < 4; j++){
            printf("%d\t", votes[i][j]);
            totalVotes[j] += votes[i][j];
        }
        printf("\n");
    }

    for(int i = 0; i < 4; i++){
        overallVotes += totalVotes[i];
    }

    printf("\nTotal votes for each candidate:\n");
    for(int i = 0; i < 4; i++){
        printf("Candidate %c: %d (%.2f%%)\n", 'A' + i, totalVotes[i], (totalVotes[i] * 100.0) / overallVotes);
    }
    
    int winnerIndex = -1;
    for(int i = 0; i < 4; i++){
        if((totalVotes[i] * 100.0) / overallVotes > 50.0){
            winnerIndex = i;
            break;
        }
    }

    if(winnerIndex != -1){
        printf("\nCandidate %c wins with more than 50%% of the total votes!\n", 'A' + winnerIndex);
    }
    else{
        int max1 = -1, max2 = -1;
        for(int i = 0; i < 4; i++){
            if (max1 == -1 || totalVotes[i] > totalVotes[max1]){
                max2 = max1;
                max1 = i;
            } 
            else if(max2 == -1 || totalVotes[i] > totalVotes[max2]){
                max2 = i;
            }
        }
        printf("\nNo candidate received more than 50%% of the votes.\nA runoff is required between Candidate %c and Candidate %c.\n", 'A' + max1, 'A' + max2);
    }

    return 0;
}
