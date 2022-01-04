#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#define READDATA 0
#define WROTEDATA 1

void main() {
	key_t key = (key_t)69;
	int shmid, semid, i;
	int *pshm = NULL;
	struct sembuf sb;
	// key = ftok("random.c", 'M');
	if((shmid = shmget(key, sizeof(int), 0777|IPC_CREAT)) < 0){
		perror("shmget");
		exit(1);
	}
	if((semid = semget(key, 2, 0777|IPC_CREAT)) < 0) {
		perror("semget");
		exit(1);
	}
	if((pshm = (int *)shmat(shmid, NULL, 0)) == NULL) {
		perror("shmat");
		exit(1);
	}
	for(i = 0; i < 5; i++) {
		
		sb.sem_num = READDATA;
		sb.sem_op = 1;
		sb.sem_flg = SEM_UNDO;
		semop(semid, &sb, 1);
		
		sb.sem_num = WROTEDATA;
		sb.sem_op = -1;
		sb.sem_flg = SEM_UNDO;
		semop(semid, &sb, 1);
		
		printf("Reader read: %d\n", *(pshm));
		
	}
	printf("Read all data from shm\n");
	shmdt(pshm);
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, READDATA, IPC_RMID, NULL);
	semctl(semid, WROTEDATA, IPC_RMID, NULL);
}
