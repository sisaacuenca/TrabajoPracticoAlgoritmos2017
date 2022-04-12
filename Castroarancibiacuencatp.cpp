#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>  

#define tacam 17,60

int muestra_menu(int);
float depo_minimo(float);
float depo_maximo(float);

int main() {
	
	int foper = 0;
	int conta=0, fusua, opera, opera1, opera2, opera3, opera4, opera5, opera6, cdepp=0, cextp=0;
	float depop, extrap, saldop1, saldop2, saldop3, extrap1, extrap2, extrap3, convus, depmin, depmax, acud;
	bool ingreso = false;
	char usua[6], passw[7], ing[3], reti[3];
	char confir;
	
	/* inicio de programa */
    printf("\t\t\tINICIO DEL PROGRAMA \n\n\n");
    printf("\tDesea realizar una operacion? (si/no): \t");
    fflush(stdin);
    scanf("%s",ing);
    fflush(stdin);
    system("cls");
    while (strcmp(ing, "si")==0) {
    	/* preguntas de ingreso de datos */
		do {
			system("cls");
			printf("\t\t\tBienvenido al Servicio de Cajero automatico \n\n\n");
			printf("\t\tINGRESO DE USUARIO \n");
			printf("\t\t------------------ \n");
			printf("\t\tIngrese su nombre de Usuario: \n\n\t\t");
	    	fflush(stdin);
    		gets(usua);	
    		printf("\t\t\tIngrese su password: \n\t\t");
	    	fflush(stdin);
    		gets(passw);
		
			if(((((strcmp(usua, "USUA1")==0)&&(strcmp(passw, "aaaaaa")==0))||((strcmp(usua, "USUA2")==0)&&(strcmp(passw, "bbbbbb")==0))))||((strcmp(usua, "USUA3")==0)&&(strcmp(passw, "cccccc")==0))) {
				ingreso = 1;		
	    	}
	   		else
				{
					printf("\t\tEl usuario y/o password son incorrectos\n\t\t");
					system("pause");
					conta++;
				}	
		system("cls");
		
		} while ((ingreso == 0) && (conta <3));
		
		
	
		if(ingreso == 1) { 
			printf("\n\t\tBienvenido al sistema\n\t\t");
			opera = muestra_menu(foper);
	
		}
		else {
			printf("\t\tUd. no ha podido ingresar al sistema. Adios");
		
		}
		
	
		if((strcmp(usua, "USUA1")==0)&&((opera==1)||(opera==2)||(opera==3)||(opera==4))) 
		{
			if(opera == 1) {
				printf("\t\tIngrese el Monto a depositar:  \n\t\t");
				fflush(stdin);
    			scanf("%f",&depop);
    			saldop1 = saldop1+depop;
    			depmin = depo_minimo(depop);
    			cdepp++;
    			printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop1);	
			}
			if(opera == 2) {
				printf("\t\tIngrese el Monto a extraer (en Pesos Argentinos):  \n\t\t");
				fflush(stdin);
    			scanf("%f", &extrap);
    			if(extrap<saldop1) {
    				printf("\tDesea retirar el monto en dolares? (si/no): \t");
    				fflush(stdin);
    				scanf("%s",reti);
    				if(strcmp(reti, "si")==0) {
    					convus=(extrap/tacam);
						printf("el monto a retirar en dolar es: %f. Desea continuar con la operacion? (s/n)", convus);
						scanf("%c", confir);
						if(confir == 's')
						{
						saldop1=saldop1-extrap;
    					acud=acud+convus;
    					}
							
    					printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop1);
    					printf("\t\tSaldo en dolares a retirar: %f \n\t\t", convus);
    				}else 
					{
    					saldop1=saldop1-extrap;
    					cextp++;
    					printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop1);
    					printf("\t\tSaldo en pesos a retirar: %f \n\t\t", extrap);
    				}
    					
    				}
    				else{
    					printf("\t\tSaldo insuficiente. Operacion terminada.\n\t\t");
    				
    				}	
				}
				else
						depmax = depo_maximo(depop);
				if(opera == 3 ) {
					printf("\tEl Saldo en pesos es: %f\n\t\n", saldop1);
				}
				if(opera == 4) {
					printf("Gracias por operar con nuestros servicios");
				}
			}
		if(strcmp(usua, "USUA2")==0) {
	
				if(opera == 1) {
					printf("\t\tIngrese el Monto a depositar:  \n\t\t");
					fflush(stdin);
    				scanf("%f",&depop);
    				saldop2=saldop2+depop;
    				depmin = depo_minimo(depop);
    				cdepp++;
    				printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop2);	
				}
				if(opera == 2) {
					printf("\t\tIngrese el Monto a extraer:  \n\t\t");
					fflush(stdin);
    				scanf("%f",&extrap);
    				if(extrap<saldop2) {
    					printf("\tDesea retirar el monto en dolares? (si/no): \t");
    					fflush(stdin);
    					scanf("%s",reti);
    					if(strcmp(reti, "si")==0) {
    						convus=(extrap/tacam);
							saldop2=saldop2-extrap;
    						acud=acud+convus;
    						printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop2);
    						printf("\t\tSaldo en dolares a retirar: %f \n\t\t", convus);
    					}else 
							{
    							saldop2=saldop2-extrap;
    							printf("\t\tNuevo saldo en pesos: %f.2 \n\t\t", saldop2);
    							printf("\t\tSaldo en pesos a retirar: %f.2i\n\t\t", extrap);
    						}
    					cextp++;	
    				}
    				else{
    					depmax = depo_maximo(depop);
    				}	
				}
				else
					printf("\t\tSaldo insuficiente. Operacion terminada.\n\t\t");
				if(opera == 3 ) {
					printf("\tEl Saldo en pesos es: %f\n\t\n", saldop2);
				}
				if(opera == 4) {
					printf("Gracias por operar con nuestros servicios");
				}
			}
			if(strcmp(usua, "USUA3")==0) {
	
				if(opera == 1) {
					printf("\t\tIngrese el Monto a depositar:  \n\t\t");
					fflush(stdin);
    				scanf("%f",&depop);
    				saldop3=saldop3+depop;
    				depmin = depo_minimo(depop);
    				cdepp++;
    				printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop3);	
				}
				if(opera == 2) {
					printf("\t\tIngrese el Monto a extraer:  \n\t\t");
					fflush(stdin);
    				scanf("%f",&extrap);
    				if(extrap<saldop3) {
    					printf("\tDesea retirar el monto en dolares? (si/no): \t");
    					fflush(stdin);
    					scanf("%s",reti);
    					if(strcmp(reti, "si")==0) {
    						saldop3=saldop3-extrap;
    						convus=(extrap/tacam);
    						acud=acud+convus;
    						printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop3);
    						printf("\t\tSaldo en dolares a retirar: %f \n\t\t", convus);
    					}else 
							{
    							saldop3=saldop3-extrap;
    							printf("\t\tNuevo saldo en pesos: %f \n\t\t", saldop3);
    							printf("\t\tSaldo en pesos a retirar: %f \n\t\t", extrap);
    						}
    					cextp++;	
    				}
    				else{
    					depmax = depo_maximo(depop);
    				}	
				}
				else
					printf("\t\tSaldo insuficiente. Operacion terminada.\n\t\t");
				if(opera == 3 ) {
					printf("\tEl Saldo en pesos es: %f\n\t\n", saldop3);
				}
				if(opera == 4) {
					printf("Gracias por operar con nuestros servicios");
				}
			}
		printf("\tDesea realizar otra operacion? (si/no): \t");
    	fflush(stdin);
    	gets(ing);
    	fflush(stdin);
    	system("cls");			
	}
	printf("\t\tPresentacion de resultados solicitados \n");
	printf("\t\tTotal de operaciones de deposito: %i", cdepp);
	printf("\t\tTotal de operaciones de extraccion: %i", cextp);
	printf("\t\tTotal de venta de dolares: %f", acud);
	printf("\t\tMinimo valor de deposito: %f", depmin);
	printf("\t\tMaximo valor de deposito: %f", depmax);	
}

int muestra_menu(int foper) {
	
    /* permite limitar las opciones y evitar salir en caso de eleccion erronea */
    while((foper<1)||(foper>4)) {
	   	printf("\tPor favor, seleccione la operacion a realizar: \n\n");
	    printf("\t\t1 - Deposito en Pesos\n");
	  	printf("\t\t2 - Extraccion en Pesos\n");
	    printf("\t\t3 - Saldo\n");
	    printf("\t\t4 - Finalizar\n\n\t\t");
		fflush(stdin);
	    scanf("%i",&foper);
		fflush(stdin);
	    system("cls");
	}
    return foper; /* devuelve valor numerico del 1 al 4 El while no permite otra opcion */
}

float depo_minimo(float depop) {
	
	int ban=1;
	static float depmin;
	
	if(ban==1) {
		depmin=depop;
		ban=0;
	}
	else{
		if(depop<depmin){
			depmin=depop;
		}
	}
	return depmin;
}

float depo_maximo(float depop) {
	
	int ban=1;
	static float depmax;
	
	if(ban==1) {
		depmax=depop;
		ban=0;
	}
	else{
		if(depmax<depop){
			depmax=depop;
		}
	}
	return depmax;
}
