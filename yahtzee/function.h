#ifndef FUNCTION_H
#define FUNCTION_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro(void);
void main_gameplay (void);
int gameplay_menu (void);
void roll_dice (int dice_values[5], int num_items);
void print_die (int die[5], int size, int c_combos[13]);
void reroll (int die[5], int size, int c_combo[13], char player[50], int round);
void choose_combo (int die[5], int size, int c_combo[13], int scores[13], char player[50], int round);


void print_score (int scores[13], int player);
void print_combos (int c_combos[13]);

int ones (int die[5], int c_combo[13], int points[13]);
int twos (int die[5], int c_combo[13], int points[13]);
int threes (int die[5], int c_combo[13], int points[13]);
int fours (int die[5], int c_combo[13], int points[13]);
int fives (int die[5], int c_combo[13], int points[13]);
int sixes (int die[5], int c_combo[13], int points[13]);

int three_of_a_kind (int die[5], int c_combo[13], int points[13]);
int four_of_a_kind (int die[5], int c_combo[13], int points[13]);
int full_house (int die[5], int c_combo[13], int points[13]);
int sm_straight (int die[5], int c_combo[13], int points[13]);
int lg_straight (int die[5], int c_combo[13], int points [13]);
int yahtzee (int die[5], int c_combo[13], int points [13]);
int chance (int die[5], int c_combo[13], int points [13]);


void end_game (int p1_points[13], int p2_points[13]);

#endif // FUNCTION_H
