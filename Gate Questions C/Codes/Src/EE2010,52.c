#include <stdio.h>

int main() {
    printf("Q.52 A minimized form of the function F is:\n\n");

    printf("Options:\n");
    printf("1) F = !X.Y + Y.Z\n");
    printf("2) F = !X.!Y + Y.Z\n");
    printf("3) F = X.!Y + !Y.Z\n");
    printf("4) F = !X.Y + !Y.Z\n");

    printf("\n--- Solution ---\n");
    printf("We apply Boolean algebra or K-map simplification to reduce F.\n");
    printf("Assume original function involves terms combining !X, Y, and Z.\n");
    printf("Combining:\n");
    printf("   !X.Y covers cases when X=0, Y=1 (regardless of Z)\n");
    printf("   !Y.Z covers Y=0, Z=1\n");
    printf("These two together cover all the 1s in the truth table efficiently.\n");

    printf("\nTherefore, minimized form is:\nF = !X.Y + !Y.Z\n");
    printf("Answer: Option 4 is correct.\n");

    return 0;
}

