
#include<stdio.h>
#include<math.h>
#include <time.h>

// Structure to handle the all points
typedef struct{
    double x;
    double y;
} Vector;


// Equation u(t) = U0*(1 − e^(−t/RC))
double equation(double U0,double R, double C, double t){
    return U0*(1 - exp(-t/(R*C)));
}


int main(){
    // start and end time to calculate the time took by program
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // array of 100 points
    Vector points[100];

    // number of points readed from the file
    int n = 0;
    
    // Capacitor value 1mF 
    double C = 0.01;
    // let intial resistance and U0 are 0 
    double R;
    double U0;

    // open data.bin file in read and binary mode
    FILE *input = fopen("data.bin","rb");

    // exit the program if file not found
    if(!input){
        perror("Error in reading file data.bin");
        return 1;
    }


    // read points from file one by one and add  it to points array of Vector
    while(!feof(input)){
        fread(&points[n],sizeof(Vector),1,input);
        n++;
    }


    int k = 0,bestIndex = 0;

    float u,r;
    // let intial error is INFINITY
    double err, minError = INFINITY;

    // looping through all possiblity of u and r with 0.1 accuracy to find minimum error
    for(u=12.0;u <= 20.0;u += 0.1){
        for(r=10.0;r<=100.0;r += 0.1){
            err = 0.0;
            for(k=0;k<n;k++){
                double y = equation(u,r,C,points[k].x);
                err += pow(y-points[k].y,2.0);  
            }
            // new values of U0 and R0 for which error is less than the minError
            if(err < minError){
                minError = err;
                U0 = u;
                R = r;
            }
        }
    }

    // looping through close to u and r with 0.001 accuracy for better result
    for(u = U0 - 0.5;  u <= U0 + 0.5; u += 0.001){
        for(r = R - 0.5; r <= R + 0.5; r += 0.001){
            err = 0.0;
            for(k=0;k<n;k++){
                double y = equation(u,r,C,points[k].x);
                err += pow(y-points[k].y,2.0);  
            }
            if(err < minError){
                minError = err;
                U0 = u;
                R = r;
            }
        }
    }

    printf("R: %lf \t\t",R);
    printf("U0: %lf\n",U0);

    fclose(input);
    // end time when program works end
    end = clock();
    // calculating elapsed time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time: %lfs\n",cpu_time_used);
    return 0;
}
