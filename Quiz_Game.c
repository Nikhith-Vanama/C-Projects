#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[256];
    char options[4][100];
    char correct;
};

void loadQuestions(struct Question q[]) {
    strcpy(q[0].question, "Which language is used to write system software?");
    strcpy(q[0].options[0], "a) Python");
    strcpy(q[0].options[1], "b) C");
    strcpy(q[0].options[2], "c) HTML");
    strcpy(q[0].options[3], "d) Java");
    q[0].correct = 'b';

    strcpy(q[1].question, "Which data structure uses LIFO?");
    strcpy(q[1].options[0], "a) Queue");
    strcpy(q[1].options[1], "b) Stack");
    strcpy(q[1].options[2], "c) Array");
    strcpy(q[1].options[3], "d) Linked List");
    q[1].correct = 'b';

    strcpy(q[2].question, "What is the capital of France?");
    strcpy(q[2].options[0], "a) London");
    strcpy(q[2].options[1], "b) Paris");
    strcpy(q[2].options[2], "c) Berlin");
    strcpy(q[2].options[3], "d) Rome");
    q[2].correct = 'b';

    strcpy(q[3].question, "Which keyword is used to return a value in C?");
    strcpy(q[3].options[0], "a) output");
    strcpy(q[3].options[1], "b) send");
    strcpy(q[3].options[2], "c) return");
    strcpy(q[3].options[3], "d) break");
    q[3].correct = 'c';

    strcpy(q[4].question, "How many bits are in a byte?");
    strcpy(q[4].options[0], "a) 4");
    strcpy(q[4].options[1], "b) 8");
    strcpy(q[4].options[2], "c) 16");
    strcpy(q[4].options[3], "d) 32");
    q[4].correct = 'b';
}

int playQuiz() {
    struct Question q[5];
    int score = 0;
    char answer;
    loadQuestions(q);

    printf("\n🎮 Welcome to the Quiz Game!\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Q%d. %s\n", i + 1, q[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", q[i].options[j]);
        }

        printf("Your answer (a/b/c/d): ");
        scanf(" %c", &answer);

        if (answer == q[i].correct) {
            printf("✅ Correct!\n\n");
            score++;
        } else {
            printf("❌ Wrong! Correct answer: %c\n\n", q[i].correct);
        }
    }

    printf("🎯 Your Score: %d out of 5\n", score);
    return score;
}

int main() {
    char choice;

    do {
        playQuiz();
        printf("\n🔁 Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("👋 Thanks for playing!\n");
    return 0;
}
