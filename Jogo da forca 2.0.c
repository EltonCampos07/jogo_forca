#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "desenho_forca.c"

void imprimir (int i){
    int cont, aux;
    cont = i;

    for (aux = 0; aux<cont; aux++){
        printf (" _ ");
    }
}

int main (){
    
    char palavra [30][21] = {"ESPINAFRE", "CEREAIS", "VEGETAIS", "MORANGO", "CAQUI", "CEREJA", 
    "ABOBRINHA", "CARNE", "COGUMELO", "LARANJA", "OSSO", "COXA", "QUADRIL", "OMBRO", 
    "OUVIDO", "CALCANHAR", "UNHA", "SANGUE", "MENTE", "CABECA", "COBRA", "PORCO", "POLVO", 
    "VEADO", "ARRAIA", "POMBA", "PAPAGAIO", "CHAMA", "BALEIA", "CHITA"}, palavra2[20];
    int  x, cont = 0, vidas = 0, i = 0, aux, acertos;
    char op, letra;

    setbuf(stdout, NULL);
    srand(time(0));

    printf ("Jogo da forca - 2.0\n\n");
    printf ("Objetivo do jogo: descubra a palavra secreta e evitar perder suas vidas.\n");
    printf ("Voce tem 6 tentativas para descobrir qual palavra eh.\n\n");

    // Nessa etapa: programa gera um número aleatório. Esse número indica qual palavra será escolhida para 1 partida do jogo.

    x = rand()%30;

    // Aqui nessa etapa eu conto quantas letra tem a palavra sorteada
    i = strlen (palavra[x]);
    // Chamo a função para imprimir o tamanho da palavra no qual será apresentado ao jogador por ' _ '
    imprimir (i);
    //Atualizo a variável responsável por contar quantas jogadas já foram
    cont++;
   
    //laço principal do jogo.
    //Há duas situações que param o laço: o limite máximo de jogadas (o valor foi definido como 30) e caso o jogador escolha a opção 'N' de não continuar jogando.

    do{
            //A ideia dessa string é armazenar as letras digitadas pela jogador 
            //O tamanho dessa string sempre mudará conforme uma nova palavra é estabelecida

            for (aux = 0; aux<i; aux++ ){
                palavra2[aux] = '_';
            }

            //laço da jogada atual.
            //Há duas situações que param o laço: se a vida do jogador chegar a zero ou se ele acertar todas as letras da palavra sorteada.

            do{
                
                //variável auxiliar para contar quantas vezes a letra digitada pelo usário aparece na palavra da string
                acertos = 0;

                //Entrada de dados. Só é aceito se respeitar as condições estabelecidas

                do{
                    printf ("\n\ndigite uma letra (somente letras maiuscula sao aceitas):\n");
                    scanf (" %c", &letra);
                    if (letra < 'A' || letra > 'Z'){
                        printf ("Erro: letra nao aceita!\n");
                    }
                }while (letra < 'A' || letra > 'Z');

                printf ("\n");

                //Caso a letra digitado aparecer na string o valor da variável acertos será atualizados

                for (aux = 0; palavra [x][aux] != '\0'; aux++){
                    if (palavra[x][aux] == letra){
                        acertos++;
                    }
                }

                //Se o valor da variável acertos for diferente de zero: o jogador acertou e as posição da string correspondente a letra é atualizado

                if(acertos > 0){
                    for(aux = 0; palavra [x][aux] != '\0'; aux++){
                        if (palavra2[aux] == '_' && palavra[x][aux] == letra){
                            palavra2[aux] = letra;
                            i --;
                        }
                    printf (" %c ", palavra2[aux]);
                    }
                }

                //Se o valor da variável acertos for igual a zero: o jogador errou e ele perde vidas (é apresentado o bonequinho na forca)

                if (acertos == 0){
                    vidas ++;
                    desenho (vidas);
                }

            }while (vidas!=6 && i != 0);

        // Se "I" chegar a zero: o jogador acertou todas as letras da palavra. Portanto, ele venceu.

        if (i == 0){
            printf ("\n\nParabens! Voce escapou com vida!\n");
        }

        // Se a variável vidas for igual 6: o jogador zerou todas suas tentativas, ou seja, fim de jogo.

        if (vidas == 6){
            printf ("\n\nVoce morreu!\n");
        }

        //O programa pergunta se o jogador que jogar novamente

        printf ("\nVoce quer continuar? S - Sim e N - Nao\n");
        scanf (" %c", &op);

        //Nesta etapa o programa deixa preparado as condições para próxima rodada (se caso o jogador desejar continuar jogando)
        // Ele reseta a variável vida e ele muda a palavra (assim garante que nunca a palavra será repetida durante as jogadas)
        
        if (op != 'N' && op != 'n'){

            vidas = 0;
            
            if (x!=29 && cont<=30){
                // Atualiza o valor de 'X', ou seja, nova palavra para próxima jogada
                x++;
                //Atualizo a variável responsável por contar quantas jogadas já foram
                cont++;
                // Aqui nessa etapa eu conto quantas letra tem a palavra nova
                i = strlen (palavra[x]);
                // Chamo a função para imprimir o tamanho da palavra no qual será apresentado ao jogador por ' _ '
                imprimir (i);
                }else{
                    //Caso o valor de 'X' ultrapassa o valor 29, ele reseta para '0' 
                    x = 0;
                    //Atualizo a variável responsável por contar quantas jogadas já foram
                    cont++;
                    // Aqui nessa etapa eu conto quantas letra tem a palavra nova
                    i = strlen (palavra[x]);
                    // Chamo a função para imprimir o tamanho da palavra no qual será apresentado ao jogador por ' _ '
                    imprimir (i);
                }
            }

    }while((op != 'N' && op != 'n') && cont<=30);
    
    return EXIT_SUCCESS;
}