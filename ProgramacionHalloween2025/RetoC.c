#include <stdio.h>

int main() {
    printf("¡Feliz Halloween 2025!\n");
    printf("Autor: Juan Luis Prieto Panadero\n");
    printf("Contacto: i22prpaj@uco.es\n");
    printf("Estudiante de Ingeniería Informática en la EPSC\n");
    printf("Mención: Computación\n");

    int o = 0;
    do{
        printf("1.Contar caramelos 🍬\n");
        printf("2.Limpiar el conjuro 🧙\n");
        printf("3.Inventario de calabazas 🎃\n");
        printf("4.Truco o Trato 🎭\n");
        printf("5.Ruta en el cementerio (BFS)\n");
        printf("6.Compresor de aullidos (RLE) 🐺\n");
        printf("7.Agenda embrujada 📅 \n");
        printf("8.Censo de fantasmas 👻 \n");
        printf("9.Cifrado del vampiro (ROT-N)🧛\n");
        printf("0.Salir 🚪\n");
        printf("Elige una opción: ");
        scanf("%d", &o);
        switch(o){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 0:
                printf("¡Hasta la próxima! 🎃👻\n");
                break;
            default:
                printf("Opción no válida. Por favor, elige de nuevo.\n");
                break;
        }
    } while(o != 0);
    return 0;
}