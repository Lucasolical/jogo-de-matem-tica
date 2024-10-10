#include<stdio.h>
//stdlib foi incluido para utilizar o rand(), exit e o system
#include<stdlib.h>
//time foi incluido para conseguir pegar uma matriz diferente em toda inicialização passando o horario do sistema para acrescentar ao rand
#include<time.h>
#define Tam 6
// tamanho da matriz de numeros
int V[Tam][Tam];
//variavel que vai decrescendo a cada erro, ao chegar em zero, o jogador perde
int errototal = 24;
//resposta do menu
int respM;
// validador que coloca o menu em looping caso as regras sejam chamadas
int contReg;
//função para criar uma matriz aleatoria com numeros menores que 10 e maiores que 0
void CriarMatriz();
//função para imprimir a matriz
int ImprimirMatriz();
int Menu();
//realização do jogo, maior parte do codigo 1-(escolha de linhas e colunas), 2-(escolha dos operadores), 3-(respostas)
int GamePlay();
int GameOver();
int Gamewin();


int main()
{
    //inicializa o validador em 0 para entrar no while
    int contReg = 0;
    while(contReg!=1)
    {
       //chama o menu
       Menu();
       //case 0 = sai do jogo
       //case 1 = inicia o jogo
       //case 2 = mostra as regras
       //respM é declarado no menu
       switch(respM)
    {
    case 2:
        {
            contReg = 0;
            system("cls");
            printf("\n                                      Iremos te apresentar uma tabela com 30 numeros.");
            printf("\n                 Seu objetivo sera escolher 2 numeros dessa tabela e fazer as contas disponiveis entre elas.");
            printf("\n                                  Voce tem 24 chances. Se as chances acabarem, voce perde.");
            printf("\n                 A escolha sera feita informando o numero de uma linha e de uma coluna, informado dentro dos ().\n\n");
            system("pause");
            system("cls");

            break;
        }
    case 1:
        {
            //ao escolher jogar o while termina com o reg = 1
            contReg = 1;
            system("cls");
            printf("\n\n\n         Entao vamos la.\n     Aqui esta a sua tabela.\n\n");
            CriarMatriz();
            ImprimirMatriz();
            GamePlay();
            break;
        }
    case 0:
        {
            contReg = 1;
            printf("\njogo encerrado\n");
            //encerra o jogo e retorna 1
            exit(EXIT_FAILURE);
            break;
        }

    }

    }

}
//Criar matriz gera a matriz aleatoria
void CriarMatriz()
{
    // i responsavel por criar a linha
    //j responsavel pela coluna
    int i,j;
    //passa o horario do sistema para o rand
    srand(time(NULL));
    for(i=0;i<Tam+1;i++)
    {
        for(j=0;j<Tam;j++)
        {
            //mod 9+1 para que o 9 seja incluido e o zero excluido
            V[i][j] = rand()%9+1;
        }
    }
}

int ImprimirMatriz()
{
    int i,j;
    //Criação da numeração da coluna
    //a primeira coluna foi printada separada por que o espaçamento entre a borda e a coluna é maior do que entre as colunas
    printf("     (0)");
    // Tam - 1 por que a primeira coluna ja foi adicionada
    for (i=0;i<Tam-1; i++)
        printf(" (%d)", i+1);
        printf("\n");
        printf("    -------------------------");
    //criação da linha (numeração e dados)
    for(i=0;i<Tam;i++)
    {
        //print do numeração da linha
        printf("\n(%d)-|",i);
        //print do dado da casa
        for(j=0;j<Tam;j++)
        {
            //condição para controlar a casa repetida (trasformo a casa ja usada em 0 e esse if pega a casa com 0 e transforma em vazio ' '
            if(V[i][j] == 0)
            {
                printf("   |");
            }
            // se não for 0 imprime o numero normal
            else
            printf(" %d |",V[i][j]);
        }
        printf("\n");
        printf("    -------------------------");

    }

}

int Menu()
{
    printf("\n                                            Bem Vindo ao Contar e Aprender.\n");
    printf("\n\n                              Digite 1 para JOGAR, 0 para SAIR e 2 para ver as REGRAS\n\n");
    scanf("%d",&respM);
}

int GamePlay()
{
    //variavel que vai confirmar o spoiler da resposta
    int spoiler;
    //variavel responsavel pela contagem de erros para o spoiler
    int erroparcial;
    //validação da operação
    int validope;
    //contador responsavel por sair do looping das operações
    int contope;
    // quando o jogador pede pra sair
    int saida;
    // quantidade de usos de operações
    int add = 5 ,sub = 4 ,div = 4,mult = 5;
    // resultados inteiros das contas
    int rsoma, rsub,rmult;
    // a divisão foi feita separada por necessitar muitas vezes de um numero quebrado(float)
    float rdiv;
    //resposta do jogador
    float userresp;
    //ope = variavel responsavel pela escolha da operação
    int ope;
    //variaveis da escolha da l = linha, c = coluna
    int l,c;
    //numb1 e 2 são os numeros que irão ser contados
    int numb1,numb2;
    int i;
    //escolha e apresentação dos numeros ate a vitoria
    for(i=0;i<18;i++)
    {
        //validador de casa ja escolhida
        int continvalid = 0;
        //validador de casa inexistente
        int contacert = 0;
        //looping que so libera se a casa não for repetida ou inexistente
        while(contacert == 0 || continvalid == 0)
        {
            printf("\ndigite a linha: ");
            scanf("%d",&l);

            printf("\nAgora digite uma coluna: ");
            scanf("%d",&c);
            // ao escolher a casa transforma ela em 0, ai vem o if se a casa for 0
            if(V[l][c]==0)
            {
                printf("essa casa ja foi escolhida, tente outra\n\n");
            }
            // se não for repetido libera uma parte do looping
            else
                continvalid = 1;
            //instrução para o usuario não escolher linha ou coluna acima de 5 ou abaixo de 0
            if(c > 5 || l > 5 || c < 0 || l < 0)
                {
                    printf("essa casa nao existe, tente outra\n\n");
                }
            //se não for inexistente libera outra parte do looping
            else
                contacert = 1;
        }


        printf("\nVoce escolheu o numero: (%d)\n\n",V[l][c]);
        //variavel para guardar o primeiro numero escolhido
        numb1 = V[l][c];
        //transforma a casa em 0
        V[l][c] = 0;
        system("pause");
        //repete o processo com o segundo numero
        continvalid = 0;
        contacert = 0;
        while(contacert == 0 || continvalid == 0)
        {
            printf("\ndigite outra linha: ");
            scanf("%d",&l);

            printf("\nAgora digite outra coluna: ");
            scanf("%d",&c);
            if(V[l][c]==0)
                printf("essa casa ja foi escolhida, tente outra\n\n");
            else
                continvalid = 1;
            if(c > 5 || l > 5 || c < 0 || l < 0)
                    printf("essa casa nao existe, tente outra\n\n");
            else
                contacert = 1;

        }
        printf("\nVoce escolheu o numero: (%d)\n\n",V[l][c]);
        numb2= V[l][c];
        V[l][c] = 0;
        system("pause");
        system("cls");
        //apresenta os numeros escolhidos
        printf("\nSeus numeros sao (%d) e (%d)\n\n", numb1, numb2);
        //criação das respostas das operações entre eles
        rsoma =  numb1 + numb2;
        rsub = numb1 - numb2;
        rdiv =(float) numb1 / numb2;
        rmult = numb1 * numb2;
        //escolha e apresentação das operações
        printf("\nAgora escolha uma operacao digitando o numero correspondente\n\n(Lembrando que cada operacao tem uma quantidade limite de uso):\n\n[0] = Adicao(+) (%dx)\n\n[1] = Subtracao(-)  (%dx) \n\n[2] = Divisao(/)  (%dx)\n\n[3] = Multiplicacao(x)  (%dx)\n\n", add, sub, div, mult);
        //looping das operações
        contope = 0;
        //limite de operação atingido
        validope = 0;
        //looping validador da resposta (escolhi -10 porque é um valor impossivel para a situação) se o valor manter -10 ele não sai do looping, se o usuario acertar, o userresp passa a ser o resultado
        userresp = -10;
        //ativador do spoiler (aumenta a cada erro e ativa o spoiler quando chegar a 3)
        erroparcial = 0;

        while(contope == 0)
        {
            // looping para ver se a casa respectiva do case ja atingiu o limite de vezes usadas
            while(validope==0)
            {
                scanf("%d", &ope);
                if(ope == 0 && add == 0)
                {
                    printf("Voce ja atingiu o limite dessa operação, escolha outra:\n");
                }
                if(ope == 1 && sub == 0)
                {
                    printf("Voce ja atingiu o limite dessa operação, escolha outra:\n");
                }
                if(ope == 2 && div == 0)
                {
                    printf("Voce ja atingiu o limite dessa operação, escolha outra:\n");
                }
                if(ope == 3 && mult == 0)
                {
                    printf("Voce ja atingiu o limite dessa operação, escolha outra:\n");
                }
                if(ope == 0 && add !=0 || ope == 1 && sub != 0 || ope == 2 && div != 0 || ope == 3 && mult != 0)
                    validope = 1;
            }
            //operações disponiveis no case vão de 0 a 3, se o numero estiver fora ele repete e imprime mensagem do else
            if(ope >= 0 && ope<=3)
            {
                //ao entrar na area do switch, ja libera do looping inicial das operações
                contope = 1;
                switch(ope)
                {
                    case 0:
                    {
                        //diminui a quantidade de usos de soma
                        add = add - 1;
                        printf("Voce escolheu a soma. \n\nQual vc acha que sera a resposta?\nVoce tem %d chances\nR: ",errototal);
                        while(userresp == -10)
                        {
                            //pergunta e resposta da opção do spoiler caso tenha errado 3 vezes
                            if(erroparcial == 3)
                            {
                                printf("\nvoce gostaria de saber a resposta?\n1 para sim e 0 para não\n");
                                scanf("%d", &spoiler);
                                if(spoiler == 1)
                                {
                                    printf("%d\ntente de novo:",rsoma);
                                }
                            }
                            scanf("%f",&userresp);
                            if(userresp == rsoma)
                            {
                                printf("acertou\n\n");
                                //pergunta e resposta da saida no meio do jogo
                                printf("\nDeseja continuar?\n[1] = sim \n[outro] = nao\nR:");
                                scanf("%d", &saida);
                                if(saida != 1)
                                {

                                    GameOver();
                                }
                            }
                            //caso de erro da resposta
                            else
                            {
                                errototal = errototal - 1;
                                //caso erro total chegue a 0 dá game over
                                if(errototal == 0)
                                GameOver();
                                printf("errou, tente de novo: ");
                                printf("\n(%d chances)\nR: ",errototal);
                                //caso ele erre a resposta volta a ser -10
                                userresp = -10;
                                //aumenta a condição de spoiler
                                erroparcial = erroparcial + 1;
                            }

                        }

                        system("pause");
                        system("cls");
                        break;
                    }
                    case 1:
                    {
                        //diminui a quantidade de usos de subtração
                        sub = sub - 1;
                        printf("Voce escolheu a subtracao. \n\nQual vc acha que sera a resposta?\nVoce tem %d chances\nR: ",errototal);
                        while(userresp == -10)
                        {
                            if(erroparcial == 3)
                            {
                                printf("\nvoce gostaria de saber a resposta?\n1 para sim e 0 para não\n");
                                scanf("%d", &spoiler);
                                if(spoiler == 1)
                                {
                                    printf("%d\ntente de novo:",rsub);
                                }

                            }
                            scanf("%f",&userresp);
                            if(userresp == rsub)
                            {
                                printf("acertou\n\n");
                                printf("\nDeseja continuar?\n[1] = sim \n[outro] = nao\nR:");
                                scanf("%d", &saida);
                                if(saida != 1)
                                {

                                    GameOver();
                                }
                            }
                            else
                            {
                                errototal = errototal - 1;
                                if(errototal == 0)
                                GameOver();
                                printf("errou, tente de novo: ");
                                printf("\n(%d chances)\nR: ",errototal);
                                userresp = -10;
                                erroparcial = erroparcial + 1;
                            }
                        }
                    system("pause");
                    system("cls");
                    break;
                    }
                    case 2:
                    {
                        //diminui a quantidade de usos da divisão
                        div = div - 1;
                        printf("Voce escolheu a divisao. \n\nQual vc acha que sera a resposta?\nVoce tem %d chances\nR: ",errototal);
                        while(userresp == -10)
                        {
                            if(erroparcial == 3)
                            {
                                printf("\n\nvoce gostaria de saber a resposta?\n1 para sim e 0 para não\n");
                                scanf("%d", &spoiler);
                                if(spoiler == 1)
                                {
                                    printf("%f\ntente de novo:",rdiv);
                                }
                            }
                            scanf("%f",&userresp);
                            if( rdiv - userresp <= 0.09 && rdiv - userresp >= -0.09)
                            {
                                printf("acertou\n\n");
                                printf("\nDeseja continuar?\n[1] = sim \n[outro] = nao\nR:");
                                scanf("%d", &saida);
                                if(saida != 1)
                                {

                                    GameOver();
                                }
                            }
                            else
                            {
                                errototal = errototal - 1;
                                if(errototal == 0)
                                GameOver();
                                printf("errou, tente de novo: ");
                                printf("\n(%d chances)\nR: ",errototal);
                                userresp = -10;
                                erroparcial = erroparcial + 1;
                            }

                        }

                        system("pause");
                        system("cls");
                        break;
                    }
                    case 3:
                    {
                        //diminui a quantidade de usos da multiplicação
                        mult = mult - 1;
                        printf("Voce escolheu a multiplicacao. \n\nQual vc acha que sera a resposta?\nVoce tem %d chances\nR: ",errototal);
                        while(userresp == -10)
                        {
                            if(erroparcial == 3)
                            {
                                printf("\nvoce gostaria de saber a resposta?\n1 para sim e 0 para não\n");
                                scanf("%d", &spoiler);
                                if(spoiler == 1)
                                {
                                    printf("%d\ntente de novo:",rmult);
                                }
                            }
                            scanf("%f",&userresp);
                            if(userresp == rmult)
                            {
                                printf("acertou\n\n");
                                printf("\nDeseja continuar?\n[1] = sim \n[outro] = nao\nR:");
                                scanf("%d", &saida);
                                if(saida != 1)
                                {

                                    GameOver();
                                }
                            }
                            else
                            {
                                errototal = errototal - 1;
                                if(errototal == 0)
                                GameOver();
                                printf("errou, tente de novo: ");
                                printf("\n(%d chances)\nR: ",errototal);
                                userresp = -10;
                                erroparcial = erroparcial + 1;

                            }
                        }

                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }
            else
                printf("numero invalido, tente outro\n");
        }
        //ao terminar a primeira rodada imprime a matriz de novo, agora com as atualizações nela
        ImprimirMatriz();
    }
    //se acabar o looping, vem para a condição de vitoria
    Gamewin();
}

int GameOver()
{
    printf("\nVoce perdeu. Todas as suas chances acabaram\n                    [F]");
    exit(EXIT_FAILURE);
}
int Gamewin()
{
    printf("\n\n\nPARABENS VOCE ELIMINOU TODOS OS NUMEROS.\n\n        VITORIA MEU CONSAGRADO!\n");
    exit(EXIT_SUCCESS);
}
