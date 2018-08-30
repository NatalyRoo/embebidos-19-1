#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define N 32

void procesoHijo(int np);
void procesoPadre();
void memoria();
void llenarArreglo();

int main(){
	int *datos;
	datos = memoria();
	llenarArreglo(datos);
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
int memoria(){
	int *mem;
	mem = (int*)malloc(sizeof(int)*N);
	if(!mem){

		perror("error al hacer la memoria");
		error(ERROR_FAILURE);
	}
	return mem;
}

void llenarArreglo(int * datos){
	register int i;
	for(i=0;i<N;i++){
		datos[i] = rand()%255;
	}
}