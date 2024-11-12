#include <stdio.h>

int main() {
    int bucket_size, outgoing_rate, n, incoming, storage = 0;
    int i;
   
    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);
   
    printf("Enter outgoing rate: ");
    scanf("%d", &outgoing_rate);
   
    printf("Enter the number of input packets: ");
    scanf("%d", &n);
   
    for (i = 1; i <= n; i++) {
        printf("Enter incoming packet size at time %d: ", i);
        scanf("%d", &incoming);
       
        if (incoming <= (bucket_size - storage)) {
            storage += incoming;
            printf("Packet of size %d accepted.", incoming);
        } else {
            printf("Packet of size %d discarded (Bucket overflow).", incoming);
        }
       
        if (storage > outgoing_rate) {
            printf("Sent out %d units of data.", outgoing_rate);
            storage -= outgoing_rate;
        } else {
            printf("Sent out %d units of data.", storage);
            storage = 0;
        }
       
        printf("Bucket status: %d units remaining.", storage);
    }
   
    while (storage > 0) {
        if (storage > outgoing_rate) {
            printf("Sent out %d units of data.", outgoing_rate);
            storage -= outgoing_rate;
        } else {
            printf("Sent out %d units of data", storage);
            storage = 0;
        }
        printf("Bucket status: %d units remaining.", storage);
    }

    return 0;
}
