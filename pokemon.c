#include <stdio.h>
#include <stdlib.h> 
#include<conio.h>
#include<string.h>

// 3971 - ROMULO FERNANDES GOUVEA

typedef struct Pokemon
{
	char nome[30];
	int tipo;	
}Elemento;

typedef struct celula
{
	Elemento info;
	struct celula * prox;
	struct celula * ante;
}Celula;

typedef struct deque
{
	Celula * inicio;
	Celula * fim;
}Deque;

void inicializar(Deque * deque)
{
	deque->inicio = NULL;
	deque->fim = NULL;
}

int vazia(Deque * deque)
{
	if (deque->inicio==NULL)
	{
		return 1;
	}
	return 0;
}

Celula * criarCelula()
{
	Celula * nova;
	nova= (Celula*)malloc(sizeof(Celula));
	return nova;
}

int inserirDequeFim(Deque * deque, Elemento novo)
{
	Celula * novaCelula= criarCelula();
	
	if (novaCelula == NULL)
	{
		printf("Erro: Impossivel alocar memoria.");
		return 0;
	}
	
	novaCelula->info = novo;
	novaCelula->ante = NULL;
	novaCelula->prox =NULL;
	
	if (vazia(deque))
	{
		deque->inicio = novaCelula;
		deque->fim = novaCelula;
		return 1;
	}
	
	deque->fim->prox=novaCelula;
	novaCelula->ante=deque->fim;
	deque->fim=novaCelula;
	return 1;
}

int inserirDequeInicio(Deque * deque, Elemento novo)
{
	Celula * novaCelula= criarCelula();
	
	if (novaCelula == NULL)
	{
		printf("Erro: Impossivel alocar memoria.");
		return 0;
	}
	
	novaCelula->info= novo;
	novaCelula->ante= NULL;
	novaCelula->prox=NULL;
	if (vazia(deque))
	{
		deque->inicio=novaCelula;
		deque->fim=novaCelula;
		return 1;
	}
	deque->inicio->ante=novaCelula;
	novaCelula->prox=deque->inicio;
	deque->inicio=novaCelula;
	return 1;
}

Elemento removerDequeInicio(Deque * deque)
{
	Elemento vazio;
	Celula * aux;
	
	strcpy(vazio.pokemon, "");
	vazio.tipo=0;
	
	if (vazia(deque))
	{
		printf("Erro deque vazia.");
		return vazio;
	}
	
	aux=deque->inicio;
	vazio = aux->info;
	
	if (deque->inicio->prox==NULL)
	{
		inicializar(deque);		
		free(aux);
		return vazio;
	}
	else
	{
		deque->inicio->prox->ante=NULL;
		deque->inicio= deque->inicio->prox;
		free(aux);
		return vazio;
	}	
}

void imprimir(Deque * deque)
{
	Elemento e;
	Deque deque2;
	inicializar(&deque2);
	
	if (vazia(deque))
	{
		printf("A deque esta vazia!");
		return;
	}
	
	while(!vazia(deque))
	{
		e = removerDequeInicio(deque);
		printf("\nPokemon: %s - Tipo: %d", e.nome, e.tipo);		
		inserirDequeFim(&deque2, e);
	
	}
	while(!vazia(&deque2))
	{
		inserirDequeInicio(deque, removerDequeInicio(&deque2));
		
	}
}

void menuTipo()
{
	printf("\nTipo:");
	printf("\n1 - ar");
	printf("\n2 - fogo");
	printf("\n3 - agua");
	printf("\n4 - terrestre");
	printf("\n5 - outros");
	printf("\nOpcao: ");	
}

void combatePokemon(Deque * dequeJogador1,Deque * dequeJogador2,combate){
	int i = 1;
	char continua;
	
	while(i != combate+1)
	{
		printf("\n=== Combate %d",i);
		printf("\n%s, tipo:%s",dequeJogador1.inicio->nome,dequeJogador1.inicio->tipo);
		printf("\n--- VS ---");
		printf("\n%s, tipo:%s",dequeJogador2.inicio->nome,dequeJogador2.inicio->tipo);
		
		printf("\nDigite . e depois ENTER para continuar:");
		do{
			scanf("%c",&continua);
		}while(strcmp(continua, ".") == 0);
		
		//compara
		
		printf("\nDigite . e depois ENTER para continuar:");
		do{
			scanf("%c",&continua);
		}while(strcmp(continua, ".") == 0);
		
		//fazer o placar final
				
		i++;
	}
	
}
void compara(){//falta os parametros e o tipo dela
	
	if(inJogador1 == inJogador2){
		//empate
		removerDequeInicio(&dequeJogador1);
		removerDequeInicio(&dequeJogador2);
		
	}
	switch(inJogador1){
		case 1:
			if(inJogador2 == 3 || inJogador2 == 4 ){//  AR
				//jogador1 vence
				removerDequeInicio(&dequeJogador2);
			}else{
				//jogador2 vence
				removerDequeInicio(&dequeJogador1);
			}
			break;
		case 2:
			if(inJogador2 == 1 || inJogador2 == 5 ){//  FOGO
				//jogador1 vence
				removerDequeInicio(&dequeJogador2);
			}else{
				//jogador2 vence
				removerDequeInicio(&dequeJogador1);
			}
			break;
		case 3:
			if(inJogador2 == 2 || inJogador2 == 5 ){//  AGUA
				//jogador1 vence
				removerDequeInicio(&dequeJogador2);
			}else{
				//jogador2 vence
				removerDequeInicio(&dequeJogador1);
			}
			break;
		case 4:
			if(inJogador2 == 2 || inJogador2 == 3 ){//   TERRESTRE
				//jogador1 vence
				removerDequeInicio(&dequeJogador2);
			}else{
				//jogador2 vence
				removerDequeInicio(&dequeJogador1);
			}
			break;
		case 5:
			if(inJogador2 == 1 || inJogador2 == 4 ){//   OUTROS
				//jogador1 vence
				removerDequeInicio(&dequeJogador2);
			}else{
				//jogador2 vence
				removerDequeInicio(&dequeJogador1);
			}
			break;
		default:
			printf("\nERRO |default!|");
	}
}

int contCelulas(Deque * deque){
	int count;
	Deque deque2;
	inicializar(&deque2);
	
	while(!vazia(deque))
	{		
		inserirDequeFim(&deque2, removerDequeInicio(deque));
		count++;
	}
	while(!vazia(&deque2))
	{
		inserirDequeInicio(deque, removerDequeInicio(&deque2));
	}
	
	return count;
}

int main()
{
	Elemento e;
	Deque  dequeJogador1,dequeJogador2;
	int opcao,qtdPokemons,i,combate;
	
	inicializar(&dequeJogador1);
	inicializar(&dequeJogador2);
	
	printf("\nQuantos pokemins para cada jogador?: ");	
	scanf("%d", &qtdPokemons);
	
	printf("\nPokemons do jogador 1:");
	for( i = 0 ; i < qtdPokemons ; i++ ){
		printf("\nNome do pokemon:");
		scanf("%s", e.nome);	
		menuTipo();
		scanf("%d", &e.tipo);
		inserirDequeFim(&dequeJogador1, e);
	}
	
	printf("\nPokemons do jogador 2:");
	for( i = 0 ; i < qtdPokemons ; i++ ){
		printf("\nNome do pokemon:");
		scanf("%s", e.nome);	
		menuTipo();
		scanf("%d", &e.tipo);
		inserirDequeFim(&dequeJogador2, e);
	}
	
	printf("\nJogador1: %d pokemons restantes ",contCelulas(&dequeJogador1));
	printf("\nJogador2: %d pokemons restantes ",contCelulas(&dequeJogador2));
	
	combate = contCelulas(&dequeJogador1);
	
	combatePokemon(&dequeJogador1,&dequeJogador2,combate);
	
	//inserirDequeInicio(&deque, e);
	//e=removerDequeInicio(&deque);
	//imprimir(&deque);
	
	//1 função pra:
	//imprimir a quantidade de celulas que tem em cada deque
		
	return 0;
}

