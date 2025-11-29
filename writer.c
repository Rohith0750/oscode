#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, BUFFER_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *str = (char *)shmat(shmid, NULL, 0);
    if (str == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    printf("Write Data: ");
    fgets(str, BUFFER_SIZE, stdin);

    printf("Data written in memory: %s\n", str);

    if (shmdt(str) == -1) {
        perror("shmdt");
        exit(1);
    }
  -------------------------------------------------------------------------
    #include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, BUFFER_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *str = (char *)shmat(shmid, NULL, 0);
    if (str == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    printf("Data read from memory: %s\n", str);

    if (shmdt(str) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}


    return 0;
}
