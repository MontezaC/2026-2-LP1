#include <stdio.h>
int main(void){
// 1. Multiplicar/dividir por potencias de 2 (mas rapido en HW)
int n = 5;
printf("5 << 1 = %d (= 5*2)\n", n << 1);
printf("5 << 3 = %d (= 5*8)\n", n << 3);
printf("40 >> 3 = %d (= 40/8)\n", 40 >> 3);
//linea 4:                        n=00000101
//linea 5 (solo en el print): print=00001010
//linea 6 (solo en el print): print=00101000

// 2. Verificar si un bit esta encendido (bitmask)
#define BIT(n) (1u << (n))
unsigned char flags = 0;
flags |= BIT(2); // encender bit 2
flags |= BIT(5); // encender bit 5
printf("flags = 0x%02X\n", flags);
printf("bit 2 encendido? %d\n", (flags & BIT(2)) != 0);
printf("bit 3 encendido? %d\n", (flags & BIT(3)) != 0);
//linea 14:  flags=00000000
//linea 15:flagsOR=00000100
//linea 15:  flags=00000100
//linea 16:flagsOR=00100000
//linea 16:  flags=00100100


// 3. Apagar un bit
flags &= ~BIT(2);
printf("tras apagar bit 2: 0x%02X\n", flags);
//linea 16: flags=00100100
//linea 28:flags&=11111011 (&:AND)
//linea 28: flags=00100000

// 4. Alternar (toggle) un bit
flags ^= BIT(5);
printf("tras toggle bit 5: 0x%02X\n", flags);
//linea 28: flags=00100000
//linea 35:flagsD=00100000 (DELTA: XOR)
//linea 35: flags=00000000

// 5. Intercambiar dos enteros sin variable auxiliar (XOR swap)
int x = 13, y = 27;
x ^= y; y ^= x; x ^= y;
printf("x=%d, y=%d\n", x, y);
}