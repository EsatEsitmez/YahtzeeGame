#include "function.h"


void main_gameplay (void)
{
printIntro();

    // Declare variables
    char naam1[50];
    char naam2 [50];
    int die[5] = {0}, p1_scores[13] = {0}, p1_combinations[13] = {0}, p2_scores[13] = {0}, p2_combinations[13] = {0}, player = 1, turn = 0;

    // Set rand string
    srand((unsigned int)time(NULL));

    printf("Speler 1 mag zijn naam invoeren: ");
    scanf("%s", &naam1);




    printf("Speler 2 mag zijn naam invoeren: ");
    scanf("%s", &naam2);


    while(gameplay_menu())
    {

        while(turn < 13)
        {

            // SPELER 1

            printf("\n\t\t\t\t\t*********\t %s \t\t**********\n", naam1);
            printf("\t\t\t\t\t*********\t ROUND %d\t**********\n\n", turn);
            roll_dice(die, 5);
            print_die(die, 5, p1_combinations);
            reroll(die, 5, p1_combinations,naam1,turn);
            choose_combo(die, 5, p1_combinations, p1_scores,naam1,turn);


            printf("\n\t\t\t\t\t*********\t %s \t\t**********\n", naam1);
            printf("\t\t\t\t\t*********\t ROUND %d\t**********\n\n", turn);
            print_score (p1_scores, 1);

            printf("\n\nPress any key to switch to %s ", naam2);
            system("pause > nul");




            // Speler 2

            printf("\n\t\t\t\t\t*********\t %s \t\t**********\n", naam2);
            printf("\t\t\t\t\t*********\t ROUND %d\t**********\n\n", turn);
            roll_dice(die, 5);
            print_die(die, 5,p2_combinations);
            reroll(die, 5, p1_combinations,naam2,turn);
            choose_combo(die, 5, p2_combinations, p2_scores,naam2,turn);


            printf("\n\t\t\t\t\t*********\t %s \t\t**********\n",naam2);
            printf("\t\t\t\t\t*********\t ROUND %d\t**********\n\n", turn);
            print_score (p2_scores, 2);

            system("pause\n");



            turn++;

        }


        end_game(p1_scores, p2_scores);

    }
    printf("Tot ziens!\n\n");
}

int gameplay_menu (void)
{
    int option = 0, play_game = 0;


    do
    {
        do
        {
            printf("Kies een optie door het bijbehorende nummer in te voeren: \n1. Print spelregels \n2. Start een spelletje Yahtzee \n3. Exit\n");
            scanf("%d", &option);
        }
        while ((option != 1) && (option != 2) && (option != 3));

        switch (option)
        {
        case 1: //print spel regels



            printf("\nSpel regels:\n\n");
            printf("De scorekaart die voor Yahtzee wordt gebruikt, bestaat uit twee delen. Een bovenste gedeelte en een onderste gedeelte. Een totaal van\n");
            printf("dertien boxen of dertien scorecombinaties zijn verdeeld over de secties. Het bovenste gedeelte bestaat uit\n");
            printf("van dozen die worden gescoord door de waarde van de dobbelstenen op te tellen die overeenkomen met de vlakken van de doos. Als een speler\n");
            printf("vier 3en gooit, dan is de score die in het vak 3 wordt geplaatst de som van de dobbelstenen, namelijk 12. Zodra een speler\n");
            printf("gekozen om een box te scoren, mag deze niet worden gewijzigd en is de combinatie niet langer in het spel voor toekomstige rondes.\n");
            printf("Als de som van de scores in het bovenste deel groter is dan of gelijk is aan 63, dan zijn dat 35 punten meer\n");
            printf("toegevoegd aan de totaalscore van de spelers als bonus. Het onderste gedeelte bevat een aantal pookachtige combinaties.\n\n");
            break;
        case 2:
            play_game = 1;
            break;
        case 3:
            play_game = 0;
            break;
        default:
            printf("Voer een geldig antwoord in.\n");
        }
    }
    while ((option != 2) && (option != 3));


    return play_game;
}


void roll_dice (int die[5], int size)
{
    char cont = 0;
    int index = 0;

    printf("Druk op een willekeurige toets om de dobbelstenen te gooien.\n\n");
    system("pause > nul");


    for (index = 0; index < size; ++index)
    {
        die[index] = rand() % 6 + 1;
    }

}


void print_die (int die[5], int size, int c_combos[13])
{
    int index = 0;
    int line = 1;

    // Prints 5 lines
    while (line <= 5)
    {
        // One line at a time
        switch (line)
        {
        case 1:
            // Loops through each dice
            while(index<size)
            {
                switch(die[index])
                {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        printf("-----	");
                        break;

                }
                index++;
            }
            printf("\n");
            line++;
            index = 0;
            break;
        case 2:
            while(index<size)
            {
                switch(die[index])
                {
                    case 1:
                        printf("|   |	");
                        break;
                    case 2:
                        printf("|o  |	");
                        break;
                    case 3:
                        printf("|o  |	");
                        break;
                    case 4:
                        printf("|o o|	");
                        break;
                    case 5:
                        printf("|o o|	");
                        break;
                    case 6:
                        printf("|o o|	");
                        break;

                }
                index++;
            }
            printf("\n");
            line++;
            index = 0;
            break;
        case 3:
            while(index<size)
            {
                switch(die[index])
                {
                    case 1:
                        printf("| o |	");
                        break;
                    case 2:
                        printf("|   |	");
                        break;
                    case 3:
                        printf("| o |	");
                        break;
                    case 4:
                        printf("|   |	");
                        break;
                    case 5:
                        printf("| o |	");
                        break;
                    case 6:
                        printf("|o o|	");
                        break;

                }
                index++;
            }
            printf("\n");
            line++;
            index = 0;
            break;
        case 4:
            while(index<size)
            {
                switch(die[index])
                {
                    case 1:
                        printf("|   |	");
                        break;
                    case 2:
                        printf("|  o|	");
                        break;
                    case 3:
                        printf("|  o|	");
                        break;
                    case 4:
                        printf("|o o|	");
                        break;
                    case 5:
                        printf("|o o|	");
                        break;
                    case 6:
                        printf("|o o|	");
                        break;

                }
                index++;
            }
            printf("\n");
            line++;
            index = 0;
            break;
        case 5:
            while(index<size)
            {
                switch(die[index])
                {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        printf("-----	");
                        break;

                }
                index++;
            }
            printf("\n\n");
            line++;
            break;
        }
    }

    print_combos(c_combos);

}


void reroll (int die[5], int size, int c_combo[13], char player [50], int round)
{

    int number = 0;
    int index = 0;
    int reroll_index = 0;
    int die_reroll = 0;
    //int die_reroll[5] = {0};

    for (index = 0; index<2; index++)
    {
        do
        {
            printf("Hoeveel dobbelstenen zou je opnieuw willen gooien? Of, voer 0 in om deze poging to behouden. \n");
            scanf("%d", &number);

        } while ((number!=1) && (number!=2) && (number!=3) && (number!=4) && (number!=5) && (number!=0));



        if (number != 0)
        {
            for (reroll_index = 0; reroll_index < number; reroll_index++)
            {

                    do
                    {
                        printf("Voer een enkele dobbelsteen in die u opnieuw zou willen gooien: \n");
                        scanf("%d", &die_reroll);
                        die[die_reroll-1] = rand() % 6 + 1;
                    }
                    while((die_reroll != 5) && (die_reroll != 1) && (die_reroll != 2) && (die_reroll != 3) && (die_reroll != 4));

            }
        }
        else
        {break;}

    printf("\t\t\t\t\t*********\t %s \t\t**********\n", player);
    printf("\t\t\t\t\t*********\t ROUND %d\t**********\n\n", round);

    print_die(die, 5,c_combo);
    }
}


void choose_combo (int die[5], int size, int c_combo[13], int scores[13], char player[50], int round)
{
    int selection = 0, index = 0, is_combo_valid = 0;



    printf("\t\t\t\t\t*********\t %s \t\t**********\n", player);
    printf("\t\t\t\t\t*********\t ROUND %d\t**********\n\n", round);
    print_die(die, 5, c_combo);

    // Vraagt gebruiker om combinatie, herhaal als combo eerder is gebruikt
    do
    {
        printf("Voer de combinatie in die u wilt gebruiken: ");
        scanf("%d", &selection);

        switch(selection)
        {
        case 1:
            is_combo_valid = ones(die,c_combo,scores);

            break;
        case 2:
            is_combo_valid = twos(die,c_combo,scores);

            break;
        case 3:
            is_combo_valid = threes(die,c_combo,scores);

            break;
        case 4:
            is_combo_valid = fours(die,c_combo,scores);

            break;
        case 5:
            is_combo_valid = fives(die,c_combo,scores);

            break;
        case 6:
            is_combo_valid = sixes(die,c_combo,scores);

            break;
        case 7:
            is_combo_valid = three_of_a_kind(die,c_combo,scores);

            break;
        case 8:
            is_combo_valid = four_of_a_kind(die,c_combo, scores);

            break;
        case 9:
            is_combo_valid = full_house(die,c_combo, scores);

            break;
        case 10:
            is_combo_valid = sm_straight(die, c_combo, scores);

            break;
        case 11:
            is_combo_valid = lg_straight(die, c_combo, scores);

            break;
        case 12:
            is_combo_valid = yahtzee(die, c_combo, scores);

            break;
        case 13:
            is_combo_valid = chance(die, c_combo, scores);

            break;
        default:
            printf("Geef het correcte optie.\n\n");
            break;
        }

    }
    while(!is_combo_valid);


}


void print_combos (int c_combo[13])
{
    // Drukt alle combinaties af, of een X als deze is gebruikt
    if (c_combo[0] == 0)
    {printf ("1. Sum of 1s\n");}
    else {printf ("X. Sum of 1s\n");}

    if (c_combo[1] == 0)
    {printf ("2. Sum of 2s\n");}
    else {printf ("X. Sum of 2s\n");}

    if (c_combo[2] == 0)
    {printf ("3. Sum of 3s\n");}
    else {printf ("X. Sum of 3s\n");}

    if (c_combo[3] == 0)
    {printf ("4. Sum of 4s\n");}
    else {printf ("X. Sum of 4s\n");}

    if (c_combo[4] == 0)
    {printf ("5. Sum of 5s\n");}
    else {printf ("X. Sum of 5s\n");}

    if (c_combo[5] == 0)
    {printf ("6. Sum of 6s\n");}
    else {printf ("X. Sum of 6s\n");}

    if (c_combo[6] == 0)
    {printf ("7. Three of a kind\n");}
    else {printf ("X. Three of a kind\n");}

    if (c_combo[7] == 0)
    {printf ("8. Four of a kind\n");}
    else {printf ("X. Four of a kind\n");}

    if (c_combo[8] == 0)
    {printf ("9. Full house\n");}
    else {printf ("X. Full house\n");}

    if (c_combo[9] == 0)
    {printf ("10. Small Straight\n");}
    else {printf ("X. Small Straight\n");}

    if (c_combo[10] == 0)
    {printf ("11. Large Straight\n");}
    else {printf ("X. Large Straight\n");}

    // Kan een onbeperkt aantal keren worden gebruikt
    printf ("12. YAHTZEE\n");

    if (c_combo[12] == 0)
    {printf ("13. Chance\n\n");}
    else {printf ("X. Chance\n\n");}
}

void print_score (int scores[13], int player)
{
    int sum = 0, index = 0;
    for (index= 0; index<13; index++)
    {
        sum = scores[index] + sum;
    }
    printf("Player %d's score is nu %d.\n", player, sum);
}

int ones (int die[5], int c_combo[13], int points[13])
{
    int index = 0, sum = 0, value = 0;

    if (c_combo[0] == 0)
    {
        c_combo[0] = 1;
        value = 1;
        for (index= 0; index<5; index++)
        {
            if(die[index] == 1)
            {sum = sum + 1;}
        }
        points[0] = sum;
    }
    return value;
}


int twos (int die[5], int c_combo[13], int points[13])
{
    int index = 0, sum = 0, value = 0;

    if (c_combo[1] == 0)
    {
        c_combo[1] = 1;
        value = 1;
        for (index= 0; index<5; index++)
        {
            if(die[index] == 2)
            {sum = sum + 1;}
        }
        points[1] = sum*2;
    }
    return value;
}

int threes (int die[5], int c_combo[13], int points[13])
{
    int index = 0, sum = 0, value = 0;

    if (c_combo[2] == 0)
    {
        c_combo[2] = 1;
        value = 1;
        for (index= 0; index<5; index++)
        {
            if(die[index] == 3)
            {sum = sum + 1;}
        }
        points[2] = sum*3;
    }
    return value;
}


int fours (int die[5], int c_combo[13], int points[13])
{
    int index = 0, sum = 0, value = 0;

    if (c_combo[3] == 0)
    {
        c_combo[3] = 1;
        value = 1;
        for (index= 0; index<5; index++)
        {
            if(die[index] == 4)
            {sum = sum + 1;}
        }
        points[3] = sum*4;
    }
    return value;
}


int fives (int die[5], int c_combo[13], int points[13])
{
    int index = 0, sum = 0, value = 0;

    if (c_combo[4] == 0)
    {
        c_combo[4] = 1;
        value = 1;
        for (index= 0; index<5; index++)
        {
            if(die[index] == 5)
            {sum = sum + 1;}
        }
        points[4] = sum*5;
    }
    return value;
}


int sixes (int die[5], int c_combo[13], int points[13])
{
    int index = 0, sum = 0, value = 0;

    if (c_combo[5] == 0)
    {
        c_combo[5] = 1;
        value = 1;
        for (index= 0; index<5; index++)
        {
            if(die[index] == 6)
            {sum = sum + 1;}
        }
        points[5] = sum*6;
    }
    return value;
}


int three_of_a_kind (int die[5], int c_combo[13], int points[13])
{
    int number = 0, result = 0, sum = 0;

    // Controleert of combo eerder is gebruikt
    if (c_combo[6] == 0)
    {
        result = 1;
        c_combo[6] = 1; // Stelt combo in op gebruikt
        for (number = 1; number<7; number++)
        {
            sum = 0;

            if (die[0] == number)
            {sum = sum +1;}
            if (die[1] == number)
            {sum = sum +1;}
            if (die[2] == number)
            {sum = sum +1;}
            if (die[3] == number)
            {sum = sum +1;}
            if (die[4] == number)
            {sum = sum +1;}

            // Voegt punten toe als three of a kind
            if (sum>= 3)
            {
                points[6] = die [0] + die[1] + die[2] + die[3] + die[4];
                break;
            }
        }

    }
    return result;
}

int four_of_a_kind (int die[5], int c_combo[13], int points[13])
{
    int number = 0, result = 0, sum = 0;

    // Controleer of combo eerder is gebruikt
    if (c_combo[7] == 0)
    {
        c_combo[7] = 1; // Stelt combo in op gebruikt
        // Controleert of een dobbelsteen overeenkomt met een getal, als dit het geval is, wordt dit toegevoegd aan een variabele "som". if sum = 3, then it breaks. Herhaal anders met number+1.
        for (number = 1; number>5; number++)
        {
            sum = 0;

            if (die[0] == number)
            {sum = sum +1;}
            if (die[1] == number)
            {sum = sum +1;}
            if (die[2] == number)
            {sum = sum +1;}
            if (die[3] == number)
            {sum = sum +1;}
            if (die[4] == number)
            {sum = sum +1;}

            if (sum>= 4)
            {
                points[7] = die [0] + die[1] + die[2] + die[3] + die[4];
                break;
            }
        }
        result = 1;
    }

    return result;
}


int full_house (int die[5], int c_combo[13], int points[13])
{
    int number = 0, result = 0, sum1 = 0, sum2 = 0, three=0, two=0, number2 = 0;

    // Controleert of combo eerder is gebruikt
    if (c_combo[8] == 0)
    {
        c_combo[8] = 1; // Stelt combo in op gebruikt

        // Stelt de retourwaarde (indien gebruikt of niet) in op 1
        result = 1;

        //Controleert op een three of a kind
        for (number = 1; number<7; number++)
        {
            sum1 = 0;

            if (die[0] == number)
            {sum1 = sum1 +1;}
            if (die[1] == number)
            {sum1 = sum1 +1;}
            if (die[2] == number)
            {sum1 = sum1 +1;}
            if (die[3] == number)
            {sum1 = sum1 +1;}
            if (die[4] == number)
            {sum1 = sum1 +1;}

            if (sum1== 3)
            {
                break;
            }
        }

        // Controleert op two of a kind
        for (number2 = 1; number2<7; number2++)
        {
            sum2 = 0;

            if (die[0] == number2)
            {sum2 = sum2 +1;}
            if (die[1] == number2)
            {sum2 = sum2 +1;}
            if (die[2] == number2)
            {sum2 = sum2 +1;}
            if (die[3] == number2)
            {sum2 = sum2 +1;}
            if (die[4] == number2)
            {sum2 = sum2 +1;}

            // Als de two of the kind hetzelfde nummer is als de three of a kind, negeer het dan
            if (number2 == number)
            {sum2 = 0;}

            if (sum2== 2)
            {
                if (sum2 + sum1 == 5)
                {points[8] = 25;}
                break;
            }
        }
    }
    return result;

}

int sm_straight (int die[5], int c_combo[13], int points [13])
{
    int index = 0, temp = 0, passes = 0, sum=0, result=0;

    // Controleert of combo is gebruikt
    if (c_combo[9] == 0)
    {
        result = 1;

        c_combo[9] = 1;
        // Sorteer op oplopende volgorde
        for (passes = 1; passes < 5; passes++)
        {
            for (index = 0; index < 5 - passes; index++)
            {
                if (die[index] > die[index + 1])
                    {// swap
                    temp = die[index];
                    die[index] = die[index+1];
                    die[index+1] = temp;
                }
            }
        }

    // Controleer op small straight
    for (index = 4; index>0; index--)
        {
            if (die[index] == die[index -1] + 1)
            {sum++;}

        }

    // Geef punten
    if (sum>=3)
    {points[9] = 30;}
    }

    return result;
}


int lg_straight (int die[5], int c_combo[13], int points [13])
{
    int index = 0, temp = 0, passes = 0, sum=0, result=0;

    // Controleert of combo is gebruikt
    if (c_combo[10] == 0)
    {
        result = 1;
        c_combo[10]=1;
        //Sorteer op oplopende volgorde
        for (passes = 1; passes < 5; passes++)
        {
            for (index = 0; index < 5 - passes; index++)
            {
                if (die[index] > die[index + 1])
                    {// swap
                    temp = die[index];
                    die[index] = die[index+1];
                    die[index+1] = temp;
                }
            }
        }

    // Controleer op small straight
    for (index = 4; index>0; index--)
        {
            if (die[index] == die[index -1] + 1)
            {sum++;}

        }

    // Geef punten
    if (sum>=4)
    {points[10] = 30;}
    }

    return result;
}

int yahtzee (int die[5], int c_combo[13], int points[13])
{
    int number = 0, result = 0, sum = 0;

    // Controleer of combo eerder is gebruikt
    if (c_combo[11] == 0)
    {
        c_combo[11] = 1; // Stelt combo in op gebruikt

        for (number=0;number<5;number++)
        {
            sum =0;

            if (die[0] == number)
            {sum = sum +1;}
            if (die[1] == number)
            {sum = sum +1;}
            if (die[2] == number)
            {sum = sum +1;}
            if (die[3] == number)
            {sum = sum +1;}
            if (die[4] == number)
            {sum = sum +1;}

            if (sum== 5)
            {
                points[11] = 50;
            }
        }
        result = 1;
    }

    return result;
}

int chance (int die[5], int c_combo[13], int points[13])
{
    int result = 0, sum =0;

    if (c_combo[12] == 0)
    {
        c_combo[12] = 1;
        result = 1;
        sum = die[0] + die[1] + die[2] + die[3] + die[4];

        points[12] = sum;
    }



    return result;
}


void end_game (int p1_points[13], int p2_points[13])
{
    int sum1 = 0, sum2 = 0, winner = 0, index=0;

    printf("************************************************ Einde Spel ******************************************************\n");

    for (index = 0; index<5; index++)
    {
        sum1 = p1_points[index] + sum1;
    }
    for (index = 0; index<5; index++)
    {
        sum2 = p2_points[index] + sum2;
    }


    if ((p1_points[0]+p1_points[1]+p1_points[2]+p1_points[3]+p1_points[4]+p1_points[5])>63)
    {sum1 = sum1+35;}
    if ((p2_points[0]+p2_points[1]+p2_points[2]+p2_points[3]+p2_points[4]+p1_points[5])>63)
    {sum2 = sum2+35;}

    if (sum2>sum1)
    {
        winner=2;
    }

    if (sum1>sum2)
    {
        winner =1;
    }

    if (sum1 == sum2)
    {
        winner = -1;
    }

    switch (winner)
    {
    case 1:
        printf("\n\nPlayer 1 wint met %d punten!\nPlayer 2 heeft %d punten.\n\n", sum1, sum2);
        break;
    case 2:
        printf("\n\nPlayer 2 wint met %d punten!!\nPlayer 1 heeft %d punten.\n\n", sum2, sum1);
        break;
    case -1:
        printf("Het is een gelijkspel! Beide spelers hebben %d punten.\n\n", sum1);
        break;
    default:
        printf("Error");
    }

    system("pause");


}
void printIntro(void)
{


printf(" wwwwwww           wwwww           wwwwwww eeeeeeeeeeee    l::::l     cccccccccccccccc   ooooooooooo      mmmmmmm    mmmmmmm       eeeeeeeeeeee       \n");
printf("  w:::::w         w:::::w         w:::::wee::::::::::::ee  l::::l   cc:::::::::::::::c oo:::::::::::oo  mm:::::::m  m:::::::mm   ee::::::::::::ee     \n");
printf("  w:::::w       w:::::::w       w:::::we::::::eeeee:::::eel::::l  c:::::::::::::::::co:::::::::::::::om::::::::::mm::::::::::m e::::::eeeee:::::ee    \n");
printf("    w:::::w     w:::::::::w     w:::::we::::::e     e:::::el::::l c:::::::cccccc:::::co:::::ooooo:::::om::::::::::::::::::::::me::::::e     e:::::e   \n");
printf("    w:::::w   w:::::w:::::w   w:::::w e:::::::eeeee::::::el::::l c::::::c     ccccccco::::o     o::::om:::::mmm::::::mmm:::::me:::::::eeeee::::::e    \n");
printf("      w:::::w w:::::w w:::::w w:::::w  e:::::::::::::::::e l::::l c:::::c             o::::o     o::::om::::m   m::::m   m::::me:::::::::::::::::e    \n");
printf("       w:::::w:::::w   w:::::w:::::w   e::::::eeeeeeeeeee  l::::l c:::::c             o::::o     o::::om::::m   m::::m   m::::me::::::eeeeeeeeeee     \n");
printf("        w:::::::::w     w:::::::::w    e:::::::e           l::::l c::::::c     ccccccco::::o     o::::om::::m   m::::m   m::::me:::::::e              \n");
printf("        w:::::::w       w:::::::w     e::::::::e         l::::::lc:::::::cccccc:::::co:::::ooooo:::::om::::m   m::::m   m::::me::::::::e              \n");
printf("         w:::::w         w:::::w       e::::::::eeeeeeee l::::::l c:::::::::::::::::co:::::::::::::::om::::m   m::::m   m::::m e::::::::eeeeeeee      \n");
printf("          w:::w           w:::w         ee:::::::::::::e l::::::l  cc:::::::::::::::c oo:::::::::::oo m::::m   m::::m   m::::m  ee:::::::::::::e      \n");
printf("           www             www            eeeeeeeeeeeeee llllllll    cccccccccccccccc   ooooooooooo   mmmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee      \n");



printf("	   ttttt                             \n");
printf("      ttt:::t                            \n");
printf("      t:::::t                            \n");
printf("      t:::::t                            \n");
printf("ttttttt:::::ttttttt       ooooooooooo    \n");
printf("t:::::::::::::::::t     oo:::::::::::oo  \n");
printf("t:::::::::::::::::t    o:::::::::::::::o \n");
printf("tttttt:::::::tttttt    o:::::ooooo:::::o \n");
printf("      t:::::t          o::::o     o::::o \n");
printf("      t:::::t          o::::o     o::::o \n");
printf("      t:::::t          o::::o     o::::o \n");
printf("      t:::::t    tttttto::::o     o::::o \n");
printf("      t::::::tttt:::::to:::::ooooo:::::o \n");
printf("      tt::::::::::::::to:::::::::::::::o \n");
printf("        tt:::::::::::tt oo:::::::::::oo  \n");
printf("          ttttttttttt     ooooooooooo    \n");


printf("                                        hhhhhhh                     tttt                                                                         \n");
printf("                                        h:::::h                  ttt:::t                                                                         \n");
printf("                                        h:::::h                  t:::::t                                                                         \n");
printf("                                        h:::::h                  t:::::t                                                                         \n");
printf("yyyyyyy           yyyyyyyaaaaaaaaaaaaa   h::::h hhhhh      ttttttt:::::ttttttt    zzzzzzzzzzzzzzzzz    eeeeeeeeeeee        eeeeeeeeeeee          \n");
printf(" y:::::y         y:::::y a::::::::::::a  h::::hh:::::hhh   t:::::::::::::::::t    z:::::::::::::::z  ee::::::::::::ee    ee::::::::::::ee        \n");
printf("  y:::::y       y:::::y  aaaaaaaaa:::::a h::::::::::::::hh t:::::::::::::::::t    z::::::::::::::z  e::::::eeeee:::::ee e::::::eeeee:::::ee      \n");
printf("    y:::::y   y:::::y      aaaaaaa:::::a h::::::h   h::::::h     t:::::t                z::::::z   e:::::::eeeee::::::ee:::::::eeeee::::::e      \n");
printf("     y:::::y y:::::y     aa::::::::::::a h:::::h     h:::::h     t:::::t               z::::::z    e:::::::::::::::::e e:::::::::::::::::e	     \n");
printf("      y:::::y:::::y     a::::aaaa::::::a h:::::h     h:::::h     t:::::t              z::::::z     e::::::eeeeeeeeeee  e::::::eeeeeeeeeee 	     \n");
printf("       y:::::::::y     a::::a    a:::::a h:::::h     h:::::h     t:::::t    tttttt   z::::::z      e:::::::e           e:::::::e         	     \n");
printf("        y:::::::y      a::::a    a:::::a h:::::h     h:::::h     t::::::tttt:::::t  z::::::zzzzzzzze::::::::e          e::::::::e        	     \n");
printf("         y:::::y       a:::::aaaa::::::a h:::::h     h:::::h     tt::::::::::::::t z::::::::::::::z e::::::::eeeeeeee   e::::::::eeeeeeee	     \n");
printf("        y:::::y         a::::::::::aa:::ah:::::h     h:::::h       tt:::::::::::ttz:::::::::::::::z  ee:::::::::::::e    ee:::::::::::::e	     \n");
printf("       y:::::y           aaaaaaaaaa  aaaahhhhhhh     hhhhhhh         ttttttttttt  zzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee      eeeeeeeeeeeeee 	     \n");
printf("      y:::::y                                                                                                                            	     \n");
printf("     y:::::y                                                                                                                             	     \n");
printf("    y:::::y                                                                                                                              	     \n");
printf("   y:::::y                                                                                                                              	     \n");
printf("  yyyyyyy                                                                                                                               	     \n");

printf("                                              \n");
printf("                                              \n\n\n");
}

