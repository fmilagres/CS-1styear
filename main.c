#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<locale.h>
#include<math.h>
#include<string.h>]
#include<time.h>



int main(void)
{
    setlocale(LC_ALL,"");

    //Definição de variáveis e ponteiros//
    FILE *ponteiroarq;
    int i, j, t, lci, _lci, lcj, _lcj, l1i, _l1i, l1j, _l1j, l2i, _l2i, l2j, _l2j, l3i, _l3i, l3j, _l3j, lfi, _lfi, lfj, _lfj, qtd, ind, obst, oi, oj;
    char texto[20];
    char *mat[11][11][2];
    int str[2][100];

    printf("\t\tPASSEIO DA MINHOCA DESGOVERNADA\n\n");
    printf("\tNeste programa, a minhoca caminha aleatoriamente na vertical e horizontal em um tabuleiro 10x10.\n");
    printf("Para definir a posição inicial da cabeça da minhoca, como a quantidade de movimentos, quantidade de obs-\n");
    printf("táculos e suas respectivas posições, você deve abrir 'arquivo.txt', localizado na mesma pasta do progra-,\n");
    printf("ma, para configurar esses dados iniciais.\n");
    printf("\n\tDefinida a posição da cabeça, o restante do corpo é posicionado a esquerda. Então cuidado para não \n");
    printf("sobrepor obstáculos.");
    printf("\n\nFeito isso, aperte qualquer tecla para continuar");
    getch();


    for (i=1;i<11;++i)
    {
        for(j=1;j<11;++j)
        {
            mat[i][j][0]=" ";

        }
        printf("\n");
    }

    //Abrindo e testando o arquivo//
    ponteiroarq = fopen("arquivo.txt","r");

    if (ponteiroarq == NULL)
    {
        printf("Erro na Leitura!");
        system("pause");
        exit(1);
    }

    //Leitura do arquivo//
    fscanf(ponteiroarq,"%s %s %s %i",texto,texto,texto,&lci);
    fscanf(ponteiroarq,"%s %s %s %i",texto,texto,texto,&lcj);
    fscanf(ponteiroarq,"%s %s %s %i",texto,texto,texto,&qtd);
    fscanf(ponteiroarq,"%s %s %s %i",texto,texto,texto,&obst);
    fscanf(ponteiroarq,"%s %s %s %s",texto,texto,texto,texto);

    for (t=0;t<obst;t++)
    {
    fscanf(ponteiroarq,"%i %i",&str[0][t],&str[1][t]);
    oi=str[0][t];
    oj=str[1][t];
    mat[oi][oj][0]="x";
    }

    //posicionar minhoca//
    if (mat[lci][lcj][0]=="x")
    {
      printf("Cabeça da minhoca sobrepondo obstáculo. Por favor, escolha outras posições!!\n");
      exit(1);
    }

    //posicionando o primeiro corpo//
    if (lcj-1==0 || mat[lci][lcj-1][0]=="x")
        {
            if(lci+1==11 || mat[lci+1][lcj][0]=="x")
            {
            l1i=lci-1;
            l1j=lcj;
            }
            else
            {
                if (mat[lci][lcj+1][0]=="x")
                printf("Minhoca sobrepondo obstáculo! Por favor, escolha outras posições.");
                else
                {
                    l1i=lci+1;
                    l1j=lcj;
                }

            }
        }
    else
    {
        l1i=lci;
        l1j=lcj-1;
    }
    //posicionando o segundo corpo//
    if (l1j-1==0)
        {
            if(l1i+1==11)
            {
            l2i=l1i-1;
            l2j=l1j;
            }
            else
            {
            l2i=l1i+1;
            l2j=l1j;
            }
        }
    else
    {
        l2i=l1i;
        l2j=l1j-1;
    }
//posicionando o terceiro corpo//
    if (l2j-1==0)
        {
            if(l2i+1==11)
            {
            l3i=l2i-1;
            l3j=l2j;
            }
            else
            {
            l3i=l2i+1;
            l3j=l2j;
            }
        }
    else
    {
        l3i=l2i;
        l3j=l2j-1;
    }
    if (lcj<3)
        {
            l3i=l2i;
            l3j=l2j+1;
        }
    //posicionando a cauda//
    if (l3j-1==0)
        {
            if(l3i+1==11)
            {
            lfi=l3i-1;
            lfj=l3j;
            }
            else
            {
            lfi=l3i+1;
            lfj=l3j;
            }
        }
    else
    {
        lfi=l3i;
        lfj=l3j-1;
    }
    //refazendo a cauda para caso a minhoca esteja nos limites do tabuleiro//
    if (lcj<4)
    {
        lfi=l3i;
        lfj=l3j+1;
    }

//conteúdo/layout da minhoca//
    mat[lci][lcj][0]="C";
    mat[l1i][l1j][0]="*";
    mat[l2i][l2j][0]="*";
    mat[l3i][l3j][0]="*";
    mat[lfi][lfj][0]=".";

    //Exibir tabuleiro//

    for (i=1;i<11;++i)
    {
        for(j=1;j<11;++j)
        {
            printf("[  %s  ]",mat[i][j][0]);

        }
        printf("\n");
    }
printf("\n");




    //sorteio para onde a cabeça segue//
    for (t=0;t<qtd;t++)
    {
        srand( (unsigned)time(NULL) );
        ind=(rand()%4+1);

        //movimentar minhoca continuar aqui para cada ind//

        //movimento 1//
        if (ind==1)
        {
                if(lci-1==0 || mat[lci-1][lcj][0]=="x" || mat[lci-1][lcj][0]=="*" || mat[lci-1][lcj][0]==".")
                {
                t--;
                }
                else
                {
                    mat[lfi][lfj][0]=" ";
                    _lci=lci-1;
                    _l1i=lci;
                    _l1j=lcj;
                    _l2i=l1i;
                    _l2j=l1j;
                    _l3i=l2i;
                    _l3j=l2j;
                    _lfi=l3i;
                    _lfj=l3j;

                    lci=_lci;
                    l1i=_l1i;
                    l1j=_l1j;
                    l2i=_l2i;
                    l2j=_l2j;
                    l3i=_l3i;
                    l3j=_l3j;
                    lfi=_lfi;
                    lfj=_lfj;

                    mat[lci][lcj][0]="C";
                    mat[l1i][l1j][0]="*";
                    mat[l2i][l2j][0]="*";
                    mat[l3i][l3j][0]="*";
                    mat[lfi][lfj][0]=".";



    //Exibir tabuleiro//

    for (i=1;i<11;++i)
    {
        for(j=1;j<11;++j)
        {
            printf("[  %s  ]",mat[i][j][0]);

        }
        printf("\n");
    }
    printf("\n");
    }}


    //movimento 2//
    if (ind==2)
        {
                if(lcj+1==11 || mat[lci][lcj+1][0]=="x" || mat[lci][lcj+1][0]=="*" || mat[lci][lcj+1][0]==".")
                {
                t--;

                }
                else
                {
                    mat[lfi][lfj][0]=" ";
                    _lcj=lcj+1;
                    _l1i=lci;
                    _l1j=lcj;
                    _l2i=l1i;
                    _l2j=l1j;
                    _l3i=l2i;
                    _l3j=l2j;
                    _lfi=l3i;
                    _lfj=l3j;

                    lcj=_lcj;
                    l1i=_l1i;
                    l1j=_l1j;
                    l2i=_l2i;
                    l2j=_l2j;
                    l3i=_l3i;
                    l3j=_l3j;
                    lfi=_lfi;
                    lfj=_lfj;

                    mat[lci][lcj][0]="C";
                    mat[l1i][l1j][0]="*";
                    mat[l2i][l2j][0]="*";
                    mat[l3i][l3j][0]="*";
                    mat[lfi][lfj][0]=".";



    //Exibir tabuleiro//

    for (i=1;i<11;++i)
    {
        for(j=1;j<11;++j)
        {
            printf("[  %s  ]",mat[i][j][0]);

        }
        printf("\n");
    }
    printf("\n");




    }}

    //movimento 3//
    if (ind==3)
        {
                if(lci+1==11 || mat[lci+1][lcj][0]=="x" || mat[lci+1][lcj][0]=="*" || mat[lci+1][lcj][0]==".")
                {
                t--;

                }
                else
                {
                    mat[lfi][lfj][0]=" ";
                    _lci=lci+1;
                    _l1i=lci;
                    _l1j=lcj;
                    _l2i=l1i;
                    _l2j=l1j;
                    _l3i=l2i;
                    _l3j=l2j;
                    _lfi=l3i;
                    _lfj=l3j;

                    lci=_lci;
                    l1i=_l1i;
                    l1j=_l1j;
                    l2i=_l2i;
                    l2j=_l2j;
                    l3i=_l3i;
                    l3j=_l3j;
                    lfi=_lfi;
                    lfj=_lfj;

                    mat[lci][lcj][0]="C";
                    mat[l1i][l1j][0]="*";
                    mat[l2i][l2j][0]="*";
                    mat[l3i][l3j][0]="*";
                    mat[lfi][lfj][0]=".";



    //Exibir tabuleiro//

    for (i=1;i<11;++i)
    {
        for(j=1;j<11;++j)
        {
            printf("[  %s  ]",mat[i][j][0]);

        }
        printf("\n");
    }
    printf("\n");




    }}
//movimento 4//
    if (ind==4)
        {
                if(lcj-1==0 || mat[lci][lcj-1][0]=="x" || mat[lci][lcj-1][0]=="*" || mat[lci][lcj-1][0]==".")
                {
                t--;

                }
                else
                {
                    mat[lfi][lfj][0]=" ";
                    _lcj=lcj-1;
                    _l1i=lci;
                    _l1j=lcj;
                    _l2i=l1i;
                    _l2j=l1j;
                    _l3i=l2i;
                    _l3j=l2j;
                    _lfi=l3i;
                    _lfj=l3j;

                    lcj=_lcj;
                    l1i=_l1i;
                    l1j=_l1j;
                    l2i=_l2i;
                    l2j=_l2j;
                    l3i=_l3i;
                    l3j=_l3j;
                    lfi=_lfi;
                    lfj=_lfj;

                    mat[lci][lcj][0]="C";
                    mat[l1i][l1j][0]="*";
                    mat[l2i][l2j][0]="*";
                    mat[l3i][l3j][0]="*";
                    mat[lfi][lfj][0]=".";



    //Exibir tabuleiro//

    for (i=1;i<11;++i)
    {
        for(j=1;j<11;++j)
        {
            printf("[  %s  ]",mat[i][j][0]);

        }
        printf("\n");
    }
    printf("\n");




    }}
    }

    printf("Linha da posição da cabeça: %i \nColuna da posição da cabeça: %i\n", lci, lcj);
    printf("Número de casas visitadas: %i\nNúmero de casas não visitadas: %i\n", qtd+1, 100-(qtd+1));
    printf("Quantidade de obstáculos: %i\n\n",obst);


    fclose(ponteiroarq);

    return(0);

}
