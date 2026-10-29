#include <stdio.h>
#include <stdlib.h>
//lista osea array, n osea tamaño, objetivo, indice 
//el const le asegura a C que ninguno de los elementos en la memoria asociados al puntero variará
int buscar(const int *v, int n, int objetivo, int *posicion){
    if(v==NULL||n<=0||posicion==NULL){
        return 0;
    }else{
        int encontrado=0;
        for(int i=n-1;i>=0;i--){
            if(objetivo==*(v+i)){
                //solo modifica posicion si es que encuentra al objetivo
                *posicion=i;
                encontrado=1;
            }
        }
        return encontrado;
    }
}

//acá sí van a variar
void reemplazar(int *v, int n, int antiguo, int nuevo){
    for(int i=0;i<n;i++){
        if(antiguo==*(v+i)){
            *(v+i)=nuevo;
        }
    }
}

int main(){
    //creando y leyendo la lista
    int n;
    do{
        printf("Ingrese la cantidad de enteros: ");
        scanf("%d",&n);  
    }while(n<0||n>500);
    int *lista;
    lista=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Ingrese el elemento de posicion %d: ",i);
        scanf("%d",lista+i);
    }

    //leyendo el objetivo y buscándolo
    int objetivo;
    printf("Ingrese un objetivo a buscar: ");
    scanf("%d",&objetivo);
    //inicializa posicion en 0 porque sino tendria basura
    int posicion=0;
    int valor=buscar(lista,n,objetivo,&posicion);
    //guardo posicion en temp porque luego volveré a usar la funcion buscar y eso podria modificar posición
    int temp=posicion;
    if(valor){
        printf("Encontrado por primera vez en posicion: %d \n",posicion);
    }else{
        printf("No encontrado o la lista no es valida.\n");
    }

    //proceso de reemplazar
    int nuevo;
    printf("Ingrese el numero que desea reemplazar: ");
    scanf("%d",&objetivo);
    printf("Ingrese el numero por el que desea reemplazarlo: ");
    scanf("%d",&nuevo);
    valor=buscar(lista,n,objetivo,&posicion);
    posicion=temp;
    //paso extra para asegurar que lo que busco reemplazar existe
    if(valor){
        reemplazar(lista,n,objetivo,nuevo);
        printf("Reemplazar %d por %d: \n",objetivo,nuevo);
        printf("Arreglo: ");
        for(int i=0;i<n;i++){
            printf("%d ",*(lista+i));
        }
    }else{
        printf("El numero que desea reemplazar no esta en la lista.");
    }
    return 0;
}