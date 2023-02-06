#include <stdio.h>
#include <math.h>
void imprimirmatriz(char matriz[10][10]){

    int x=0;

    printf("   0\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\n ..........................................................................\n");

    for(int i2=0;i2<10;i2++){
        printf("%d:",x);

        for(int j2=0;j2<10;j2++){
            printf("|%c|\t",matriz[i2][j2]);

        }
        printf("\n");
        x=x+1;

    }
}

char *destroyer(char nav[10][10]){

    int z=0,i2=0,j2=0;

    z=rand()%2; // Variavel que decide se vai ficar na horizontal ou vertical (0 horizontal, 1 vertical)

    if(z==0) {
        i2=rand()%10;
        j2=rand()%7;

    }else if(z==1) {
        i2=rand()%7;
        j2=rand()%10;

    }

    for(int i=0;i<4;i++){ // Imprimir os navios designados (neste caso o destroyer, 4 casas)

        nav[i2][j2]= 'W';

        if(z==0){
            j2=j2+1;

        }else{
            i2=i2+1;

        }
    }
    return &(nav[0][0]);
}

char *naviomedio(char nav[10][10]){



    int z=0,i2=0,j2=0,x=0,y=0;

    z=rand()%2;

    if(z==0) {
        i2=rand()%10;
        j2=rand()%8;

        while (x < 4) {

            if (nav[i2][j2 + x] == 'W' || nav[i2 + 1][j2+x] == 'W' || nav[i2][j2 - x] == 'W' || nav[i2 - 1][j2+x] == 'W'){ // condição para não nascer um navio do lado do outro, sendo x para mexer nas colunas e y para as linhas)

                i2=rand()%10;
                j2=rand()%8;
                x=0;

            }else{
                x=x+1;

            }
        }

    }else {
        i2=rand()%8;
        j2=rand()%10;

        while (y < 4) {

            if (nav[i2 + y][j2 + 1] == 'W' || nav[i2 + y][j2] == 'W' || nav[i2 + y][j2 - 1] == 'W' || nav[i2 - y][j2] == 'W') {
                i2=rand()%8;
                j2=rand()%10;
                y=0;

            }else{
                y=y+1;
            }
        }
    }

    for(int i=0;i<3;i++){

        nav[i2][j2]= 'W';

        if(z==0){
            j2=j2+1;

        }else{
            i2=i2+1;

        }
    }
    return &(nav[0][0]);
}

char *navio(char nav[10][10]){

    int z=0,i2=0,j2=0, x=0,y=0;
    z=rand()%2;

    if(z==0) {
        i2=rand()%10;
        j2=rand()%9;

        while ( x < 3) {

            if (nav[i2][j2 + x] == 'W' || nav[i2 + 1][j2 + x] == 'W' || nav[i2][j2 - x] == 'W' || nav[i2 - 1][j2 + x] == 'W') {

                i2=rand()%10;
                j2=rand()%9;
                x=0;

            }else{
                x=x+1;
            }
        }
    }else {
        i2=rand()%9;
        j2=rand()%10;

        while (y < 3) {
            if (nav[i2 + y][j2 + 1] == 'W' || nav[i2 + y][j2] == 'W' || nav[i2 + y][j2 - 1] == 'W' || nav[i2 - y][j2] == 'W') {
                i2=rand()%9;
                j2=rand()%10;
                y=0;

            }else{
                y=y+1;
            }
        }
    }
    for(int i=0;i<2;i++){

        nav[i2][j2]= 'W';

        if(z==0){

            j2=j2+1;

        }else{

            i2=i2+1;
        }
    }
    return &(nav[0][0]);
}

char *naviopequeno(char nav[10][10]){
    int i2=0,j2=0;
    i2=rand()%10;
    j2=rand()%10;

    while (nav[i2][j2] == 'W' || nav[i2][j2 + 1] == 'W' || nav[i2 + 1][j2] == 'W' || nav[i2][j2 - 1] == 'W' || nav[i2 - 1][j2] == 'W') {
        j2 = rand() % 10;
        i2 = rand() % 10;
    }

    nav[i2][j2]= 'W';
    return &(nav[0][0]);
}

clrscr(){
    system("@cls||clear");
}

int main(){

    char nav [10][10], bat[10][10]; //nav = matriz referencial, bat = matriz do jogo (do usuario)
    int naviosabatidos=0,linha=0,coluna=0,z=0;

    srand(time(NULL));

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            nav[i][j]='_';
            bat[i][j]='_';
            if (i==0){
                nav[i-1][j]='_';
            }
            if (j==0){
                nav[i][j-1]='_';
            }
        }
    }

    imprimirmatriz(bat);
    destroyer(nav);
    naviomedio(nav);
    naviomedio(nav);
    navio(nav);
    for(int i=0;i<5;i++) {
        naviopequeno(nav);
    }

    //teste
    //imprimirmatriz(nav);

    int aux=0;

    for(int i=0;i<25;i++){
        printf("\nDigite a linha e a coluna do ataque: ");
        scanf("%d%d",&linha,&coluna);

        if (nav[linha][coluna]=='W'){
            bat[linha][coluna]='X';
            clrscr();
            imprimirmatriz(bat);
            naviosabatidos=naviosabatidos+1;

        }else{
            bat[linha][coluna]='O';
            clrscr();
            imprimirmatriz(bat);

        }
        if(naviosabatidos==17){

            clrscr();
            imprimirmatriz(bat);
            printf("Parabens, voce ganhou");
            i=25;
            z=1;

        }
    }
    if(z==0){
        clrscr();
        imprimirmatriz(bat);
        printf("Voce perdeu");
    }
    return 0;
}
