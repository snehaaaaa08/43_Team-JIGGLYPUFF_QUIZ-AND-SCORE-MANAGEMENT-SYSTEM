#ifndef QUESTIONS_H
#define QUESTIONS_H

struct Question {
    char text[120];
    char options[4][40];
    char correct_answer;
    char hint[80];
};

// Add or edit as many questions as you want here
struct Question quiz[] = {
    {"Primary function of ALU?", {"A. Storage", "B. Math/Logic", "C. Power", "D. I/O"}, 'B', "Handles CPU math."},
    {"Keyword for constant in C?", {"A. static", "B. volatile", "C. const", "D. fixed"}, 'C', "Short for constant."},
    {"Size of float (32-bit)?", {"A. 2 bytes", "B. 4 bytes", "C. 8 bytes", "D. 16 bytes"}, 'B', "Same size as int."},
    {"Logical AND operator in C?", {"A. &", "B. &&", "C. ||", "D. !"}, 'B', "Uses two ampersands."},
    {"What skips a loop iteration?", {"A. break", "B. exit", "C. continue", "D. return"}, 'C', "Continues to next step."}
};

// Automatically counts the number of questions
int total_questions = sizeof(quiz) / sizeof(quiz[0]);

#endif