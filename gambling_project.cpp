#include <iostream> 

#include <cstdlib> 

#include <ctime> 

using namespace std;



void five_balls(int[], int);

void selection_sort(int[], int);

void duplicate_check(int[], int);

void swap(int &, int &);

void show_picks(int[], int, int);



unsigned seed = time(0);



int main()

{

    const int RED_BALLS = 26;

    int games;

    srand(seed);



    do

    {

        cout << "How many games would you like to play (max 24 games)? ";

        cin >> games;

    } while (games > 25);



    const int BALLS = 5;

    int lucky_numbers[BALLS];

    int six_ball;



    for (int play = 1; play <= games; play++)

    {

        five_balls(lucky_numbers, BALLS);

        selection_sort(lucky_numbers, BALLS);

        duplicate_check(lucky_numbers, BALLS);

        six_ball = rand() % (RED_BALLS - 1 + 1) + 1;

        show_picks(lucky_numbers, BALLS, six_ball);

    }

}



void five_balls(int num_list[], int size)

{

    const int WHITE_BALLS = 69, WHITE_PICKS = 5;



    for (int index = 0; index < WHITE_PICKS; index++)

        num_list[index] = rand() % (WHITE_BALLS - 1 + 1) + 1;

}



void selection_sort(int num_list[], int size)

{

    int min_index, min_value;



    for (int start = 0; start < (size - 1); start++)

    {

        min_index = start;

        min_value = num_list[start];

        for (int index = start + 1; index < size; index++)

        {

            if (num_list[index] < min_value)

            {

                min_value = num_list[index];

                min_index = index;

            }

        }

        swap(num_list[min_index], num_list[start]);

    }

}



void swap(int &a, int &b)

{

    int temp = a;

    a = b;

    b = temp;

}



void duplicate_check(int num_list[], int size)

{

    int count = 0;

    const int WHITE_BALLS = 69;



    while (count < (size - 2))

    {

        if (num_list[count] == num_list[count + 1])

        {

            num_list[count + 1] = rand() % (WHITE_BALLS - 1 + 1) + 1;

            selection_sort(num_list, size);

            count = 0;

        }

        else

            count++;

    }

}



void show_picks(int num_list[], int size, int six_num)

{

    cout << "\nWhite Balls are: ";

    for (int index = 0; index < 5; index++)

        cout << num_list[index] << " ";

    cout << "Power Ball is: " << six_num << endl;

}