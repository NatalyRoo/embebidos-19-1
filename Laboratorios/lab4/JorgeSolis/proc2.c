#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_PROC 8

void procesoHijo(int np);
void procesoPadre();

int main(){
	pid_t pid;
	printf("probando procesos \n");
	for(int i = 0; i< NUM_PROC; i++){
    	 pid = fork();
		 if(pid == -1){
		 	perror("No se pudo crear el proceso");
		 	exit(EXIT_FAILURE);
		 }
		 if(!pid){
		  	procesoHijo(i); 
		 }

	}
	procesoPadre();
	return 0;
}
void procesoHijo(int np){
	 printf("proseso hijo %d, ejecutando con el PID: %d \n",np, getpid()); 
	 while(1);
	 exit(np);
}
void procesoPadre(){
	int status;
	pid_t pid_Hijo;
	printf("proceso padre ejecutado: %d\n", getpid());
	for(int np = 0; np<NUM_PROC; np++){
		pid_Hijo = wait(&status);
		printf("este es el pid %d terminado con el pid: %d\n", status>>8,pid_Hijo);
	}
}
