#include <stdio.h>
int main(){
    int c,voc=0,cons=0,dig=0,otr=0,esp=0,palabra=0,longpal=0,contpal=0,maxlongpal=0,total=0;
    for(;;){
        c=getchar();
        if(c==10||c==EOF){
            if(palabra){
                maxlongpal=longpal;
            }
            break;
        }else{
            total++;
            if((c>=65&&c<=90)||(c>=97&&c<=122)){
                palabra=1;
                longpal++;
                switch(c){
                case 97:
                case 101:
                case 105:
                case 111:
                case 117:
                case 65:
                case 69:
                case 73:
                case 79:
                case 85: voc++;break;
                default: cons++;
                }
            }else if(c>=48&&c<=57){
                dig++;
                palabra=1;
                longpal++;
            }else if(c==32){
                esp++;
                if(palabra){
                    if(contpal==0){
                        maxlongpal=longpal;
                    }else{
                        if(longpal>maxlongpal){
                            maxlongpal=longpal;
                        }
                    }
                    contpal++;
                    palabra=0;
                    longpal=0;
                }
            }else{
                otr++;
            }
        }
        getchar();
    }
    if(!(total||voc||cons||dig||esp||otr||contpal||maxlongpal)){
        printf("Linea vacia");
    }else{
    printf("== REPORTE LEXICO ==\n");
    printf("Longitud total: %d\n",total);
    printf("Vocales: %d\n",voc);
    printf("Consonantes: %d\n",cons);
    printf("Digitos: %d\n",dig);
    printf("Espacios: %d\n",esp);
    printf("Otros: %d\n",otr);
    printf("Palabras: %d\n",contpal);
    printf("Palabra mas larga: %d\n",maxlongpal);
    }
    return 0;
}