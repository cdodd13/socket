#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080

int findPrime(int previous);

int main(int argc, char const *argv[]) {
	struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    int buffer[1024] = {0};
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "10.0.0.10", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection failed \n");
        return -1;
    }

    int maxIndex = 10;
    int txBuffer[10];
    for(int i = 0; i < maxIndex; i++) {
        txBuffer[i] = i;
        printf("%i\n", i);
    }
//    int txVal;
//    for(int j = 0; j < maxIndex; j++) {
//        txVal = txBuffer[j];
//        printf("%i\n", txVal);
//        printf("%i\n", txBuffer[j]);
//    }

    send(sock, txBuffer, maxIndex, 0);
    printf("sent txBuffer\n");
    valread = read(sock, buffer, 1024);
    int rxVal = *buffer;
    printf("%i\n", rxVal);

/*    int txVal = 1;
    int rxVal = 1;
    int count = 1;
    while(count <= 100) {
        txVal = findPrime(rxVal);
        send(sock, &txVal, sizeof(txVal), 0);
        printf("sent: %i\n", txVal);
        valread = read(sock, buffer, 1024);
        rxVal = *buffer;
        count += 1;
    }
*/
//    send(sock, hello, strlen(hello), 0);
//    printf("Hello message sent\n");
//    valread = read(sock, buffer, 1024);
//    printf("%s\n", buffer);

    return 0;
}

int findPrime(int previous) {
    int flag = 1;
    int n = previous;
    while(flag) {
        n += 1;
        flag = 0;
        for(int i = 2; i < n; i++) {
            if(n % i == 0) {
                flag = 1;
                break;
            }
        }
    }
    return n;
}
