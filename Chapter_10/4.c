#include <stdio.h>
#include <string.h>

typedef struct {
    char comb[10];
    int mpn, lb, ub;
} MPN;

int main() {
    int n;
    printf("Enter the number of entries in the MPN table: ");
    scanf("%d", &n);
    
    MPN table[n];

    for(int i = 0; i < n; i++){
        printf("Entry %d:\n  Combination triplet: ", i + 1);
        scanf("%s", table[i].comb);
        printf("  MPN, Lower bound, Upper bound: ");
        scanf("%d %d %d", &table[i].mpn, &table[i].lb, &table[i].ub);
    }

    char query[10];
    while(printf("\nEnter triplet (or 'exit'): "), scanf("%s", query), strcmp(query, "exit")){
        int found = 0;

        for(int i = 0; i < n && !found; i++){
            if(!strcmp(table[i].comb, query)){
                printf("For %s, MPN = %d; 95%% of samples contain between %d and %d bacteria/ml.\n",
                       query, table[i].mpn, table[i].lb, table[i].ub);
                found = 1;
            }
        }

        if(!found){
            printf("Triplet '%s' not found.\n", query);
        }
    }
    
    printf("Exiting the program.\n");
    return 0;
}
