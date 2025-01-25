#include <stdio.h>
#include <stdlib.h>
void TriRapid(int T[],int g,int d){
    int pi=partition(T,g,d);
    TriRapid(T,g,pi-1);
    TriRapid(T,pi+1,d);
}
 int partition(int T[],int g,int d){
    int pivot=T[d];
    int i=g-1;
    for(int j=g ;j<d;j++){
        if(T[j]<=pivot){
            i++;
            echange(&T[i],T[j]);
        }
    }
    echange(&T[i+1],T[d]);
    return (i+1);
 }
void echange(int *X,int *Y){
    int TMP =*X;
    *X=*Y;
    *Y=TMP;
}
void affichage(int T[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",T[i]);
    }
}
int main(){
int taille =6;
int T[]={20,25,35,12,10};

TriRapid(T,0,taille);
printf("tableau tri = ");
affichage(T,taille);
    return 0;
}