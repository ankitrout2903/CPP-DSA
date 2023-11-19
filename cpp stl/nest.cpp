#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//------------------
void player_pkmn(int number,char *ptr){
  if(number == 1){ strcpy(ptr,"CHARIZARD"); }
  else if(number == 2){ strcpy(ptr,"BLASTOISE"); }
  else if(number == 3){ strcpy(ptr,"VENUSAUR"); }
}
//------------------
void pkmn_type(int number,char *ptr){
  if(number == 1){ strcpy(ptr,"Fire/Fly"); }
  else if(number == 2){ strcpy(ptr,"Water"); }
  else if(number == 3){ strcpy(ptr,"Grass/Poi"); }
}
//------------------
void attack(int number){
  if(number == 1){
    printf("1 - Fire Blast\n");
    printf("2 - Air Slash\n");
    printf("3 - Earthquake\n");
    printf("4 - Brick Break\n"); 
  }
  else if(number == 2){
    printf("1 - Hydro Pump\n");
    printf("2 - Blizzard\n");
    printf("3 - Water Pulse\n");
    printf("4 - Vital Throw\n");
  }
  else if(number == 3){
    printf("1 - Grass Knot\n");
    printf("2 - Sludge\n");
    printf("3 - Body press\n");
    printf("4 - Petal Blizzard\n");
  }
}
//------------------
void player_attack(int num,int att_num){
  if(num == 1){
     printf("CHARIZARD USED ");
     if(att_num==1){ printf("FIRE BLAST!\n"); }
     else if(att_num==2){ printf("AIR SLASH!\n"); }
     else if(att_num==3){ printf("EARTHQUAKE!\n"); }
     else if(att_num==4){ printf("BRICK BREAK! It was Super Effective!\n"); }
  }
  else if(num == 2){
     printf("BLASTOISE USED ");
     if(att_num==1){ printf("HYDRO PUMP!\n"); }
     else if(att_num==2){ printf("BLIZZARD!\n"); }
     else if(att_num==3){ printf("WATER PULSE!\n"); }
     else if(att_num==4){ printf("VITAL THROW! It was Super Effective!\n"); }
  }
  else if(num == 3){
     printf("VENUSAUR USED ");
     if(att_num==1){ printf("GRASS KNOT!\n"); }
     else if(att_num==2){ printf("SLUDGE!\n"); }
     else if(att_num==3){ printf("BODY PRESS! It was Super Effective!\n"); }
     else if(att_num==4){ printf("PETAL BLIZZARD!\n"); }
  }
}
//------------------
void computer_attack(int att_num){
  printf("CASTFORM USED ");
  if(att_num==1){ printf("FIRE BLAST! "); }
  else if(att_num==2){ printf("HYDRO PUMP! "); }
  else if(att_num==3){ printf("BLIZZARD! "); }
  else if(att_num==4){ printf("THUNDER! "); }  
}
//------------------
void comp_typeadv(int num,int att){
  if(num==1){
    if(att==1){ printf("It was Not Very Effective!\n"); }
    else if(att==2){ printf("It was Super Effective!\n"); }
    else if(att==3){ printf("\n"); }
    else if(att==4){ printf("It was Super Effective!\n"); }
  }
  else if(num==2){
    if(att==1){ printf("It was Not Very Effective!\n"); }
    else if(att==2){ printf("It was Not Very Effective!\n"); }
    else if(att==3){ printf("It was Not Very Effective!\n"); }
    else if(att==4){ printf("It was Super Effective!\n"); }
  }
  else if(num==3){
    if(att==1){ printf("It was Super Effective!\n"); }
    if(att==2){ printf("It was Not Very Effective!\n"); }
    if(att==3){ printf("It was Super Effective!\n"); }
    if(att==4){ printf("It was Not Very Effective!\n"); }
  }
}
//------------------
void hpcalc(int num,int att,int a,float *P,float*C){
  if(num==1){
    if(att==1){ *C=(*C)+11; }
    else if(att==2){ *C=(*C)+7.5; }
    else if(att==3){ *C=(*C)+10; }
    else if(att==4){ *C=(*C)+7.5+4; }
    
    if(a==1){ *P=(*P)+11-5; }       //Now working on the Damage Dealt by Computer
    else if(a==2){ *P=(*P)+11+5; }
    else if(a==3){ *P=(*P)+11; }
    else if(a==4){ *P=(*P)+11+5; }
  }
  
  else if(num==2){
    if(att==1){ *C=(*C)+11; }
    else if(att==2){ *C=(*C)+11; }
    else if(att==3){ *C=(*C)+6; }
    else if(att==4){ *C=(*C)+6+4; }
    
    if(a==1){ *P=(*P)+11-5; }       //Now working on the Damage Dealt by Computer
    else if(a==2){ *P=(*P)+11-5; }
    else if(a==3){ *P=(*P)+11-5; }
    else if(a==4){ *P=(*P)+11+5; }
  }
  
  else if(num==3){
    if(att==1){ *C=(*C)+12; }
    else if(att==2){ *C=(*C)+6.5; }
    else if(att==3){ *C=(*C)+8+4; }
    else if(att==4){ *C=(*C)+9; }
    
    if(a==1){ *P=(*P)+11+5; }       //Now working on the Damage Dealt by Computer
    else if(a==2){ *P=(*P)+11-5; }
    else if(a==3){ *P=(*P)+11+5; }
    else if(a==4){ *P=(*P)+11-5; }
  }
}
//------------------
void score(float P,float C,int hp,char *pkmn){
  printf("%s:\n",pkmn);
//  printf("Total Damage Dealt to %s:%.1f\n",pkmn,P);
  printf("HP Remaining: ");
  if((hp-P)>=(0.6*hp)){ printf("███████▒▒▒ %.1f\n",hp-P); }
  else if(((hp-P)<(0.6*hp))&&((hp-P)>=(0.4*hp))){ printf("█████▒▒▒▒▒ %.1f\n",hp-P); }
  else if(((hp-P)<(0.4*hp))&&((hp-P)>=(0.2*hp))){ printf("███▒▒▒▒▒▒▒ %.1f\n",hp-P); }
  else if((hp-P)<(0.2*hp)){ printf("█▒▒▒▒▒▒▒▒▒ %.1f\n",50-P); }
  
  printf("\nCASTFORM:\n");
//  printf("Total Damage Dealt to CASTFORM:%.1f\n",C);
  printf("HP Remaining: ");
  if((hp-C)>=(0.6*hp)){ printf("███████▒▒▒ %.1f\n",hp-C); }
  else if(((hp-C)<(0.6*hp))&&((hp-C)>=(0.4*hp))){ printf("█████▒▒▒▒▒ %.1f\n",hp-C); }
  else if(((hp-C)<(0.4*hp))&&((hp-C)>=(0.2*hp))){ printf("███▒▒▒▒▒▒▒ %.1f\n",hp-C); }
  else if((hp-C)<(0.2*hp)){ printf("█▒▒▒▒▒▒▒▒▒ %.1f\n",50-C); }
}
//--------------------
// MAIN CODE HERE GOES
//--------------------
int main()
{
  printf("\t|°°°| |°°°| | / |°°° |\\ /| |°°°| |\\  | \n");
  printf("\t|___| |   | |{  |--  |   | |   | | \\ | \n");
  printf("\t|     |___| | \\ |___ |   | |___| |  \\| \n");
  printf("\t▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬\n");
  printf("\t    Gotta    Catch    `Em    All\n");
  printf("\t   °°°°°°°  °°°°°°°   °°°°  °°°°°\n");
//------------------
  printf("\n\nEnter Your Name - ");
      char* name;
      name=(char*) malloc(20*sizeof(char));
  scanf("%s",name);
label:  
  printf("\n\nChoose Your Pokemon:\n");
  printf("°°°°°°°°°°°°°°°°°°°°\n");
  
  printf("\n1 - CHARIZARD\n");
  printf("2 - BLASTOISE\n");
  printf("3 - VENUSAUR\n");
//------------------
  printf("\nEnter the number:");
      int player;
      char *pkmn;
      pkmn = (char*) malloc(10*sizeof(char));
  scanf("%d",&player);
  
  if((player<1)||(player>3)){
    printf("\nPlease Enter a Valid Input!");
    goto label;
  }
//------------------  
  player_pkmn(player,pkmn);
  printf("\n\n%s: %s, I Choose You !\n",name,pkmn);
  for(int i=0 ; i<strlen(name)+1 ; i++){ printf("°"); }
  free(name);
  
  printf("\n\nComputer: CASTFORM, Lets Tell Them Who's The Boss!\n");
  for(int i=0 ; i<8 ; i++){ printf("°"); }
  
  printf("\n\n   %s   V/S   CASTFORM\n",pkmn);
  free(pkmn);
  pkmn_type(player,pkmn);
  printf("   %s          ",pkmn);
  if(player==1){ printf(" "); }
  if(player==2){ printf("    "); }
  printf("Normal\n\n");
  free(pkmn);
//----------------------
  srand(time(NULL)); //
  float C=0,P=0;     //
  int max_hp= 50;    //
  player_pkmn(player,pkmn);
//----------------- Main Game Start
while(1){
  printf("Choose Your Attack\n");
  printf("°°°°°°°°°°°°°°°°°°\n");
  attack(player);
  
  printf("\nEnter your Attack Number:");
  int att;
  scanf(" %d",&att);
  
  printf("\n\n");
  player_attack(player,att);    
  printf("\n");
     int a=rand()%4;
     a=a+1;
  computer_attack(a);
  comp_typeadv(player,a);
  printf("\n");
  
  hpcalc(player,att,a,&P,&C);
  if((P>=max_hp)||(C>=max_hp)){ break; }
  score(P,C,max_hp,pkmn);
  printf("\n");
}  
//------------------ Result
  printf("\n●～●～●～●～●～●～●～●～●～●～●～●～●～●～●\n");
  if((P>=max_hp)&&(C>=max_hp)){
    printf("\n%s:\n",pkmn);
    printf("HP Remaining: ▒▒▒▒▒▒▒▒▒▒ 0.0\n");
    printf("\n%s Fainted (*_*)\n",pkmn);
    
    printf("\nCASTFORM:\n");
    printf("HP Remaining: ▒▒▒▒▒▒▒▒▒▒ 0.0\n");
    printf("\nCASTFORM Fainted (*_*)\n");
    
    printf("\n●～●～●～●～●～●～●～●～●～●～●～●～●～●～●\n");
    printf("\nBoth Pokemon Are Unable To Fight anymore!\n");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
    printf("DRAW!\n");
    printf("°°°°°\n");
    }
  else if(C<max_hp){
    printf("\n%s:\n",pkmn);
    printf("HP Remaining: ▒▒▒▒▒▒▒▒▒▒ 0.0\n");
    printf("\n%s Fainted (*_*)\n",pkmn);
    
    printf("\n%s Is Unable To Battle Anymore!\n",pkmn);
    for(int i=0 ; i<strlen(pkmn) ; i++){ printf("°"); }
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
    printf("CASTFORM WINS!\n");
    printf("°°°°°°°°°°°°°°\n");
  }
  else{
    printf("\nCASTFORM:\n");
    printf("HP Remaining: ▒▒▒▒▒▒▒▒▒▒ 0.0\n");
    printf("\nCASTFORM Fainted (*_*)\n");
    
    printf("\nCASTFORM Is Unable To Battle Anymore!\n");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
    printf("%s WINS!\n",pkmn);
    for(int i=0 ; i<strlen(pkmn) ; i++){ printf("°"); }
    printf("°°°°°°\n");
  }
  printf("\n●～●～●～●～●～●～●～●～●～●～●～●～●～●～●\n");
  free(pkmn);
//------------------  
  return 0;
}