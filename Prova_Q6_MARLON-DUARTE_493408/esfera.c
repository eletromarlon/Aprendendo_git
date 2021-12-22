#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "esfera.h"


float volume_esfera(float raio, float pi){
    float temp;
    temp = (4*pi*(raio*raio*raio))/3;
    return temp;
}

float area_esfera(float raio, float pi){
    float temp;
    temp = 4*pi*(raio*raio);
    return temp;
}
float raio_esfera_volume(float volume, float pi){
    float temp;
    temp = ((3*volume)/(4*pi));
    temp = pow (temp, (0.3333));
    return temp;
}
float raio_esfera_area(float area, float pi){
    float temp;
    temp = (area/(4*pi));
    temp = pow (temp, (0.5));
    return temp;
}
