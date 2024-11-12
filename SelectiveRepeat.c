#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

int main() {
    int frames[TOTAL_FRAMES];
    int ack[TOTAL_FRAMES] = {0};  // 0 for unacknowledged, 1 for acknowledged
    int i, j;

    // Initialize frames
    for (i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = i;
    }

    srand(time(NULL));

    printf("Selective Repeat Protocol:\n");

    for (i = 0; i < TOTAL_FRAMES; i++) {
        // Send frame i
        printf("\nSending frame %d\n", frames[i]);

        // Simulate receiver acknowledging the frame
        ack[i] = 1;  // Assume all frames are successfully acknowledged initially
        printf("Acknowledging frame %d\n", frames[i]);

        // Simulate random loss of frames (acknowledgment failure)
        if (rand() % 2 == 0) {  // Simulate random frame loss (50% chance)
            ack[i] = 0;  // Frame lost, no acknowledgment
            printf("Frame %d lost, needs retransmission\n", frames[i]);
        }

        // If a frame is lost (ack[i] == 0), retransmit it
        if (ack[i] == 0) {
            printf("Retransmitting frame %d\n", frames[i]);
            ack[i] = 1;  // Assume it is successfully acknowledged this time
            printf("Acknowledging frame %d\n", frames[i]);
        }
    }

    printf("\nTransmission complete.\n");

    return 0;
}
