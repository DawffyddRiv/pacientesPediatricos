//Dawffydd_R
#include<stdio.h>
#include<stdlib.h>

struct pediatrico{
	int nss;
	char nombre[30];
	char apellido[30];
	
}pacientes[]; 

//int decision();
int menu();
char datosId(int a);
float indMasaCorp();
void estadoImc(float inMc);
float coefCrec();
float dataPadres();

int main(){	
	int opcion,indice;
	float imc,coefCorp;	
	int contador=0; 
	printf("Programa para estimar condicion IMC y CC de pacientes pedriatricos\n");
	while (contador>=0){
		fflush(stdin);
		datosId(contador);
		
		printf("[1]C%clculo de masa corporal\n[2]C%clculo de crecimiento(CC)\n[3]Salir\n",160,160);
		scanf("%d",&opcion);
		while (opcion<1||opcion>3){// "menu" aplicando paso por referencia
			menu(&opcion);	
		}
	
		if (opcion==1){
			printf("Elegiste la opcion 1\n");	
			imc=indMasaCorp(opcion);
			printf("Nombre completo:  %s %s  ",pacientes[contador].nombre,pacientes[contador].apellido);
			printf("No de registro:  %d  \n",pacientes[contador].nss+1);
			printf("El indice de masa corporal es: %.2f \n", imc);
			estadoImc(imc);
			system ("pause");
			system("cls");
		}	
		else if (opcion==2){
			printf("Elegiste la segunda opcion\n");		
			coefCorp=coefCrec(opcion);			
			printf("Nombre completo:  %s %s  ",pacientes[contador].nombre,pacientes[contador].apellido);
			printf("No de registro:  %d  \n",pacientes[contador].nss+1);
			printf("El resultado del CC en cm es: %.2f \n", coefCorp);		
			system ("pause");
			system("cls");						
		}	
		
		else {
			printf("Has elegido la opcion salir\n");	
			break;		
		}	
		
		//Correspondiente al while 
		contador=contador+1;
	}
	
	
	
	return 0;
}

int menu(int *a){
	printf("Elige una opci%cn\n",162);
	printf("[1]C%clculo de masa corporal\n[2]C%clculo de crecimiento(CC)\n[3]Salir\n",160,160);
	scanf("%d",a);
	return *a;	
}

char datosId(int a){
	printf("Introduce nombre\n");
	gets(pacientes[a].nombre);
	printf("Introduce apellido\n");
	gets(pacientes[a].apellido);
	printf("Nombre completo %s %s  ",pacientes[a].nombre,pacientes[a].apellido);
	pacientes[a].nss=a;
	printf("No de registro: %d  \n",pacientes[a].nss+1);
}

float indMasaCorp(int x){
	float w,h,mbi;
	printf("C%clculo de masa corporal\n",160);
	printf("Introduce el peso del infante en kilogramos\n");
	scanf("%f",&w);
	while(w<3||w>70){
		printf("No introduciste un peso real.Vuelve a intentarlo\n");
		scanf("%f",&w);
	}	
	printf("Introduce la altura del infante en metros\n");
	scanf("%f",&h);
	while(h<.5||h>1.80){
		printf("No introduciste una altura real.Vuelve a intentarlo\n");
		scanf("%f",&h);
	}

	return w/(h*h);;	
}

void estadoImc(float inMc){
	if (inMc<18.5){
		printf("Estado del peso: Bajo peso\n");
	}
	else if(inMc>=18.5 && inMc<25 ){
		printf("Estado del peso: Peso normal\n");
	}
	else if(inMc>=25 && inMc<29.9){
		printf("Estado del peso: Sobrepeso\n");
	}
	else{
		printf("El infante tiene obesidad morbida o padece \n");
		printf("alguna condicion particular fuera del alcance\n ");
		printf("del analisis de este programa\n");
	}
}

float coefCrec(int y){
	int opcionCC;
	float tallaPa,tallaMa,talla;
	printf("C%clculo de crecimiento (CC)\n",160);
	printf("Indica el sexo del infante\n",162);
	printf("[1]Masculino\n[2]Femenino\n");
	scanf("%d",&opcionCC);
	while(opcionCC<1 || opcionCC>2){// ||=Y=interseccion=conjuncion
		printf("Indica el sexo del infante\n",162);
		printf("[1]Masculino\n[2]Femenino\n");
		scanf("%d",&opcionCC);
	}
	if(opcionCC==1){
		printf("Introduce la talla del padre en cm\n");
		scanf("%f",&tallaPa);
		while(tallaPa<54||tallaPa>270){
			printf("No introduciste un peso real.Vuelve a intentarlo\n");
			scanf("%f",&tallaPa);
		}
		printf("Introduce la talla de la madre en cm\n");
		scanf("%f",&tallaMa);
		while(tallaMa<54||tallaMa>270){
			printf("No introduciste un peso real.Vuelve a intentarlo\n");
			scanf("%f",&tallaMa);
		}		
		talla=( (tallaPa+tallaMa)/2 ) +6.5;//estado(imc);		
		}
	else {
		printf("Introduce la talla del padre en cm\n");
		scanf("%f",&tallaPa);
		while(tallaPa<54||tallaPa>270){
			printf("No introduciste un peso real.Vuelve a intentarlo\n");
			scanf("%f",&tallaPa);
		}
		printf("Introduce la talla de la madre en cm\n");
		scanf("%f",&tallaMa);
		while(tallaMa<54||tallaMa>270){
			printf("No introduciste un peso real.Vuelve a intentarlo\n");
			scanf("%f",&tallaMa);
		}
		talla=( (tallaPa+tallaMa)/2 ) -6.5;	
	}
	return talla;		 	
}
//Por definir una funcion que recupere los datos de los padres. A usar paso por referencia
float dataPadres(){
}

