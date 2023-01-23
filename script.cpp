#include <iostream>
#include <cstdio>

const int N = 256; // grid size
const double dt = 0.01; // time step
const double waveSpeed = 1; // wave speed

double h[N][N]; // height field
double h_prev[N][N]; // previous height field

void update() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            h_prev[i][j] = h[i][j];
        }
    }

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            h[i][j] = 2 * h_prev[i][j] - h[i][j] + waveSpeed * waveSpeed * dt * dt * (h_prev[i+1][j] + h_prev[i-1][j] + h_prev[i][j+1] + h_prev[i][j-1] - 4*h_prev[i][j]);
        }
    }
}

int main() {
    while (true) {
        update();
    }
    return 0;
}
