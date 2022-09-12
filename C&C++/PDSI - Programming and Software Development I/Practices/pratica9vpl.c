#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//1)----------------------------------------------------------------------------
typedef struct Guerreiro{
    int ataque;
    int defesa;
    int carisma;
    int pontos_vida;
    int id_guerreiro;
}Guerreiro;

//2)----------------------------------------------------------------------------
int rolaDados (){
    int d1, d2, d3;
    d1 = 1 + rand()%6;
    d2 = 1 + rand()%6;
    d3 = 1 + rand()%6;
    return d1 + d2 + d3;
}

//3)----------------------------------------------------------------------------
void criaGuerreiro (Guerreiro *g){
    g->ataque = rolaDados();
    g->defesa = rolaDados();
    g->carisma = rolaDados();
    int exec1=0, exec2=0, exec3=0;
    exec1 = rolaDados();
    exec2 = rolaDados();
    exec3 = rolaDados();
    g->pontos_vida = exec1 + exec2 + exec3;
}

//4)----------------------------------------------------------------------------
int bonusCarisma (int carisma){
    if (carisma == 18){
        return 3;
    }
    else if (carisma == 17 || carisma == 16){
        return 2;
    }
    else if (carisma == 15 || carisma == 14){
        return 1;
    }
    else if (carisma == 7 || carisma == 6){
        return -1;
    }
    else if (carisma == 5 || carisma == 4){
        return -2;
    }
    else if (carisma == 3){
        return -3;
    }
    else{
        return 0;
    }
}

//5)----------------------------------------------------------------------------
void ataca (Guerreiro *g1, Guerreiro *g2){
    int golpe=0, dano=0, escudo=0;
    golpe = rolaDados() + g1->ataque + bonusCarisma(g1->carisma);
    escudo = rolaDados() + g2->defesa + bonusCarisma(g2->carisma);
    dano = golpe - escudo;
    if (dano > 0){
        g2->pontos_vida -= dano;
        if (g2->pontos_vida < 0){
            while (g2->pontos_vida != 0) {
                g2->pontos_vida++;
            }
        }
    }
}

//6)----------------------------------------------------------------------------
int main(){
	srand(time(NULL));
	Guerreiro g1;
    g1.id_guerreiro = 1;
    Guerreiro g2;
    g2.id_guerreiro = 2;
	criaGuerreiro(&g1);
    criaGuerreiro(&g2);
	int jogada = 0;
	for (jogada=2; g1.pontos_vida != 0 && g2.pontos_vida != 0; jogada++){
		if (jogada%2==0){
			ataca(&g1, &g2);
		}
		else{
			ataca(&g2, &g1);
		}
	}
	
	if(g1.pontos_vida != 0){
        printf("\nVencedor: %d", g1.id_guerreiro);
        printf("\nPontos de vida restantes: %d", g1.pontos_vida);
    }
    else{
        printf("\nVencedor: %d", g2.id_guerreiro);
        printf("\nPontos de vida restantes: %d", g2.pontos_vida);
    }
	
	return 0;
}














