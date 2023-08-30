#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    float f1(float x, int intensity);
    float f2(float x, int intensity);
    float f3(float x, int intensity);
    float f4(float x, int intensity);
    
#ifdef __cplusplus
}
#endif

double calc_numerical_integration(int functionid, int a, int b, int n, int intensity) {
    double sum = 0.0;
    double delta_x = (b - a) / n;

    for (int i = 0; i < n; i++) {
        double x_i = a + (i + 0.5) * delta_x;
        float f_x_i = 0.0;

        switch (functionid) {
            case 1:
                f_x_i = f1(x_i, intensity);
                break;
            case 2:
                f_x_i = f2(x_i, intensity);
                break;
            case 3:
                f_x_i = f3(x_i, intensity);
                break;
            case 4:
                f_x_i = f4(x_i, intensity);
                break;
            default:
                fprintf(stderr, "Invalid functionid.\n");
                return -1.0;
        }

        sum += f_x_i;
    }

    return sum * delta_x;
}

int main (int argc, char* argv[]) {
    if (argc < 6) {
        fprintf(stderr, "usage: %s <functionid> <a> <b> <n> <intensity>\n", argv[0]);
        return -1;
    }

    int function_id = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int n = atoi(argv[4]);
    int intensity = atoi(argv[5]);

    clock_t t;
    t = clock();
    double result = calc_numerical_integration(function_id, a, b, n, intensity);
    t = clock() - t;
    float time_taken = ((double)t) / CLOCKS_PER_SEC;
    
    printf("Result: %lf\n", result);
    fprintf(stderr, "Time taken: %f seconds\n", time_taken);

    return 0;
}
