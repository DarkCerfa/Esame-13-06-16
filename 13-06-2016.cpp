/*
Si scriva un programma che legge una poesia da un file di testo passatogli come unico argomento, e
poi la visualizzi a schermo con allineamento scelto dall'utente: sinistro, destro o centrato. Il file di
testo conterrà al massimo MAXR righe di MAXC caratteri ciascuna. L'ampiezza della
visualizzazione da utilizzare per gli allineamenti a destra ed al centro è data dalla lunghezza della riga
più lunga. Nel memorizzare la riga si utilizzi solo la memoria strettamente necessaria. La struttura del
codice rispetti il seguente schema:
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
void destra(char* testo[], int righe, int maxlungriga) { PUNTI 4 }
void centro(char* testo[], int righe, int maxlungriga) { PUNTI 4 }
void sinistra(char* testo[], int righe) { PUNTI 2 }
int main(int argc, char** argv) { PUNTI 8 }
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <streambuf>
#define MAXC 100
#define MAXR 100
using namespace std;
void destra(char*[], int, int);
void centro(char*[], int, int);
void sinistra(char*[],int);
int main(int argc, char** argv){
int i=0,Mlungh=0;
char scelta;
bool flag=true;
char* testo[MAXR];//è un vettore di puntatori di caratteri che puntano all inizio di ogni riga
fstream input;
input.open(argv[1],ios::in);
while(input.good()){
    char riga [MAXC];//dichiaro una riga di caratteri max
    input.getline(riga,MAXC);//leggo la riga dal file e la salvo su riga
    testo[i]=new char[strlen(riga)];//ogni volta che leggo una riga dal file mi creo una array(testo i) nello heap con l' esatta lunghezza della riga letta
    strcpy(testo[i],riga);//mi copio il contenuto di riga in testo[i]
    if (strlen(testo[i])>Mlungh)Mlungh=strlen(testo[i]);//qui ci dice che se la lunghezza di questo testo è maggiore della lunghezza massima salva la sua dimensione in massima lunghezza sovrascrivendola
        i++;
}
input.close();
do{
do{
    cout<<"s: allineato a sinistra"<<endl;
    cout<<"d: allineato a destra"<<endl;
    cout<<"c: allineato al centro"<<endl;
    cout<<"e: esci"<<endl;
    cin>>scelta;
    if(scelta!='c'&&scelta!='d'&&scelta!='s'&&scelta!='e')
        cout<<"lettera non consentita"<<endl;
}while(scelta!='c'&&scelta!='d'&&scelta!='s'&&scelta!='e');
    switch(scelta){
        case 's':{
            sinistra(testo,i);
        break;
        }
        case 'd':{
            destra(testo,i,Mlungh);
        break;
        }
        case 'c':{
            centro(testo,i,Mlungh);
        break;
        }
        case 'e':{
        cout<<"Arrivederci e Grazie"<<endl;
        flag=false;
        }
    }
}while(flag);
return 0;
}

void sinistra(char*testo[], int n){
for(int i=0;i<n;i++){
    cout<<testo[i]<<endl;
}
}

void destra(char*testo[],int n, int Mlungh){
int lungh1=0;
for(int i=0;i<n;i++){
    lungh1=Mlungh-strlen(testo[i]);
    for(int j=0;j<lungh1;j++)
        cout<<" ";
    cout<<testo[i]<<endl;
}
}

void centro(char*testo[],int n, int Mlungh){
int lungh1=0;
for(int i=0;i<n;i++){
    lungh1=Mlungh-strlen(testo[i]);
for(int j=0;j<lungh1/2;j++)
    cout<<" ";
cout<<testo[i]<<endl;
}
}
