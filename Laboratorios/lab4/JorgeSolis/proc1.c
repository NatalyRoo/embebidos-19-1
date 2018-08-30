#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	float num1=23, num2=12, s,r;
	pid = fork();
	pid_t pid_hijo;
	int status;
	
	printf("probando procesos \n");
	if(!pid){
	       printf("proseso hijo ejecutando: %d \n",getpid()); 
		s = num1+num2;
		printf("la suma es: %f\n", s);
		exit(0);
	}
	else{
		printf("proceso padre ejecutado: %d\n", getpid());
		r = num1-num2;
		printf("la resta es: %f\n", r);
		pid_hijo =  wait(&status);
		printf("este es el pid del wait: %d\n", getpid());
	}  
	return 0;
}
