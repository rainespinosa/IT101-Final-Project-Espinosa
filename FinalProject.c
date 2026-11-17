#include <stdio.h>
int main() {
    int choice, size, shape, rows, i, j, spaces, stars;
    int level, length, palindrome, number;
    float grade, total, average;
    char again = 'y', word[100];
    char names[4][12] = {"Prelim", "Midterm", "Pre-Final", "Final"};

    while (again == 'y' || again == 'Y') {
        printf("\n====== MAIN MENU ======\n");
        printf("1. Pattern Generator\n2. Pascal's Triangle\n3. Grade Calculator & Evaluator\n4. Palindrome Checker\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n=== PATTERN GENERATOR ===\nEnter size: ");
            scanf("%d", &size);

            if (size < 1) printf("Invalid size!\n");
            else {
                printf("1. Right Triangle\n2. Square\n3. Isosceles Triangle\n4. Inverted Right Triangle\n5. Christmas Tree\nChoice: ");
                scanf("%d", &shape);

                if (shape < 1 || shape > 5) printf("Invalid shape!\n");
                else {
                    if (shape == 5) rows = 2 * size + 1;
                    else rows = size;

                    for (i = 1; i <= rows; i++) {
                        spaces = 0;
                        stars = size;

                        if (shape == 1) stars = i;
                        else if (shape == 3) {
                            spaces = size - i;
                            stars = 2 * i - 1;
                        }
                        else if (shape == 4) stars = size - i + 1;
                        else if (shape == 5) {
                            if (i <= size) level = i;
                            else if (i < 2 * size) level = i - size + 1;
                            else level = 0;

                            if (level > 0) {
                                spaces = size - level;
                                stars = 2 * level - 1;
                            }
                            else {
                                spaces = size - 1;
                                stars = 1;
                            }
                        }

                        for (j = 0; j < spaces; j++) printf("  ");
                        for (j = 0; j < stars; j++) printf("* ");
                        printf("\n");
                    }
                }
            }
        }

        else if (choice == 2) {
            printf("\n=== PASCAL'S TRIANGLE ===\nEnter rows (1-20): ");
            scanf("%d", &rows);

            if (rows < 1 || rows > 20) printf("Invalid rows!\n");
            else for (i = 0; i < rows; i++) {
                for (j = 0; j < rows - i; j++) printf("  ");

                number = 1;

                for (j = 0; j <= i; j++) {
                    printf("%4d", number);
                    number = number * (i - j) / (j + 1);
                }

                printf("\n");
            }
        }

        else if (choice == 3) {
            printf("\n=== COLLEGE GRADE CALCULATOR ===\n");
            total = 0;

            for (i = 0; i < 4; i++) {
                do {
                    printf("Enter %s grade (1.0-5.0): ", names[i]);
                    scanf("%f", &grade);

                    if (grade < 1 || grade > 5)
                        printf("Invalid grade!\n");

                } while (grade < 1 || grade > 5);

                total += grade;
            }

            average = total / 4;

            printf("\nAverage: %.2f\n", average);

            if (average <= 3.0) printf("Status: PASSED\n");
            else printf("Status: FAILED\n");
        }

        else if (choice == 4) {
            printf("\n=== PALINDROME CHECKER ===\nEnter a word: ");
            scanf("%99s", word);

            length = 0;
            while (word[length] != '\0') length++;

            palindrome = 1;

            for (i = 0; i < length / 2; i++)
                if (word[i] != word[length - 1 - i])
                    palindrome = 0;

            if (palindrome == 1)
                printf("%s is a PALINDROME.\n", word);
            else
                printf("%s is NOT a palindrome.\n", word);
        }

        else if (choice == 5) {
            printf("Thank you for using the program. Goodbye!\n");
            return 0;
        }

        else printf("Invalid choice!\n");

        printf("\nDo you want to try another operation? (Y/N): ");
        scanf(" %c", &again);

        while (again != 'y' && again != 'Y' &&
               again != 'n' && again != 'N') {
            printf("Please enter Y or N: ");
            scanf(" %c", &again);
        }

        if (again == 'y' || again == 'Y') {
            printf("\n========================================\n");
            printf("           RETURNING TO MENU\n");
            printf("========================================\n\n");
        }
    }

    printf("\nProgram ended. Have a great day!\n");
    return 0;
}