#include <stdio.h>
#include <ctype.h>
#include "questions.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

int main() {
    int choice;
    int marks_per_question = 10;
    int penalty = 2;
    int hint_cost = 3;
    int games_played = 0;
    int high_score = 0;

    while (1) {
        printf("\n%s=== C QUIZ ARENA ===%s\n1. Start Quiz\n2. Rules\n3. Exit\nChoice: ", CYAN, RESET);
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("%sInvalid input!%s\n", RED, RESET);
            continue;
        }

        if (choice == 1) {
            int score = 5;
            char user_answer;

            for (int i = 0; i < total_questions; i++) {
                int hint_used = 0;
                printf("\n%sQuestion %d: %s%s\n", YELLOW, i + 1, quiz[i].text, RESET);
                for (int j = 0; j < 4; j++) {
                    printf("  %s\n", quiz[i].options[j]);
                }

                while (1) {
                    printf("[Points: %d] Answer (A-D) or H for Hint (-%d): ", score, hint_cost);
                    scanf(" %c", &user_answer);
                    user_answer = toupper(user_answer);

                    if (user_answer == 'H' && !hint_used && score >= hint_cost) {
                        score -= hint_cost;
                        hint_used = 1;
                        printf("%sHint: %s%s\n", CYAN, quiz[i].hint, RESET);
                    } else if (user_answer == 'H') {
                        printf("%sHint unavailable or low points!%s\n", RED, RESET);
                    } else if (user_answer >= 'A' && user_answer <= 'D') {
                        break;
                    } else {
                        printf("%sEnter A, B, C, D, or H.%s\n", RED, RESET);
                    }
                }

                if (user_answer == quiz[i].correct_answer) {
                    score += marks_per_question;
                    printf("%sCorrect! +%d%s\n", GREEN, marks_per_question, RESET);
                } else {
                    score -= penalty;
                    printf("%sWrong! Correct Answer: %c (-%d)%s\n", RED, quiz[i].correct_answer, penalty, RESET);
                }
            }

            games_played++;
            if (score > high_score) high_score = score;

            int max_score = 5 + (total_questions * marks_per_question);
            float percentage = (score > 0) ? ((float)score / max_score) * 100 : 0;

            printf("\n%s=== RESULT ===%s\nScore: %d/%d (%.1f%%)\nGrade: ", CYAN, RESET, score, max_score, percentage);
            if (percentage >= 80) printf("%sExcellent%s\n", GREEN, RESET);
            else if (percentage >= 50) printf("%sGood%s\n", YELLOW, RESET);
            else printf("%sNeeds Improvement%s\n", RED, RESET);

        } else if (choice == 2) {
            printf("\nStart: 5 points | Correct: +%d | Wrong: -%d | Hint: -%d\n", marks_per_question, penalty, hint_cost);
        } else if (choice == 3) {
            break;
        } else if (choice == 99) {
            printf("\n%s=== ADMIN PANEL ===%s\nGames Played: %d | High Score: %d\nNew Penalty: ", RED, RESET, games_played, high_score);
            scanf("%d", &penalty);
            printf("%sUpdated!%s\n", GREEN, RESET);
        } else {
            printf("%sInvalid choice!%s\n", RED, RESET);
        }
    }
    return 0;
}