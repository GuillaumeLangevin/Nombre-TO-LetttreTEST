#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <charconv>
#include <stdlib.h>
#include <algorithm>

//La je veux crée l'initilisation avec les "un","deux","trois"
using namespace std;


void initialisation(string EnLettre[],string EnLettrediz[]){


  EnLettre[1]="un";
  EnLettre[2]="deux";
  EnLettre[3]="trois";
  EnLettre[4]="quatre";
  EnLettre[5]="cinq";
  EnLettre[6]="six";
  EnLettre[7]="sept";
  EnLettre[8]="huit";
  EnLettre[9]="neuf";
  EnLettre[10]="dix";
  EnLettre[11]="onze";
  EnLettre[12]="douze";
  EnLettre[13]="treize";
  EnLettre[14]="quatorze";
  EnLettre[15]="quinze";
  EnLettre[16]="seize";

  EnLettrediz[1]="";
  EnLettrediz[2]="vingt";
  EnLettrediz[3]="trente";
  EnLettrediz[4]="quarante";
  EnLettrediz[5]="cinquante";
  EnLettrediz[6]="soixante";
  /*
  EnLettrediz[7]="soixante dix";
  EnLettrediz[8]="quatre vingt";
  EnLettrediz[9]="quatre vingt dix";
  */
}
string decompintcendiz(int nombre){
  string n;int test=nombre,dep=0;
  int exp=nombre/100,exp1=nombre/10;
  //while(test!=0){ A voir si le tant que est nécessaire mais dans le cas ou il faut mettre un while, il est bloqué dans une boucle infini 
    if (test>=100){
    n=to_string(nombre/100)+"*100+";
    dep=dep+(nombre/100)*100;
    test=test-exp*100;
  }
  // A voir si besoin de distinguer 70(60+10) et 7*10 ou 90(4+20) et 9*10
  if(test>=80&&test<=99){
    n=n+"4*20+";
    test=test-80;
  }
  if(test>=71&&test<=79){
    n=n+"6*10+";
    test=test-60;
  }
  if(test>16){
    n=n+to_string(test/10)+"*10+";
    dep=dep+(test/10)*10;
    test=test-(test/10)*10;
  }
  if (test!=0){
    n=n+to_string(test);
    dep=dep+test;
    test=test-test;
  //}
  }
  
  return n;
}
void decomposition(double nombre){
  string nombrestring,dcomp,p1,p2,p3,p4;
  int tailletotale,taillesansvirgule,test=nombre,dep=0,pos=-1;
  nombrestring=to_string(nombre);
  tailletotale=nombrestring.size();
  taillesansvirgule=tailletotale-8;
  cout<<"taille : "<<tailletotale<<endl;
  cout<<"chaine : "<<nombrestring<<endl;
  
  if(taillesansvirgule<3){
    p1.assign(nombrestring,0,taillesansvirgule+1);
    dcomp=dcomp+decompintcendiz(stoi(p1));
  }
  if(taillesansvirgule>=3&&taillesansvirgule<6){
    p1.assign(nombrestring,0,taillesansvirgule-2);
    p2.assign(nombrestring,taillesansvirgule-2,3);
    dcomp=dcomp+decompintcendiz(stoi(p1))+"*10^3 + ";
    dcomp=dcomp+decompintcendiz(stoi(p2));
  }
  if(taillesansvirgule>=6&&taillesansvirgule<8){
    p1.assign(nombrestring,0,taillesansvirgule-5);
    p2.assign(nombrestring,taillesansvirgule-5,3);
    p3.assign(nombrestring,taillesansvirgule-2,3);
    dcomp=dcomp+decompintcendiz(stoi(p1))+"*10^6 + ";
    dcomp=dcomp+decompintcendiz(stoi(p2))+"*10^3 + ";
    dcomp=dcomp+decompintcendiz(stoi(p3));
  }
  for(int i=0;i<=tailletotale;i++){
    if(nombrestring[i]=='.'){
      pos=i;
      cout<<"position de la virgule : "<<pos<<endl;
    }
  }
  
  if(pos>=0){
    p4.assign(nombrestring,pos+1,2);
    cout<<p4<<endl;
    dcomp=dcomp+" , "+decompintcendiz(stoi(p4));
  }
  


  /*
    p1.assign(n,0,t-5);
    p2.assign(n,t-5,3);
    p3.assign(n,6,3);



  
  if(nombre>=1000000){
    dcomp=dcomp+decompintcendiz(stoi(p1))+"*10^6 + ";
    dcomp=dcomp+decompintcendiz(stoi(p2))+"*10^3 + ";//A voir si sa correspond a ceux que l'on veut faire ...
    dcomp=dcomp+decompintcendiz(stoi(p3));
  }
  if(nombre>=1000&&nombre<=999999){
    dcomp=dcomp+decompintcendiz(stoi(p1))+"*10^3 + ";
    dcomp=dcomp+decompintcendiz(stoi(p2));
  }
  if(nombre>=10&&nombre<=999){
    dcomp=dcomp+decompintcendiz(stoi(p1));
  }

*/
  cout<<dcomp;
}




void traduction(int nombre,string tabentier[],string tabdiziane[]){
  
  
 
  /*
  string n,ttt;int taille; 
  n=to_string(nombre);
  //reverse(n.begin(),n.end());
  taille=n.size();
  int test;
  string transformation[taille];
  //ttt=conversioncentaine(transformation,tabentier,1);

  
  for (int i=0;i<=taille-1;i++){
    string t;t=n[i];  
    if((i)%3==0){
      transformation[i]=tabentier[stoi(t,nullptr,16)]+" cent";
    }
    else{
      transformation[i]=tabentier[stoi(t,nullptr,16)];
    }
    cout<<transformation[i]<<" ";
  } 
  */
}
/*
string conversioncentaine(string transform[],string tab[],int position){
  string t=transform[position],resultat;  
  resultat = tab[stoi(t,nullptr,16)]+" cent";
  return resultat;
}

void conversiondizaine(){
  
}

void conversionentier(){
  
}
*/

/*
int Ajoutmillionmillier(string t,int tt){
  string m="millions",te;
  if (tt>3&&tt<7){
    return 2;
  }
  if (tt>7){
    return 1;
  }
  return 3;
}
*/



//La décomposition en théorie fonctionne mais bon à vérifier dans certain cas notamment 1000000 (1*100+*10^6 + 0*10^3 + 0) ou faudra supprimer les 0 inutiles faire la simplification 
int main() {
  double entier=2536276.25;
  string tab1[17],tab2[9];
  initialisation(tab1,tab2);
  //traduction(entier,tab1,tab2);
  decomposition(entier);
}