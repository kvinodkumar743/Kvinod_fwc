#include <stdio.h>

// Function to simulate MUX output based on A, B, C, D
int mux_output(int A, int B, int C, int D) {
    int I0 = 0;
    int I1 = C;
    int I2 = (!C) && D;
    int I3 = C || D;

    int select = (A << 1) | B;

    switch (select) {
        case 0: return I0;
        case 1: return I1;
        case 2: return I2;
        case 3: return I3;
    }
    return 0;
}

int main() {
    printf("Q.39 The Boolean function realized by the logic circuit is:\n\n");

    printf("Options:\n");
    printf("1) F = Σm(0, 1, 3, 5, 9, 10, 14)\n");
    printf("2) F = Σm(2, 3, 5, 7, 8, 12, 13)\n");
    printf("3) F = Σm(1, 2, 4, 5, 11, 14, 15)\n");
    printf("4) F = Σm(2, 3, 5, 7, 8, 9, 12)\n");

    printf("\n--- Solution ---\n");
    printf("The 4x1 MUX has select lines: S1 = A, S0 = B\n");
    printf("Inputs to MUX:\n");
    printf("  I0 = 0\n");
    printf("  I1 = C\n");
    printf("  I2 = (!C) & D\n");
    printf("  I3 = C | D\n\n");

    printf("Evaluating F(A,B,C,D) for all combinations where F = 1:\n");
    printf("Minterms where F = 1: Σm(");

    int first = 1;
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            for (int C = 0; C <= 1; C++) {
                for (int D = 0; D <= 1; D++) {
                    int F = mux_output(A, B, C, D);
                    if (F) {
                        int minterm = (A << 3) | (B << 2) | (C << 1) | D;
                        if (!first) printf(", ");
                        printf("%d", minterm);
                        first = 0;
                    }
                }
            }
        }
    }

    printf(")\n");
    printf("\nAnswer: Option 2 is correct.\n");

    return 0;
}


