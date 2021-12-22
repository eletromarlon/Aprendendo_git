#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos{
    float x;
	float y;
};

typedef struct pontos pontos;

void dist(pontos v[]){

    int j, i;
    float d[4];

		for(j = 1, i=0; j<5, i<4 ; j++, i++){
            d[i] = sqrt(pow(((v[j].x)-(v[0].x)),2) + pow(((v[j].y)-(v[0].y)),2));
        }

	if(d[0]<d[1] && d[0]<d[2] && d[0]<d[3]){
        printf("O mais proximo é: %.2f , %.2f \n", v[1].x, v[1].y);
	}   else if(d[1]<d[0] && d[1]<d[2] && d[1]<d[3]){
            printf("O mais proximo é: %.2f , %.2f \n", v[2].x, v[2].y);
        }   else if(d[2]<d[0] && d[2]<d[1] && d[2]<d[3]){
                printf("O mais proximo é: %.2f , %.2f \n", v[3].x, v[3].y);
            }   else if(d[3]<d[0] && d[3]<d[1] && d[3]<d[2]){
                    printf("O mais proximo é: %.2f , %.2f \n", v[4].x, v[4].y);
                }


    if(d[0]>d[1] && d[0]>d[2] && d[0]>d[3]){
        printf("O mais distante é: %.2f , %.2f \n", v[1].x, v[1].y);
	}   else if(d[1]>d[0] && d[1]>d[2] && d[1]>d[3]){
            printf("O mais distante é: %.2f , %.2f \n", v[2].x, v[2].y);
        }   else if(d[2]>d[0] && d[2]>d[1] && d[2]>d[3]){
                printf("O mais distante é: %.2f , %.2f \n", v[3].x, v[3].y);
            }   else if(d[3]>d[0] && d[3]>d[1] && d[3]>d[2]){
                    printf("O mais distante é: %.2f , %.2f \n", v[4].x, v[4].y);
                }

}


int main(){
	float valor;
	pontos v[5];


		for(int i = 0; i<5 ; i++){
            printf("Entre com a cordenada x:");
            scanf("%f", &v[i].x);
            printf("Entre com a cordenada y:");
            scanf("%f", &v[i].y);
        }

	dist(v);

}
