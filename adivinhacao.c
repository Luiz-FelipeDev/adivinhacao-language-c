#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   printf("********************************\n"); 
   printf("Bem-vindo ao Jogo da adivinhacao\n");
   printf("********************************\n");

    int segundos = time(0);
    srand(segundos); // Essa função é uma semente para a função rand()
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int tentativa = 0;
    double pontosganhados = 1000;
    double pontosperdidos;
    int numero_de_tentativas;
    int nivel;

    // Contruir aqui a lógica da escolha de nivel que ele(jogador) deseja
    printf("(1)Facil (2)Medio (3)Dificil\n");
    printf("Qual o nivel de dificuldade?\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case(1):
            numero_de_tentativas = 20;
            break;
        case(2):
            numero_de_tentativas = 15;
            break;
        default:
            numero_de_tentativas = 6;
            break;

    }

    for (tentativa=0; tentativa < numero_de_tentativas; tentativa++){
    
        //Número de Tentativas do Jogador
        printf("Tentativa %d", tentativa+1);
        printf("\n");

        // Entrada de Chute 
        int chute;
        printf("Digite o seu chute \n");
        scanf("%d", &chute);

        
        int acerto = (chute == numerosecreto);
        int maior = (chute > numerosecreto);
        //int menor = (chute < numerosecreto);


        if (acerto){
            printf("Parabens, Voce adivinhou o numero secreto na tentativa %d", tentativa+1);
        }
        else if (maior) {
            printf("O numero digitado e maior que o numero secreto\n");
        }
        else {
            printf("O numero digitado e menor que o numero secreto\n");
        }
        //Tratando pontuação do Jogador
        pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontosganhados = abs(pontosganhados - pontosperdidos);
    } 

    printf("Sua pontuação foi de %.2f", pontosganhados);
}
    
    