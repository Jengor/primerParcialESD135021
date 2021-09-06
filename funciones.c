
#include "header.h"

int Transpuesta[6][59];
int Resultado[59][59];
int arreglo[59][6];


int leer_archivo (char *direccion){
FILE *archivo = fopen(direccion, "r");
if ( archivo )
   {
      char flujo;

      while ((flujo = fgetc(archivo)) != EOF)
      {
      // printf("%c",flujo); impresion de la lectura
      }
      fclose(archivo);
   }
   
return 0;
}


int extraer(char *direccion)
{
   FILE *archivo = fopen(direccion, "r");
   if ( archivo )
   {
      size_t contadorF=0, contadorC=-1;
      char flujo;

      while ((flujo = fgetc(archivo)) != EOF)
      {
           switch(flujo){
            case ',':
                contadorC++;
                break;
            case '\n':
                contadorF++;
                contadorC=0;
                break;
            case '0':
                arreglo[contadorF][contadorC]=0;
                break;
            case '1':
                arreglo[contadorF][contadorC]=1;
                break;
            default:
                while(flujo!=',' && flujo!='\n' && flujo!=EOF){
                    flujo=fgetc(archivo);
                }
                break;
        }
          
      }
      fclose(archivo);
   }

   return 0;
}

int transponer(){
    int i,j;
    for(i=0;i<59;i++){
        for(j=0;j<6;j++){
            Transpuesta[j][i]=arreglo[i][j];
        }
    }
    return 0;
}

int Multiplicacion(){
    int i,j,x,suma;
    for(i=0;i<59;i++){
        for(j=0;j<59;j++){
            suma = 0;
            for(x=0;x<6;x++){
                suma+=arreglo[i][j]*Transpuesta[x][j];
            }
            Resultado[i][j]=suma;
        }
    }
    return 0;
}

int carnes(){
    char *carne1="RC19106";
    char *carne2="PG19065";
    FILE *archivo = fopen("carnets.csv", "w");
   if ( archivo==NULL ){
       printf("no se pudo crear el archivo");
       exit(1);
   }
    fprintf(archivo,"%s, %s", carne1, carne2); // retorna un archivo .csv con los carnets de los integrantes 
    return 0;
}