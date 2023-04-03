#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void polygon_calc(float * input, float * area, float * inradius, float * circumradius, float * perimeter, float * interior, float * exterior, int sides, int size);

int main() {
    //number of tests
    int n = 5;
    const int max_n = 50000000;
    //number of sides
    const int sides = 9;
    // Input array
    srand(time(0));
    while (n <= max_n) {
        clock_t start, end, temp;
        start = clock();
        float * side_length = (float * ) malloc(n * sizeof(float));
        float * area = (float * ) malloc(n * sizeof(float));
        float * inradius = (float * ) malloc(n * sizeof(float));
        float * circumradius = (float * ) malloc(n * sizeof(float));
        float * perimeter = (float * ) malloc(n * sizeof(float));
        float * interior_angle = (float * ) malloc(n * sizeof(float));
        float * exterior_angle = (float * ) malloc(n * sizeof(float));

        for (int i = 0; i < n; i++) {
            side_length[i] = (float)(rand() % 10000) / 100;
        }

        polygon_calc(side_length, area, inradius, circumradius, perimeter, interior_angle, exterior_angle, sides, n);

        /*for (int i = 0; i < n; i++) {
        	printf("input: %f\narea: %f\tinradius: %f\tcircumradius: %f\nperimeter: %f\tinterior: %f\texterior: %f\n", side_length[i],area[i],inradius[i],circumradius[i],perimeter[i],interior_angle[i],exterior_angle[i]);
        }*/
        end = clock();
        printf("\n\nN: %d\t\ttime: %lf\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
        free(area);
        free(inradius);
        free(circumradius);
        free(perimeter);
        free(interior_angle);
        free(exterior_angle);
        free(side_length);
        n *= 10;
    }
    return 0;
}

void polygon_calc(float * input, float * area, float * inradius, float * circumradius, float * perimeter, float * interior, float * exterior, int sides, int size) {
    for (int i = 0; i < size; i++) {
        area[i]=((sides*input[i]*input[i])/(4.0f*tan(M_PI/sides)));
		perimeter[i]=(sides*input[i]);
		interior[i]=((sides-2)*(180.0f/sides));
		exterior[i]=(360.0f/sides);
		circumradius[i]=((input[i]/2.0f)/sin(M_PI/sides));
		inradius[i]=((2.0f*area[i])/(perimeter[i]));
    }
}