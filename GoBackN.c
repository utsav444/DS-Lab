#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

int main() {
    int frames[TOTAL_FRAMES];
    int ack_received = 0;
    int start = 0;
    int end = WINDOW_SIZE - 1;

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = i + 1;
    }

    srand(time(NULL));

    while (ack_received < TOTAL_FRAMES) {
        for (int i = start; i <= end && i < TOTAL_FRAMES; i++) {
            printf("Frame %d sent.\n", frames[i]);
        }

        for (int i = start; i <= end && i < TOTAL_FRAMES; i++) {

            if (rand() % TOTAL_FRAMES < 1) {
                printf("Frame %d is faulty. No acknowledgment received.\n", frames[i]);
                break;
            }
            printf("Acknowledgment for frame received.\n");
            ack_received++;
        }

        start = ack_received;
        end = start + WINDOW_SIZE - 1;


        if(end >= TOTAL_FRAMES) {
            end = TOTAL_FRAMES - 1;
        }

        printf("Sliding window from position %d to %d\n", start + 1, end + 1);
    }

    printf("All frames are sent and then acknowledged successfully.\n");
    return 0;
}
