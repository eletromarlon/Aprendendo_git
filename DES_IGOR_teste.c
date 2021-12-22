#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float compCabo (float basMetros,  float altMetros){
	float compCaboM;
	compCaboM = sqrt((pow(basMetros, 2)) + (pow(altMetros, 2)));

	return compCaboM;
	}

int main(){
	float distPonte, baseM, alturaM, distPontm, compXcabo, altura_metrosCabo, base_metrosCabo;
	float somaCabos = 0;
	float i;

	do {
	printf("Digite a distância da ponte em (Km): \n");
		scanf("%f", &distPonte);
    }while ((distPonte<2) || (distPonte>4));

    distPontm = distPonte * 1000; //distPontem ponte em metros
    baseM = distPontm/2;  //metade da ponte, cateto adjacente
    alturaM = distPontm/20; //haste da ponte
    altura_metrosCabo = alturaM/5; //redução em partes da haste
    base_metrosCabo = baseM/5; //redução em partes da metade da ponte
    printf(" distPontm %f \nbaseM %f \nalturaM %f \naltura_metroscabo %f \nbase_metrosCabo %f \n", distPontm, baseM, alturaM, altura_metrosCabo, base_metrosCabo);


        for(i = 0; i<5 ; i++ ){
        compXcabo = compCabo(baseM , alturaM);
        baseM -= base_metrosCabo;
        alturaM -= altura_metrosCabo;
        somaCabos += compXcabo;
            }
		somaCabos *= 4;
		printf("A quantidade de cabos de aço em metros que será preciso para construir a ponte será de: %.2f m", somaCabos);

	return 0;
}
