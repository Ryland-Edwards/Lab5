#include <stdlib.h>
#include <stdio.h>

/* The `#define` statements are used to define constants in the code. In this case, `S`, `FG`, `TD`,
`TDFG`, and `TD2P` are defined as constants with the values 2, 3, 6, 7, and 8 respectively. These
constants are used later in the code to represent the values of different scoring plays in a
football game. */
#define S 2 // Safetys
#define FG 3 // Field goals
#define TD 6 // Touchdown
#define TDFG 7 // touchdown + field goal
#define TD2P 8 // touchdown + conversion

void nfl_score_combinations(int target_score) {
    
    /* The `char *scoring_plays[]` is an array of strings that represents the different types of
    scoring plays in a football game. Each element in the array corresponds to a specific scoring
    play, such as a touchdown with a 2-point conversion, a touchdown with a field goal, a touchdown,
    a 3-point field goal, or a safety. */
    char *scoring_plays[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};
    int values[] = {8, 7, 6, 3, 2};

    
    /* The line `for (int td_2pt = 0; td_2pt <= target_score / values[0]; td_2pt++) {` is a for loop
    that iterates over the possible number of touchdown + 2-point conversion combinations. */
    for (int td_2pt = 0; td_2pt <= target_score / values[0]; td_2pt++) {
        /* The line `for (int td_fg = 0; td_fg <= target_score / values[1]; td_fg++) {` is a for loop
        that iterates over the possible number of touchdown + field goal combinations. */
        for (int td_fg = 0; td_fg <= target_score / values[1]; td_fg++) {
            /* The line `for (int td = 0; td <= target_score / values[2]; td++) {` is a for loop that
            iterates over the possible number of touchdowns. */
            for (int td = 0; td <= target_score / values[2]; td++) {
                /* The line `for (int fg = 0; fg <= target_score / values[3]; fg++) {` is a for loop
                that iterates over the possible number of field goals in a scoring combination. */
                for (int fg = 0; fg <= target_score / values[3]; fg++) {
                    /* The line `for (int safety = 0; safety <= target_score / values[4]; safety++) {`
                    is a for loop that iterates over the possible number of safeties in a scoring
                    combination. */
                    for (int safety = 0; safety <= target_score / values[4]; safety++) {
                        /* The `if` statement is checking if the current combination of scoring plays
                        equals the target score. It does this by multiplying the number of each type
                        of scoring play (touchdown + 2-point conversion, touchdown + field goal,
                        touchdown, field goal, safety) by their respective values and summing them
                        up. If the sum is equal to the target score, it means that the current
                        combination of scoring plays adds up to the target score. */
                        if (td_2pt * values[0] + td_fg * values[1] + td * values[2] + fg * values[3] + safety * values[4] == target_score) {
                            printf("%d %s, %d %s, %d %s, %d %s, %d %s\n", td_2pt, scoring_plays[0], td_fg, scoring_plays[1], td, scoring_plays[2], fg, scoring_plays[3], safety, scoring_plays[4]);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int score = 2;
    /* This code block is responsible for taking user input for an NFL score and then calling the
    `nfl_score_combinations` function to calculate and display the possible combinations of scoring
    plays that could result in that score. */
    printf("Enter 0 or 1 to STOP.\n");
    while (score > 1)
    {
        printf("Enter the NFL score: ");
        /* `scanf("%d", &score);` is a function call that reads an integer input from the user and
        stores it in the variable `score`. */
        scanf("%d", &score);
        printf("Possible combinations of scoring plays: \n");
        nfl_score_combinations(score);
        printf("\n");
    }
    return 0;
}