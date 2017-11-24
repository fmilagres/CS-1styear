Algoritmo "Escalonamento"
// Disciplina  :  Algebra Linear
// Professor   : Maurício
// Descrição   : Programa escalona uma matriz 3x3 pelo método de Gauss Jordan
// Autor(a)    : Fernanda Colonezi Milagres
// Data atual  : 28/09/2017
Var
m: vetor[1..3,1..4] de real
v: vetor[1..3] de real
i,j: inteiro
Inicio


para i de 1 ate 3 faca          //leitura da matriz//
     para j de 1 ate 4 faca
          leia(m[i,j])
     fimpara
fimpara
//coluna 1//
se (m[1,1]=0) entao             //verificação de elementos nulos//
   se (m[2,1]=0) entao
      para j de 1 ate 4 faca    //troca linhas 1 e 3//
           v[j]<-m[3,j]
           m[3,j]<-m[1,j]
           m[1,j]<-v[j]
      fimpara
   senao
        para j de 1 ate 4 faca  //troca linhas 1 e 2//
             v[j]<-m[2,j]
             m[2,j]<-m[1,j]
             m[1,j]<-v[j]
        fimpara
   fimse
fimse
v[1]<-m[1,1]
para j de 1 ate 4 faca          //divide toda linha para achar o 1° pivot//
     m[1,j]<-m[1,j]/v[1]
fimpara
v[2]<-m[2,1]
v[3]<-m[3,1]

se (m[1,1]>0) entao //verifica os sinais linhas 1 e 2, multiplica e substitui//
   se(m[2,1]>0) entao
                para j de 1 ate 4 faca
                     m[2,j]<-(-v[2])*m[1,j]+m[2,j]
                fimpara
   senao
        para j de 1 ate 4 faca
             m[2,j]<-(-v[2])*m[1,j]+m[2,j]
        fimpara
   fimse

senao
     se (m[2,1]<0) entao
        para j de 1 ate 4 faca
             m[2,j]<-(-v[2])*m[1,j]+m[2,j]
        fimpara
     senao
          para j de 1 ate 4 faca
               m[2,j]<-(v[2])*m[1,j]+m[2,j]
          fimpara
     fimse
fimse

     



se (m[1,1]>0) entao //verifica os sinais linhas 1 e 3, multiplica e substitui//
   se(m[3,1]>0) entao
                para j de 1 ate 4 faca
                     m[3,j]<-(-v[3])*m[1,j]+m[3,j]
                fimpara
   senao
        para j de 1 ate 4 faca
             m[3,j]<-(-v[3])*m[1,j]+m[3,j]
        fimpara
   fimse

senao
     se (m[3,1]<0) entao
        para j de 1 ate 4 faca
             m[3,j]<-(-v[3])*m[1,j]+m[3,j]
        fimpara
     senao
          para j de 1 ate 4 faca
               m[3,j]<-(v[3])*m[1,j]+m[3,j]
          fimpara
     fimse
fimse

//coluna 2//
se (m[2,2]=0) entao             //verificação de elementos nulos//
   se (m[3,2]!=0) entao
      para j de 1 ate 4 faca    //troca linhas 2 e 3//
           v[j]<-m[3,j]
           m[3,j]<-m[2,j]
           m[2,j]<-v[j]
      fimpara
   fimse
fimse
v[2]<-m[2,2]
para j de 1 ate 4 faca          //divide toda linha para achar o 2° pivot//
     m[2,j]<-m[2,j]/v[2]
fimpara
v[1]<-m[1,2]
v[3]<-m[3,2]

se (m[2,2]>0) entao //verifica os sinais linhas 2 e 1, multiplica e substitui//
   se(m[1,2]>0) entao
                para j de 1 ate 4 faca
                     m[1,j]<-(-v[1])*m[2,j]+m[1,j]
                fimpara
   senao
        para j de 1 ate 4 faca
             m[1,j]<-(-v[1])*m[2,j]+m[1,j]
        fimpara
   fimse

senao
     se (m[1,2]<0) entao
        para j de 1 ate 4 faca
             m[1,j]<-(-v[1])*m[2,j]+m[1,j]
        fimpara
     senao
          para j de 1 ate 4 faca
               m[1,j]<-(v[1])*m[2,j]+m[1,j]
          fimpara
     fimse
fimse

se (m[2,2]>0) entao //verifica os sinais linhas 2 e 3, multiplica e substitui//
   se(m[3,2]>0) entao
                para j de 1 ate 4 faca
                     m[3,j]<-(-v[3])*m[2,j]+m[3,j]
                fimpara
   senao
        para j de 1 ate 4 faca
             m[3,j]<-(-v[3])*m[2,j]+m[3,j]
        fimpara
   fimse

senao
     se (m[3,2]<0) entao
        para j de 1 ate 4 faca
             m[3,j]<-(-v[3])*m[2,j]+m[3,j]
        fimpara
     senao
          para j de 1 ate 4 faca
               m[3,j]<-(v[3])*m[2,j]+m[3,j]
          fimpara
     fimse
fimse
v[3]<-m[3,3]
para j de 1 ate 4 faca          //divide toda linha para achar o 3° pivot//
     m[3,j]<-m[3,j]/v[3]
fimpara
v[1]<-m[1,3]
v[2]<-m[2,3]

se (m[3,3]>0) entao //verifica os sinais linhas 3 e 1, multiplica e substitui//
   se(m[1,3]>0) entao
                para j de 1 ate 4 faca
                     m[1,j]<-(-v[1])*m[3,j]+m[1,j]
                fimpara
   senao
        para j de 1 ate 4 faca
             m[1,j]<-(-v[1])*m[3,j]+m[1,j]
        fimpara
   fimse

senao
     se (m[1,3]<0) entao
        para j de 1 ate 4 faca
             m[1,j]<-(-v[1])*m[3,j]+m[1,j]
        fimpara
     senao
          para j de 1 ate 4 faca
               m[1,j]<-(v[1])*m[3,j]+m[1,j]
          fimpara
     fimse
fimse

se (m[3,3]>0) entao //verifica os sinais linhas 3 e 2, multiplica e substitui//
   se(m[2,3]>0) entao
                para j de 1 ate 4 faca
                     m[2,j]<-(-v[2])*m[3,j]+m[2,j]
                fimpara
   senao
        para j de 1 ate 4 faca
             m[2,j]<-(-v[2])*m[3,j]+m[2,j]
        fimpara
   fimse

senao
     se (m[2,3]<0) entao
        para j de 1 ate 4 faca
             m[2,j]<-(-v[2])*m[3,j]+m[2,j]
        fimpara
     senao
          para j de 1 ate 4 faca
               m[2,j]<-(v[2])*m[2,j]+m[2,j]
          fimpara
     fimse
fimse



para i de 1 ate 3 faca         //Imprime//
     para j de 1 ate 4 faca
          escreva(m[i,j])
     fimpara
     escreval()
fimpara
Fimalgoritmo