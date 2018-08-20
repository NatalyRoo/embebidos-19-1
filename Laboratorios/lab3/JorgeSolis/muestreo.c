#include <stdio.h>
#include <math.h>
#define MUESTRAS 512 

void generar_seno (float seno[]);
void guardar_datos(float datos[]);

int main(){
	float seno[MUESTRAS];
	
	generar_seno (seno);
	guardar_datos (seno);

	return 0;
}


void generar_seno (float seno[]){
	float f = 1000, fs = 45000;
	register int n;
	
	for (n= 0; n<MUESTRAS; n++){
		seno[n] = sinf(2*n*M_PI*f/fs);
	}
}

void guardar_datos(float datos[]){
	FILE *ap_arch;
	register int n;

	ap arch = fopen("seno.dat","w");
	if (fap_arch){
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	for(n= 0; n< MUESTRAS; n++){
		fprint(ap_arch, "%f \n", datos[n]);

	}
	fclose(ap_arch);
}
