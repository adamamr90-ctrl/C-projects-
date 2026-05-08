#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Seed for random functions (legacy rand usage in case needed later)
    srand(time(0));

    cout << "Welcome to our Quiz Game!\n";

    // Player name input
    cout << "Enter your name: ";
    string name;
    cin >> name;

    cout << "Good luck, " << name << "! Let's begin.\n";

    // ================= EASY QUESTIONS =================
    vector<string> easy_questions =
    {
        "What is the capital of Egypt?",
        "What is the sum of 5 and 18?",
        "What gas do plants absorb from the atmosphere?",
        "What is the largest planet in our solar system?",
        "What is the boiling point of water in Celsius?",
        "Which organ in the human body produces insulin?",
        "How many legs does a spider have?"
    };

    vector<vector<string>> easy_choices =
    {
        {"a. Cairo", "b. Alexandria", "c. Giza", "d. Suez"},
        {"a. 12", "b. 14", "c. 23", "d. 30"},
        {"a. Oxygen", "b. Carbon Dioxide", "c. Nitrogen", "d. Hydrogen"},
        {"a. Mars", "b. Jupiter", "c. Saturn", "d. Earth"},
        {"a. 90", "b. 95", "c. 100", "d. 105"},
        {"a. Liver", "b. Pancreas", "c. Kidney", "d. Stomach"},
        {"a. 6", "b. 8", "c. 12", "d. 7"}
    };

    vector<char> easy_answers = {'a', 'c', 'b', 'b', 'c', 'b', 'b'};

    // ================= MEDIUM QUESTIONS =================
    vector<string> medium_questions =
    {
        "What planet is called the Red Planet?",
        "Who wrote the play 'Romeo and Juliet'?",
        "Which element has the chemical symbol 'Fe'?",
        "Which scientist proposed the laws of motion?",
        "What is the chemical formula for table salt?",
        "What is the capital city of Canada?"
    };

    vector<vector<string>> medium_choices =
    {
        {"a. Mars", "b. Jupiter", "c. Venus", "d. Earth"},
        {"a. William Shakespeare", "b. Charles Dickens", "c. Mark Twain", "d. Jane Austen"},
        {"a. Gold", "b. Iron", "c. Fluorine", "d. Silver"},
        {"a. Einstein", "b. Newton", "c. Galileo", "d. Tesla"},
        {"a. NaCl", "b. H2O", "c. CO2", "d. C6H12O6"},
        {"a. Toronto", "b. Vancouver", "c. Ottawa", "d. Montreal"}
    };

    vector<char> medium_answers = {'a', 'a', 'b', 'b', 'a', 'c'};

    // ================= HARD QUESTIONS =================
    vector<string> hard_questions =
    {
        "What year did the French Revolution begin?",
        "Who developed the theory of general relativity?",
        "What is the square root of 625?",
        "Which ancient civilization built Machu Picchu?",
        "What is the value of Pi to three decimal places?",
        "Who painted the ceiling of the Sistine Chapel?",
        "What is the smallest prime number?"
    };

    vector<vector<string>> hard_choices =
    {
        {"a. 1789", "b. 1776", "c. 1804", "d. 1812"},
        {"a. Newton", "b. Einstein", "c. Galileo", "d. Hawking"},
        {"a. 15", "b. 20", "c. 25", "d. 30"},
        {"a. Maya", "b. Inca", "c. Aztec", "d. Olmec"},
        {"a. 3.142", "b. 3.141", "c. 3.143", "d. 3.140"},
        {"a. Leonardo da Vinci", "b. Michelangelo", "c. Raphael", "d. Donatello"},
        {"a. 0", "b. 1", "c. 2", "d. 3"}
    };

    vector<char> hard_answers = {'a', 'b', 'c', 'b', 'a', 'b', 'c'};

    // Index lists used for shuffling questions
    vector<int> easy_indices(easy_questions.size());
    vector<int> medium_indices(medium_questions.size());
    vector<int> hard_indices(hard_questions.size());

    int high_score = 0;
    char play_again;

    // Random engine for shuffling
    random_device rd;
    mt19937 g(rd());

    do
    {
        // Reset indices before each round
        for (int i = 0; i < easy_indices.size(); i++) easy_indices[i] = i;
        for (int i = 0; i < medium_indices.size(); i++) medium_indices[i] = i;
        for (int i = 0; i < hard_indices.size(); i++) hard_indices[i] = i;

        // Shuffle question order
        shuffle(easy_indices.begin(), easy_indices.end(), g);
        shuffle(medium_indices.begin(), medium_indices.end(), g);
        shuffle(hard_indices.begin(), hard_indices.end(), g);

        int score = 0;

        // User selects number of questions per difficulty
        int num_easy, num_medium, num_hard;

        cout << "\nEnter number of EASY questions (1 to 5): ";
        cin >> num_easy;
        if (num_easy < 1 || num_easy > easy_questions.size())
        {
            cout << "Invalid input. Defaulting to 3 easy questions.\n";
            num_easy = 3;
        }

        cout << "Enter number of MEDIUM questions (1 to 5): ";
        cin >> num_medium;
        if (num_medium < 1 || num_medium > medium_questions.size())
        {
            cout << "Invalid input. Defaulting to 3 medium questions.\n";
            num_medium = 3;
        }

        cout << "Enter number of HARD questions (1 to 5): ";
        cin >> num_hard;
        if (num_hard < 1 || num_hard > hard_questions.size())
        {
            cout << "Invalid input. Defaulting to 3 hard questions.\n";
            num_hard = 3;
        }

        // Store selected questions
        vector<pair<string, vector<string>>> selected_questions;
        vector<char> selected_answers;

        // Add easy questions
        for (int i = 0; i < num_easy; i++)
        {
            int idx = easy_indices[i];
            selected_questions.push_back({"[Easy] " + easy_questions[idx], easy_choices[idx]});
            selected_answers.push_back(easy_answers[idx]);
        }

        // Add medium questions
        for (int i = 0; i < num_medium; i++)
        {
            int idx = medium_indices[i];
            selected_questions.push_back({"[Medium] " + medium_questions[idx], medium_choices[idx]});
            selected_answers.push_back(medium_answers[idx]);
        }

        // Add hard questions
        for (int i = 0; i < num_hard; i++)
        {
            int idx = hard_indices[i];
            selected_questions.push_back({"[Hard] " + hard_questions[idx], hard_choices[idx]});
            selected_answers.push_back(hard_answers[idx]);
        }

        // Shuffle final mixed question set
        vector<int> final_indices(selected_questions.size());
        for (int i = 0; i < final_indices.size(); i++) final_indices[i] = i;
        shuffle(final_indices.begin(), final_indices.end(), g);

        char answer;
        int num_questions = selected_questions.size();

        // ================= QUIZ LOOP =================
        for (int i = 0; i < num_questions; i++)
        {
            int q = final_indices[i];

            cout << "\n" << selected_questions[q].first << "\n";

            for (string choice : selected_questions[q].second)
            {
                cout << choice << "\n";
            }

            cout << "Your answer (a, b, c, d): ";
            cin >> answer;

            answer = tolower(answer);

            // Validate input
            if (answer < 'a' || answer > 'd')
            {
                cout << "Invalid choice. Please enter a, b, c, or d.\n";
                i--;
                continue;
            }

            // Check answer
            if (answer == selected_answers[q])
            {
                cout << "Correct!\n";
                score++;
            }
            else
            {
                cout << "Wrong answer. The correct answer was " << selected_answers[q] << ".\n";
            }
        }

        // ================= RESULT =================
        float percentage = (score * 100.0) / num_questions;

        cout << "\nFinal Score: " << score << "/" << num_questions << "\n";

        if (percentage == 100)
        {
            cout << "Perfect score! You are a Quiz Master.\n";
        }
        else if (percentage >= 60)
        {
            cout << "Nice job, " << name << "! Almost perfect.\n";
        }
        else
        {
            cout << "Keep practicing, " << name << ". You will improve!\n";
        }

        // High score tracking
        if (score > high_score)
        {
            high_score = score;
            cout << "New high score: " << high_score << "!\n";
        }

        // Replay option
        cout << "\nDo you want to play again? (y/n): ";
        cin >> play_again;

        if (play_again == 'y' || play_again == 'Y')
        {
            cout << "\n===== New Game =====\n";
        }

    } while (play_again == 'y' || play_again == 'Y');

    cout << "\nThanks for playing, " << name << "!\n";

    return 0;
}
