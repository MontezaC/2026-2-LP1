#include <stdio.h>
int ackermann(int m, int n){
    static int cont=0;
    if(m==0){
        return n+1;
    }else if(m>0&&n==0){
        return ackermann(m-1,1);
    }else if(m>0&&n>0){
        return ackermann(m-1,ackermann(m,n-1));
    }else{
        //intento de caso base
        return 0;
    }
    cont++;
}
//B. Intentar ackerman(4,2) produce un bucle infinito, quizas se podria arreglar haciendo 
//que el ultimo else retorne un numero que arregle todos los bucles posibles
int main(){
    int pa,pb;
    printf("Ingrese A: ");
    scanf("%d",&pa);
    printf("Ingrese B: ");
    scanf("%d",&pb);
    printf("Resultado de la funcion de Ackermann con %d y %d: %d",pa,pb,ackermann(pa,pb));
    //no se como mostrar la variable cont en este bloque, intente con &, *, :: y nada :(
    //C. como se explica en la pregunta 1, la variable debe ser static para recordar cada cambio que le hace cada llamada de funcion
    return 0;
}