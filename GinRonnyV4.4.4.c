/*Librerias*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//Si se escibre la palabra "Inicio" comienza el juego
//Si se escribre la palabra "Puntos" se despliega las 10 mejores puntuaciones obtenidas por el jugador.
//Si se escribe la palabra "Instruciones" se despliega las instrucciones.
int buscarNumero(int numero,int arreglo[],int tam); //invoco la función BuscarNumero para que el programa compile exitosamente

// Variables de los nombres de las puntuaciones

int puntuacion = 0;
int nombre;
char nombre1[20];
int score;
int scorePC;


int main() /*Ejecuta el menu de inicio*/{


        printf(".------.------.                                                              .------.------.\n");
        printf("|A.--. |2.--. |                                                              |5.--. |6.--. |\n");
        printf("| (\\/) | (\\/) |                                                              | :/\\: | (\\/) |\n");
        printf("| :\\/: | :\\/: |                                                              | (__) | :\\/: |\n");
        printf("| '--'A| '--'2|                                                              | '--'5| '--'6|\n");
        printf("`------`------'                                                              `------`------'\n");
        
        printf("               .------.------.------.------.------.------.------.------.------.\n");
        printf("               |B.--. |I.--. |N.--. |V.--. |N.--. |I.--. |D.--. |O.--. |S.--. |\n");
        printf("               | :(): | (\\/) | :(): | :(): | :(): | (\\/) | :/\\: | :/\\: | :/\\: |\n");
        printf("               | ()() | :\\/: | ()() | ()() | ()() | :\\/: | (__) | :\\/: | :\\/: |\n");
        printf("               | '--'B| '--'I| '--'N| '--'V| '--'N| '--'I| '--'D| '--'O| '--'S|\n");
        printf("               `------`------`------`------`------`------`------`------`------'\n");

        printf(".------.------.                                                              .------.------.\n");
        printf("|4.--. |3.--. |                                                              |7.--. |8.--. |\n");
        printf("| (\\/) | (\\/) |                                                              | :/\\: | (\\/) |\n");
        printf("| :\\/: | :\\/: |                                                              | (__) | :\\/: |\n");
        printf("| '--'4| '--'3|                                                              | '--'7| '--'8|\n");
        printf("`------`------'                                                              `------`------'\n");
    int opcion;
    char temp [10];
    do{

        printf("\n ¡¡¡¡¡ AVISO !!!!!\nRECOMANDAMOS LEER PRIMERO LAS INSTRUCCIONES PARA SABER COMO GANAR\n");
        printf(" \n");
        printf("\n1) Para iniciar el juego  \n2) Para leer las intrucciones \n3) Para ver las mejores puntaciones \n4) Para salir del juego \n");
        printf("\nIngrese una numero para realizar su seleccion: ");
        ///fgets se utiliza para leer la cadena
        fgets(temp,10,stdin);
        ///atoi funciona para convertir lo que leyo de la entrada standar a numero que en este caso es lo que definimos como opcion, y atoi lo cambia de una letra a numero 

        opcion = atoi(temp);
        switch(opcion)
    {
            
            case 1: 
            printf("Juego iniciado\n");
            printf("\n ¡¡¡¡¡ AVISO !!!!!\nRECOMANDAMOS LEER PRIMERO LAS INSTRUCCIONES PARA SABER COMO GANAR\n");
            printf("Introduzca ""-"" en lugar de espacios si desea colocar un espacio en su nombre.");
            printf( "\n   Introduzca el nombre del jugador: ");
            scanf( "%s", &nombre1);
            inicioJuego();
            printf("Fin del juego!!!\n");
            printf("Su puntuacion fue de: %d\n",score);
            printf("La puntuacion de la PC fue de: %d\n",scorePC);
            gane();
            printf("-------------------------------------------------------------\n");
            printf("\nIngresa cualquier tecla si desea volver menu de inicio "); 
            break;
            
            case 2: 
            reglas(); 
            printf("\nIngresa cualquier tecla si desea volver al menu de inicio"); 
            break;
            
            case 3: 
            printf("\nTOP 10 \n");
            top10At(); /*crea el archivo*/
            lecturatxt(); /*lo imprime*/
            printf("\nIngresa cualquier tecla si desea volver al menu de inicio "); 

            break;
            case 4: 
            printf("********FIN DEL JUEGO********\n"); 
            creditos();
            break;
        default: 
            printf("\nIngresa un opcion valida: ");
    }
    
        getch();
    }while (opcion!=4);
    
}


/*Case 3 Iniciar juego*/
void inicioJuego(){
    //***********************Proceso de creado de la baraja***********************//
    //Aquí se asigna variables enteras que contienen los valores propuestos para carta, en el caso de tener un AsCorazones tiene un valor de
    //101, esto permite que se puedan hacer grupos. AsDiamantes = 101, AsCorazones = 201 y AsFlores = 301, se puede observar que todas terminan
    //en 1, por lo tanto de puede formar un grupo de 3 cartas siguiendo las reglas del Gin Rummy, por otra parte si tengo un AsFlores, 

    int AsDiamantes = 101, DosDiamantes = 102, TresDiamantes = 103, CuadroDiamantes = 104, CincoDiamantes = 105, SeisDiamantes = 106;
    int SieteDiamantes = 107, OchoDiamantes = 108, NueveDiamantes = 109, DiezDiamantes = 110, JotaDiamantes = 111, QuinaDiamantes = 112, KaDiamantes =113;
    
    int AsCorazones = 201, DosCorazones = 202, TresCorazones = 203, CuadroCorazones = 204, CincoCorazones = 205, SeisCorazones = 206;
    int SieteCorazones = 207, OchoCorazones = 208, NueveCorazones = 209, DiezCorazones = 210, JotaCorazones = 211, QuinaCorazones = 212, KaCorazones =213;

    int AsFlores = 301, DosFlores = 302, TresFlores = 303, CuadroFlores = 304, CincoFlores = 305, SeisFlores = 306;
    int SieteFlores = 307, OchoFlores = 308, NueveFlores = 309, DiezFlores = 310, JotaFlores = 311, QuinaFlores = 312, KaFlores =313;

    int AsEspadas = 401, DosEspadas = 402, TresEspadas = 403, CuadroEspadas = 404, CincoEspadas = 405, SeisEspadas = 406;
    int SieteEspadas = 407, OchoEspadas =408, NueveEspadas = 409, DiezEspadas = 410, JotaEspadas = 411, QuinaEspadas = 412, KaEspadas =413;

    //1 a 13 son Diamantes, 14 a 26 son Corazones, 27 a 39 son Flores y 40 a 53 Espadas
    int baraja[52] = {AsDiamantes, DosDiamantes, TresDiamantes, CuadroDiamantes, CincoDiamantes, SeisDiamantes, SieteDiamantes,
                    OchoDiamantes, NueveDiamantes, DiezDiamantes, JotaDiamantes, QuinaDiamantes, KaDiamantes,
                    AsCorazones, DosCorazones, TresCorazones, CuadroCorazones, CincoCorazones, SeisCorazones, SieteCorazones,
                    OchoCorazones, NueveCorazones, DiezCorazones, JotaCorazones, QuinaCorazones, KaCorazones,
                    AsFlores, DosFlores, TresFlores, CuadroFlores, CincoFlores, SeisFlores, SieteFlores,
                    OchoFlores, NueveFlores, DiezFlores, JotaFlores, QuinaFlores, KaFlores,
                    AsEspadas, DosEspadas, TresDiamantes, CuadroEspadas, CincoEspadas, SeisEspadas, SieteEspadas,
                    OchoEspadas, NueveEspadas, DiezDiamantes, JotaEspadas, QuinaEspadas, KaEspadas};
    
    //***********************Creando la lógica para dos mazos de 10 cartas***********************
    int mazoJugador[9];    //Matriz de mazo para el jugador
    int mazoPC[9];          //Matriz de mazo para el PC
    int contaJ = 0;         //Iterador para mazoJugador
    int contaP = 0;         //Iterador para mazoPC 
    int min,max;            //Rango de valores de números random posibles
    min=0;
    max=51;
    int numeros[20]={0};    //Matriz que guarda los números aleatorios.
    int num_aleatorio;      //Guarda los números aleatorios
    int fstop;              //Stop para el while
    int i;                  //Iterador para el ciclo for
    int carta;
    int num;
    int num2;
    srand(time(NULL));      //Función random para generar los números
    for(i=0;i<20;i++)       //Ciclo de 20 que generá números aleatorios entre 0 y 51.
    {
        do{
            num_aleatorio=min+rand()%(max-min+1);
            fstop=buscarNumero(num_aleatorio,numeros,19);
        }while(fstop);
        numeros[i]=num_aleatorio;
        //printf("%d\n",numeros[i]);
        //Condicional para mandar crear el mazoPC en los ciclos donde i es impar, y crear mazoJugador cuando i sea par.
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 || i == 19){
            mazoPC[contaP] = baraja[num_aleatorio];
            contaP++;
            baraja[num_aleatorio] = 0; //Actualiza la baraja, de forma que las cartas que estén en mazoPC ya no estén 
                                       //en la baraja.
        }
        else{
            mazoJugador[contaJ] = baraja[num_aleatorio];
            contaJ++;
            baraja[num_aleatorio] = 0; //Actualiza la baraja, de forma que las cartas que estén en mazoJugadorya no estén 
                                       //en la baraja.
        }
        
    }

    int r;
    int aux;
    contaJ = 0;
    contaP = 0;
    int puntosJ[10];
    int puntosC[10];
    for(r=0;r<32;r++) /*cantidad de veces que se repide el ciclo*/
    {
        do{
            num_aleatorio=min+rand()%(max-min+1);
            fstop=buscarNumero(num_aleatorio,numeros,32);
        }while(fstop);
        numeros[r]=num_aleatorio;
        while(baraja[num_aleatorio]==0)
        {
            do{
            num_aleatorio=min+rand()%(max-min+1);
            fstop=buscarNumero(num_aleatorio,numeros,32);
            }while(fstop);
            numeros[r]=num_aleatorio;  
        }
        if (r == 0  || r == 2  || r == 4  || r == 6  || r == 8  || 
            r == 10 || r == 12 || r == 14 || r == 16 || r == 18 ||
            r == 20 || r == 22 || r == 24 || r == 26 || r == 28 || r == 30){
            printf("\n");
            printf("\n");
            printf("\nSe saca la siguiente carta de la baraja: ");
            for(i=0;i<1;i++)
                {
                    if(101<=baraja[num_aleatorio]<=113){
                        carta = baraja[num_aleatorio] - 100;
                        if (carta == 1){
                            printf(" A%c ",4);
                        }else if (carta == 2){
                            printf(" 2%c ",4);
                        }else if (carta == 3){
                            printf(" 3%c ",4);
                        }else if (carta == 4){
                            printf(" 4%c ",4);
                        }else if (carta == 5){
                            printf(" 5%c ",4);
                        }else if (carta == 6){
                            printf(" 6%c ",4);
                        }else if (carta == 7){
                            printf(" 7%c ",4);
                        }else if (carta == 8){
                            printf(" 8%c ",4);
                        }else if (carta == 9){
                            printf(" 9%c ",4);
                        }else if (carta == 10){
                            printf(" 10%c ",4);
                        }else if (carta == 11){
                            printf(" J%c ",4);
                        }else if (carta == 12){
                            printf(" Q%c ",4);
                        }else if (carta == 13){
                            printf(" K%c ",4);
                        }else{} 

                    }
                    if(201<=baraja[num_aleatorio]<=213){
                        carta = baraja[num_aleatorio] - 200;
                        if (carta == 1){
                            printf(" A%c ",3);
                        }else if (carta == 2){
                            printf(" 2%c ",3);
                        }else if (carta == 3){
                            printf(" 3%c ",3);
                        }else if (carta == 4){
                            printf(" 4%c ",3);
                        }else if (carta == 5){
                            printf(" 5%c ",3);
                        }else if (carta == 6){
                            printf(" 6%c ",3);
                        }else if (carta == 7){
                            printf(" 7%c ",3);
                        }else if (carta == 8){
                            printf(" 8%c ",3);
                        }else if (carta == 9){
                            printf(" 9%c ",3);
                        }else if (carta == 10){
                            printf(" 10%c ",3);
                        }else if (carta == 11){
                            printf(" J%c ",3);
                        }else if (carta == 12){
                            printf(" Q%c ",3);
                        }else if (carta == 13){
                            printf(" K%c ",3);
                        }else{} 
                    }
                    if(301<=baraja[num_aleatorio]<=313){
                        carta = baraja[num_aleatorio] - 300;
                        if (carta == 1){
                            printf(" A%c ",5);
                        }else if (carta == 2){
                            printf(" 2%c ",5);
                        }else if (carta == 3){
                            printf(" 3%c ",5);
                        }else if (carta == 4){
                            printf(" 4%c ",5);
                        }else if (carta == 5){
                            printf(" 5%c ",5);
                        }else if (carta == 6){
                            printf(" 6%c ",5);
                        }else if (carta == 7){
                            printf(" 7%c ",5);
                        }else if (carta == 8){
                            printf(" 8%c ",5);
                        }else if (carta == 9){
                            printf(" 9%c ",5);
                        }else if (carta == 10){
                            printf(" 10%c ",5);
                        }else if (carta == 11){
                            printf(" J%c ",5);
                        }else if (carta == 12){
                            printf(" Q%c ",5);
                        }else if (carta == 13){
                            printf(" K%c ",5);
                        }else{} 
                    }
                    if(401<=baraja[num_aleatorio]<=413){
                        carta = baraja[num_aleatorio] - 400;
                        if (carta == 1){
                            printf(" A%c ",6);
                        }else if (carta == 2){
                            printf(" 2%c ",6);
                        }else if (carta == 3){
                            printf(" 3%c ",6);
                        }else if (carta == 4){
                            printf(" 4%c ",6);
                        }else if (carta == 5){
                            printf(" 5%c ",6);
                        }else if (carta == 6){
                            printf(" 6%c ",6);
                        }else if (carta == 7){
                            printf(" 7%c ",6);
                        }else if (carta == 8){
                            printf(" 8%c ",6);
                        }else if (carta == 9){
                            printf(" 9%c ",6);
                        }else if (carta == 10){
                            printf(" 10%c ",6);
                        }else if (carta == 11){
                            printf(" J%c ",6);
                        }else if (carta == 12){
                            printf(" Q%c ",6);
                        }else if (carta == 13){
                            printf(" K%c ",6);
                        }else{} 
                    }
                } 

            printf("\nEsta carta fue agarrada por la maquina\n");
            printf("\nLa maquina decidio dejar la carta: ");
            for(i=0;i<1;i++)
                {
                    if(101<=mazoPC[0]<=113){
                        carta = mazoPC[0] - 100;
                        if (carta == 1){
                            printf(" A%c ",4);
                        }else if (carta == 2){
                            printf(" 2%c ",4);
                        }else if (carta == 3){
                            printf(" 3%c ",4);
                        }else if (carta == 4){
                            printf(" 4%c ",4);
                        }else if (carta == 5){
                            printf(" 5%c ",4);
                        }else if (carta == 6){
                            printf(" 6%c ",4);
                        }else if (carta == 7){
                            printf(" 7%c ",4);
                        }else if (carta == 8){
                            printf(" 8%c ",4);
                        }else if (carta == 9){
                            printf(" 9%c ",4);
                        }else if (carta == 10){
                            printf(" 10%c ",4);
                        }else if (carta == 11){
                            printf(" J%c ",4);
                        }else if (carta == 12){
                            printf(" Q%c ",4);
                        }else if (carta == 13){
                            printf(" K%c ",4);
                        }else{} 

                    }
                    if(201<=mazoPC[0]<=213){
                        carta = mazoPC[0] - 200;
                        if (carta == 1){
                            printf(" A%c ",3);
                        }else if (carta == 2){
                            printf(" 2%c ",3);
                        }else if (carta == 3){
                            printf(" 3%c ",3);
                        }else if (carta == 4){
                            printf(" 4%c ",3);
                        }else if (carta == 5){
                            printf(" 5%c ",3);
                        }else if (carta == 6){
                            printf(" 6%c ",3);
                        }else if (carta == 7){
                            printf(" 7%c ",3);
                        }else if (carta == 8){
                            printf(" 8%c ",3);
                        }else if (carta == 9){
                            printf(" 9%c ",3);
                        }else if (carta == 10){
                            printf(" 10%c ",3);
                        }else if (carta == 11){
                            printf(" J%c ",3);
                        }else if (carta == 12){
                            printf(" Q%c ",3);
                        }else if (carta == 13){
                            printf(" K%c ",3);
                        }else{} 
                    }
                    if(301<=mazoPC[0]<=313){
                        carta = mazoPC[0] - 300;
                        if (carta == 1){
                            printf(" A%c ",5);
                        }else if (carta == 2){
                            printf(" 2%c ",5);
                        }else if (carta == 3){
                            printf(" 3%c ",5);
                        }else if (carta == 4){
                            printf(" 4%c ",5);
                        }else if (carta == 5){
                            printf(" 5%c ",5);
                        }else if (carta == 6){
                            printf(" 6%c ",5);
                        }else if (carta == 7){
                            printf(" 7%c ",5);
                        }else if (carta == 8){
                            printf(" 8%c ",5);
                        }else if (carta == 9){
                            printf(" 9%c ",5);
                        }else if (carta == 10){
                            printf(" 10%c ",5);
                        }else if (carta == 11){
                            printf(" J%c ",5);
                        }else if (carta == 12){
                            printf(" Q%c ",5);
                        }else if (carta == 13){
                            printf(" K%c ",5);
                        }else{} 
                    }
                    if(401<=mazoPC[0]<=413){
                        carta = mazoPC[0] - 400;
                        if (carta == 1){
                            printf(" A%c ",6);
                        }else if (carta == 2){
                            printf(" 2%c ",6);
                        }else if (carta == 3){
                            printf(" 3%c ",6);
                        }else if (carta == 4){
                            printf(" 4%c ",6);
                        }else if (carta == 5){
                            printf(" 5%c ",6);
                        }else if (carta == 6){
                            printf(" 6%c ",6);
                        }else if (carta == 7){
                            printf(" 7%c ",6);
                        }else if (carta == 8){
                            printf(" 8%c ",6);
                        }else if (carta == 9){
                            printf(" 9%c ",6);
                        }else if (carta == 10){
                            printf(" 10%c ",6);
                        }else if (carta == 11){
                            printf(" J%c ",6);
                        }else if (carta == 12){
                            printf(" Q%c ",6);
                        }else if (carta == 13){
                            printf(" K%c ",6);
                        }else{} 
                    }
                }
            printf("\n");
            aux = mazoPC[0];
            mazoPC[0] = baraja[num_aleatorio];
            baraja[num_aleatorio] = 0;
            }
        else{
            //printf("\nTienes las siguientes cartas:\n [%d %d %d %d %d %d %d %d %d %d]\n", mazoJugador[0], 
            //mazoJugador[1], mazoJugador[2], mazoJugador[3], mazoJugador[4], mazoJugador[5],
            //mazoJugador[6], mazoJugador[7], mazoJugador[8], mazoJugador[9]);
            printf("\nTienes las siguientes cartas: \n [");
            for(i=0;i<10;i++)
                {
                if(101<=mazoJugador[i]<=113){
                    carta = mazoJugador[i] - 100;
                    if (carta == 1){
                        printf(" A%c ",4);
                        }else if (carta == 2){
                            printf(" 2%c ",4);
                        }else if (carta == 3){
                            printf(" 3%c ",4);
                        }else if (carta == 4){
                            printf(" 4%c ",4);
                        }else if (carta == 5){
                            printf(" 5%c ",4);
                        }else if (carta == 6){
                            printf(" 6%c ",4);
                        }else if (carta == 7){
                            printf(" 7%c ",4);
                        }else if (carta == 8){
                            printf(" 8%c ",4);
                        }else if (carta == 9){
                            printf(" 9%c ",4);
                        }else if (carta == 10){
                            printf(" 10%c ",4);
                        }else if (carta == 11){
                            printf(" J%c ",4);
                        }else if (carta == 12){
                            printf(" Q%c ",4);
                        }else if (carta == 13){
                            printf(" K%c ",4);
                        }else{} 

                    }
                    if(201<=mazoJugador[i]<=213){
                        carta = mazoJugador[i] - 200;
                        if (carta == 1){
                            printf(" A%c ",3);
                        }else if (carta == 2){
                            printf(" 2%c ",3);
                        }else if (carta == 3){
                            printf(" 3%c ",3);
                        }else if (carta == 4){
                            printf(" 4%c ",3);
                        }else if (carta == 5){
                            printf(" 5%c ",3);
                        }else if (carta == 6){
                            printf(" 6%c ",3);
                        }else if (carta == 7){
                            printf(" 7%c ",3);
                        }else if (carta == 8){
                            printf(" 8%c ",3);
                        }else if (carta == 9){
                            printf(" 9%c ",3);
                        }else if (carta == 10){
                            printf(" 10%c ",3);
                        }else if (carta == 11){
                            printf(" J%c ",3);
                        }else if (carta == 12){
                            printf(" Q%c ",3);
                        }else if (carta == 13){
                            printf(" K%c ",3);
                        }else{} 
                    }
                    if(301<=mazoJugador[i]<=313){
                        carta = mazoJugador[i] - 300;
                        if (carta == 1){
                            printf(" A%c ",5);
                        }else if (carta == 2){
                            printf(" 2%c ",5);
                        }else if (carta == 3){
                            printf(" 3%c ",5);
                        }else if (carta == 4){
                            printf(" 4%c ",5);
                        }else if (carta == 5){
                            printf(" 5%c ",5);
                        }else if (carta == 6){
                            printf(" 6%c ",5);
                        }else if (carta == 7){
                            printf(" 7%c ",5);
                        }else if (carta == 8){
                            printf(" 8%c ",5);
                        }else if (carta == 9){
                            printf(" 9%c ",5);
                        }else if (carta == 10){
                            printf(" 10%c ",5);
                        }else if (carta == 11){
                            printf(" J%c ",5);
                        }else if (carta == 12){
                            printf(" Q%c ",5);
                        }else if (carta == 13){
                            printf(" K%c ",5);
                        }else{} 
                    }
                    if(401<=mazoJugador[i]<=413){
                        carta = mazoJugador[i] - 400;
                        if (carta == 1){
                            printf(" A%c ",6);
                        }else if (carta == 2){
                            printf(" 2%c ",6);
                        }else if (carta == 3){
                            printf(" 3%c ",6);
                        }else if (carta == 4){
                            printf(" 4%c ",6);
                        }else if (carta == 5){
                            printf(" 5%c ",6);
                        }else if (carta == 6){
                            printf(" 6%c ",6);
                        }else if (carta == 7){
                            printf(" 7%c ",6);
                        }else if (carta == 8){
                            printf(" 8%c ",6);
                        }else if (carta == 9){
                            printf(" 9%c ",6);
                        }else if (carta == 10){
                            printf(" 10%c ",6);
                        }else if (carta == 11){
                            printf(" J%c ",6);
                        }else if (carta == 12){
                            printf(" Q%c ",6);
                        }else if (carta == 13){
                            printf(" K%c ",6);
                        }else{} 
                    }
                } printf("]");
                printf("\n   1   2   3   4   5   6   7   8   9   10  \n");
                printf("\n");
                printf("¿Deseas agarrar la carta que dejo la maquina o tomar una de la baraja?\n");
                printf("Ingresa 1 para agarrar la carta que dejo la maquina.\n");
                printf("Ingresa 2 para agarrar una carta de la baraja.\n");
                do
                {
                    scanf("%d", &num);
                switch(num)
                	   {
                    	case 1:
			                printf("\nSegun la posicion que se muestra abajo de las cartas que tiene."); 
                    	    printf("Ingrese la carta que quiere intercambiar: "); 
                            scanf("%d", &num2);
                            mazoJugador[num2-1]= aux;
                            num++;
			                break;
                        case 2:
                    	    printf("Segun la posicion que se muestra abajo de las cartas que tiene.");
                            printf("Ingrese la carta que quiere intercambiar: ");
                    	    scanf("%d", &num2);
                    	    mazoJugador[num2-1]= baraja[num_aleatorio];
                    	    break;
                		default:
                            printf("Ingrese un valor valido: ");
                        }
                }while(num!=2);
            }
                            i=0;
                while(i<10)
                {
                    if(mazoPC[i]>= 401 & mazoPC[i]<=413)
                    {   
                        puntosC[i]=mazoPC[i]-400;
                        if(puntosC[i]==11) {puntosC[i] = puntosC[i] - 1;}
                        else if(puntosC[i]==12) {puntosC[i] = puntosC[i] - 2;}
                        else if(puntosC[i]==13) {puntosC[i] = puntosC[i] - 3;}
                        i++;
                    }
                    else if(mazoPC[i]>= 301 & mazoPC[i]<=313)
                    {
                        puntosC[i]=mazoPC[i]-300;
                        if(puntosC[i]==11) {puntosC[i] = puntosC[i] - 1;}
                        else if(puntosC[i]==12) {puntosC[i] = puntosC[i] - 2;}
                        else if(puntosC[i]==13) {puntosC[i] = puntosC[i] - 3;}
                        i++;
                    }
                    else if(mazoPC[i]>= 201 & mazoPC[i]<=213)
                    {
                        puntosC[i]=mazoPC[i]-200;
                        if(puntosC[i]==11) {puntosC[i] = puntosC[i] - 1;}
                        else if(puntosC[i]==12) {puntosC[i] = puntosC[i] - 2;}
                        else if(puntosC[i]==13) {puntosC[i] = puntosC[i] - 3;}
                        i++;
                    }
                    else if(mazoPC[i]>= 101 & mazoPC[i]<=113)
                    {
                        puntosC[i]=mazoPC[i]-100;
                        if(puntosC[i]==11) {puntosC[i] = puntosC[i] - 1;}
                        else if(puntosC[i]==12) {puntosC[i] = puntosC[i] - 2;}
                        else if(puntosC[i]==13) {puntosC[i] = puntosC[i] - 3;}          
                        i++;
                    }else {mazoPC[i]=0;i++;} 
                }
                i=0;
                while(i<10)
                {
                    if(mazoJugador[i]>= 401 & mazoJugador[i]<=413)
                    {   
                        puntosJ[i]=mazoJugador[i]-400;
                        if(puntosJ[i]==11) {puntosJ[i] = puntosJ[i] - 1;}
                        else if(puntosJ[i]==12) {puntosJ[i] = puntosJ[i] - 2;}
                        else if(puntosJ[i]==13) {puntosJ[i] = puntosJ[i] - 3;}
                        i++;
                    }
                    else if(mazoJugador[i]>= 301 & mazoJugador[i]<=313)
                    {
                        puntosJ[i]=mazoJugador[i]-300;
                        if(puntosJ[i]==11) {puntosJ[i] = puntosJ[i] - 1;}
                        else if(puntosJ[i]==12) {puntosJ[i] = puntosJ[i] - 2;}
                        else if(puntosJ[i]==13) {puntosJ[i] = puntosJ[i] - 3;}
                        i++;
                    }
                    else if(mazoJugador[i]>= 201 & mazoJugador[i]<=213)
                    {
                        puntosJ[i]=mazoJugador[i]-200;
                        if(puntosJ[i]==11) {puntosJ[i] = puntosJ[i] - 1;}
                        else if(puntosJ[i]==12) {puntosJ[i] = puntosJ[i] - 2;}
                        else if(puntosJ[i]==13) {puntosJ[i] = puntosJ[i] - 3;}
                        i++;
                    }
                    else if(mazoJugador[i]>= 101 & mazoJugador[i]<=113)
                    {
                        puntosJ[i]=mazoJugador[i]-100;
                        if(puntosJ[i]==11) {puntosJ[i] = puntosJ[i] - 1;}
                        else if(puntosJ[i]==12) {puntosJ[i] = puntosJ[i] - 2;}
                        else if(puntosJ[i]==13) {puntosJ[i] = puntosJ[i] - 3;}            
                        i++;
                    }else {mazoJugador[i]=0;i++;} 
                }

        scorePC=puntosC[0] + puntosC[2] + puntosC[3] + puntosC[4] + puntosC[5] + puntosC[6] + puntosC[7] + puntosC[8] + puntosC[9];   
        score = puntosJ[0] + puntosJ[2] + puntosJ[3] + puntosJ[4] + puntosJ[5] + puntosJ[6] + puntosJ[7] + puntosJ[8] + puntosJ[9];
        printf("%s su puntuacion actual es de: %d\n", nombre1, score);
        printf("La puntuacion actual de su rival es de: %d\n", scorePC);



    }
    
    
}

int buscarNumero(int numero,int arreglo[],int tam) //Ayuda a que no se repitan los números en el random
{
    int i, stop=0;
    for (i=0;(i<20 && stop==0);i++)
    {
        if (arreglo[i]==numero)
            stop=1;
    }
    return stop;
}

void gane()
{
    if (score < scorePC)
    {
        printf ("\nFelicidades, has ganado\n");
    }
    if (scorePC<score)
    {
        printf("\nHas perdido\n");
    }
    if (score==scorePC)
    {
        printf ("\nEmpate\n");
    }

}
///Case2
void reglas()/*Lee un archivo de nombre reglas, el posee las reglas basicas generales que tiene el juego*/
{
    FILE* archivo;
    char caracter;
    archivo = fopen("Reglas.txt", "r");
    if (archivo==NULL)
    {
        printf("Falta un archivo\n");
    }else{
        while (feof(archivo)==0){ /*feof funciona para comprobar el indicador al final del archivo si hay algun caracter, para terminar el ciclo while*/
        caracter=fgetc(archivo); /*Funcion para optener un solo caracter unido a feof se puede extrae*/
        printf("%c", caracter);
    }
    printf("\n");
    }
    
    fclose(archivo);
    getch();

}

/*case 4 creditos*/
void creditos()/*Lee un archivo de txt que posse creditos*/
{
    FILE* archivo;
    char caracter;
    archivo = fopen("Creditos.txt", "r");
    if (archivo==NULL)
    {
        printf("Falta un archivo\n");
    }else{
        while (feof(archivo)==0){ /*feof funciona para comprobar el indicador al final del archivo si hay algun caracter, para terminar el ciclo while*/
        caracter=fgetc(archivo); /*Funcion para optener un solo caracter unido a feof se puede extrae*/
        printf("%c", caracter);
    }
    printf("\n");
    }
    
    fclose(archivo);
    getch();


}

/*Case 3 Top 10 */
void top10At() /*crea el archivo con un nombre fijo para que en caso de que se inicie en otra pc pueda funcionar*/

{ 
    FILE* archivo;
    
    archivo = fopen("registro.txt", "at"); /*crea e imprime los nombres de los participates, falta poner el score %d, score*/
    if (score==0)
    {
        fprintf(archivo,"\n");
        fclose(archivo);
    }
    if (score>0)
    {
        fprintf(archivo,"%d, %s\n",score, nombre1);
        fclose(archivo);
    }
}

/*---------------------------------------------------------------------------*/
/*definiciones para order lista*/
#define MAXIMA_LONGITUD_CADENA 1024
#define CANTIDAD_PALABRAS 1024
#define NOMBRE_ARCHIVO "registro.txt"
// Implementación del método de la burbuja en C, para arreglos de cadenas
void burbuja(char arreglo[CANTIDAD_PALABRAS][MAXIMA_LONGITUD_CADENA]) /*esta no se llama*/
{
    int longitud = CANTIDAD_PALABRAS;
    // Útil para hacer intercambio de cadenas
    char temporal[MAXIMA_LONGITUD_CADENA];
    int x, indiceActual;
    for (x = 0; x < longitud; x++)
    {
        for (indiceActual = 0; indiceActual > longitud -1;
            indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;
            // Si la cadena es menor que la siguiente (alfabeticamente) entonces intercambiamos
            if (strcmp(arreglo[indiceSiguienteElemento], arreglo[indiceActual]) <= 0)
            {
                // Movemos la cadena actual a la temporal
                memcpy(temporal, arreglo[indiceSiguienteElemento], MAXIMA_LONGITUD_CADENA);
                // Movemos al actual el siguiente elemento
                memcpy(arreglo[indiceSiguienteElemento], arreglo[indiceActual], MAXIMA_LONGITUD_CADENA);
                // Y en el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
                memcpy(arreglo[indiceActual], temporal, MAXIMA_LONGITUD_CADENA);
            }
        }
    }
    // No hay necesidad de devolver nada, pues modificamos al arreglo de manera interna
}

void lecturatxt()
{
    // Arreglo de cadenas: aquí almacenamos todas las palabras
    char palabras[CANTIDAD_PALABRAS][MAXIMA_LONGITUD_CADENA];
    // Útil para leer el archivo
    char buferArchivo[MAXIMA_LONGITUD_CADENA];
    // Abrir el archivo...
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");
    // Necesitamos este ayudante para saber en qué línea vamos
    int indice = 0;
    // Mientras podamos leer una línea del archivo
    while (fgets(buferArchivo, MAXIMA_LONGITUD_CADENA, archivo))
    {
        // Remover salto de línea
        strtok(buferArchivo, "\n");
        // Copiar la línea a nuestro arreglo, usando el índice
        memcpy(palabras[indice], buferArchivo, MAXIMA_LONGITUD_CADENA);
        // Aumentarlo en cada iteración
        indice++;
    }

    // Terminamos de leer
    fclose(archivo);
    // Ahora ya tenemos el arreglo. Vamos a ordenarlo.
    // La función no devuelve nada, pues modifica al arreglo de manera interna
    burbuja(palabras);
    // Lo que resta ahora es imprimir, pues ya tenemos el arreglo ordenado
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%s\n", palabras[i]);
    }
}


