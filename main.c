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

    //Defini��o de vari�veis e ponteiros//
    FILE *ponteiroarq;
    int i, j, t, lci, _lci, lcj, _lcj, l1i, _l1i, l1j, _l1j, l2i, _l2i, l2j, _l2j, l3i, _l3i, l3j, _l3j, lfi, _lfi, lfj, _lfj, qtd, ind, obst, oi, oj;
    char texto[20];
    char *mat[11][11][2];
    int str[2][100];

    printf("\t\tPASSEIO DA MINHOCA DESGOVERNADA\n\n");
    printf("\tNeste programa, a minhoca caminha aleatoriamente na vertical e horizontal em um tabuleiro 10x10.\n");
    printf("Para definir a posi��o inicial da cabe�a da minhoca, como a quantidade de movimentos, quantidade de obs-\n");
    printf("t�culos e suas respectivas posi��es, voc� deve abrir 'arquivo.txt', localizado na mesma pasta do progra-,\n");
    printf("ma, para configurar esses dados iniciais.\n");
    printf("\n\tDefinida a posi��o da cabe�a, o restante do corpo � posicionado a esquerda. Ent�o cuidado para n�o \n");
    printf("sobrepor obst�culos.");
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
      printf("Cabe�a da minhoca sobrepondo obst�culo. Por favor, escolha outras posi��es!!\n");
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
                printf("Minhoca sobrepondo obst�culo! Por favor, escolha outras posi��es.");
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

//conte�do/layout da minhoca//
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




    //sorteio para onde a cabe�a segue//
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

    printf("Linha da posi��o da cabe�a: %i \nColuna da posi��o da cabe�a: %i\n", lci, lcj);
    printf("N�mero de casas visitadas: %i\nN�mero de casas n�o visitadas: %i\n", qtd+1, 100-(qtd+1));
    printf("Quantidade de obst�culos: %i\n\n",obst);


    fclose(ponteiroarq);

    return(0);

}
