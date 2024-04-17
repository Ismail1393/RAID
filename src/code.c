#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDisks, numChunks, numSectorsPerDisk, numQueries, query;
char* raidLevel;
// Function prototypes
void raid0(int query);
void raid1(int query);
void raid01(int query);
void raid10(int query);
void raid4(int query);
void raid5(int query);

int main() {
    char input[256]; 
    char *words[5];
    char *token;
    int i = 0;


    scanf("%255[^\n]", input); 

    token = strtok(input, " "); // Split the line into words
    while(token != NULL && i < 5) {
        words[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    // Assign the values to the variables
    raidLevel = words[0];
    numDisks = atoi(words[1]);
    numChunks = atoi(words[2]);
    numSectorsPerDisk = atoi(words[3]);
    numQueries = atoi(words[4]);

    

    // Save the query in a variable or process it as needed
    for (int j = 0; j < numQueries; j++) {
        
        scanf("%d", &query);

        if (strcmp(raidLevel, "0") == 0) {
            raid0(query);
        } else if (strcmp(raidLevel, "1") == 0) {
            raid1(query);
        } else if (strcmp(raidLevel, "10") == 0) {
            // Implement RAID 10
            raid10(query);
        } else if (strcmp(raidLevel, "4") == 0) {
            // Implement RAID 4
            raid4(query);
        } else if (strcmp(raidLevel, "5") == 0){
            // Implement RAID 5
            raid5(query);
        } else if (strcmp(raidLevel, "01") == 0){
            raid01(query);
        } else {
            printf("RAID not supported\n");
        }
    }
    return 0;
}




void raid0(int query) {
    // Implement RAID 0
    int hardDiskNumber = (query / numChunks) % numDisks ;
    // int stripeNumber = (query % numChunks) + (((query / (numChunks * numDisks)) % (numChunks * numDisks)) * numChunks);
    int stripeNumber = (query % numChunks) + ((query / (numChunks * numDisks)) * numChunks);

    printf("%d %d\n", hardDiskNumber, stripeNumber);

}

void raid1(int query) {
    int hardDiskNumber = 0;
    int stripeNumber = query;
    int hardDiskNumber2 = 1;

    printf("%d %d %d\n", hardDiskNumber, stripeNumber, hardDiskNumber2);
}

void raid01(int query) {
    // Implement RAID 01
    int hardDiskNumber = query % (numDisks/2);
    int stripeNumber = query/ (numDisks/2);
    int hardDiskNumber2 = (query % (numDisks/2)) + (numDisks/2);

    printf("%d %d %d\n", hardDiskNumber, stripeNumber, hardDiskNumber2);
}

void raid10(int query) {
    // Implement RAID 10
    int hardDiskNumber = (query % (numDisks/2)) * 2;
    int stripeNumber = query/ (numDisks/2);
    int hardDiskNumber2 = (query % (numDisks/2)) * 2 + 1;

    printf("%d %d %d\n", hardDiskNumber, stripeNumber, hardDiskNumber2);
}

void raid4(int query) {
    // Implement RAID 4
    int hardDiskNumber = query % (numDisks - 1);
    int stripeNumber = (query / (numDisks - 1)) * numChunks;
    int parity = numDisks - 1;

    printf("%d %d %d\n", hardDiskNumber, stripeNumber, parity);
}

void raid5(int query) {
    // Implement RAID 5
    int hardDiskNumber = query % numDisks;
    int stripeNumber = (query / (numDisks - 1 )) * numChunks;
    int parity = numDisks - 1 - (stripeNumber%numDisks);

    printf("%d %d %d\n", hardDiskNumber, stripeNumber, parity);
}