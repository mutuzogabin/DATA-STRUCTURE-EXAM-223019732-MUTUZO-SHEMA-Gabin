#include <iostream>
#include <cstring>
#include <vector>

struct Question {
    char prompt[100];
    char choices[4][40];
    int correctIdx;
};

class QuizUser {
protected:
    char username[50];
    int score;

public:
    QuizUser(const char* name) : score(0) {
        strncpy(username, name, 49);
        username[49] = '\0';
    }

    virtual ~QuizUser() {}

    virtual int takeQuiz(Question* questions, int numQuestions) = 0;
    virtual void displayResults() = 0;

    const char* getUsername() const { return username; }
    int getScore() const { return score; }
};

class PremiumUser : public QuizUser {
public:
    PremiumUser(const char* name) : QuizUser(name) {}

    int takeQuiz(Question* questions, int numQuestions) override {
        std::cout << "\nPremium Quiz Session for " << username << "\n";
        score = 0;
        
        for (int i = 0; i < numQuestions; ++i) {
            Question* current = questions + i; // Pointer arithmetic
            
            std::cout << "\nQuestion " << (i+1) << ": " << current->prompt << "\n";
            for (int j = 0; j < 4; ++j) {
                std::cout << "  " << (j+1) << ") " << current->choices[j] << "\n";
            }

            int answer;
            std::cout << "Your answer (1-4): ";
            std::cin >> answer;

            if (answer - 1 == current->correctIdx) {
                std::cout << "Correct!\n";
                score += 2; // Premium users get 2 points per correct answer
            } else {
                std::cout << "Incorrect! The right answer was: " 
                          << (current->correctIdx + 1) << "\n";
            }
        }
        return score;
    }

    void displayResults() override {
        std::cout << "\nPremium User " << username << " - Final Score: " 
                  << score << "/" << (score / 2) * 2 << "\n";
    }
};

class GuestUser : public QuizUser {
public:
    GuestUser(const char* name) : QuizUser(name) {}

    int takeQuiz(Question* questions, int numQuestions) override {
        std::cout << "\nGuest Quiz Session for " << username << "\n";
        score = 0;
        
        for (int i = 0; i < numQuestions; ++i) {
            Question* current = questions + i; // Pointer arithmetic
            
            std::cout << "\nQuestion " << (i+1) << ": " << current->prompt << "\n";
            for (int j = 0; j < 4; ++j) {
                std::cout << "  " << (j+1) << ") " << current->choices[j] << "\n";
            }

            int answer;
            std::cout << "Your answer (1-4): ";
            std::cin >> answer;

            if (answer - 1 == current->correctIdx) {
                std::cout << "Correct!\n";
                score += 1; // Guest users get 1 point per correct answer
            } else {
                std::cout << "Incorrect! The right answer was: " 
                          << (current->correctIdx + 1) << "\n";
            }
        }
        return score;
    }

    void displayResults() override {
        std::cout << "\nGuest User " << username << " - Final Score: " 
                  << score << "/" << score << "\n";
    }
};

class QuizEngine {
private:
    Question* questions;
    int numQuestions;
    int capacity;

    QuizUser** users;
    int numUsers;
    int userCapacity;

public:
    QuizEngine() : questions(nullptr), numQuestions(0), capacity(0),
                   users(nullptr), numUsers(0), userCapacity(0) {}

    ~QuizEngine() {
        delete[] questions;
        for (int i = 0; i < numUsers; ++i) {
            delete users[i];
        }
        delete[] users;
    }

    void addQuestion(const Question& q) {
        if (numQuestions >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            Question* newQuestions = new Question[newCapacity];
            
            for (int i = 0; i < numQuestions; ++i) {
                newQuestions[i] = questions[i];
            }
            
            delete[] questions;
            questions = newQuestions;
            capacity = newCapacity;
        }
        
        questions[numQuestions++] = q;
    }

    void removeQuestion(int index) {
        if (index < 0 || index >= numQuestions) return;
        
        for (int i = index; i < numQuestions - 1; ++i) {
            questions[i] = questions[i + 1];
        }
        numQuestions--;
    }

    void addUser(QuizUser* user) {
        if (numUsers >= userCapacity) {
            int newCapacity = (userCapacity == 0) ? 1 : userCapacity * 2;
            QuizUser** newUsers = new QuizUser*[newCapacity];
            
            for (int i = 0; i < numUsers; ++i) {
                newUsers[i] = users[i];
            }
            
            delete[] users;
            users = newUsers;
            userCapacity = newCapacity;
        }
        
        users[numUsers++] = user;
    }

    void runQuizSession() {
        if (numQuestions == 0) {
            std::cout << "No questions available!\n";
            return;
        }

        if (numUsers == 0) {
            std::cout << "No users registered!\n";
            return;
        }

        std::cout << "\n=== Quiz Session ===\n";
        for (int i = 0; i < numUsers; ++i) {
            users[i]->takeQuiz(questions, numQuestions);
            users[i]->displayResults();
        }
    }

    void displayAllQuestions() {
        std::cout << "\n=== Current Questions ===\n";
        for (int i = 0; i < numQuestions; ++i) {
            std::cout << "Q" << (i+1) << ": " << questions[i].prompt << "\n";
            for (int j = 0; j < 4; ++j) {
                std::cout << "  " << (j+1) << ") " << questions[i].choices[j] << "\n";
            }
            std::cout << "Correct: " << (questions[i].correctIdx + 1) << "\n\n";
        }
    }
};

int main() {
    QuizEngine engine;

    // Add sample questions
    Question q1 = {"What is the capital of France?", 
                  {"London", "Paris", "Berlin", "Madrid"}, 1};
    Question q2 = {"Which planet is known as the Red Planet?",
                  {"Venus", "Mars", "Jupiter", "Saturn"}, 1};
    Question q3 = {"What is 2+2?",
                  {"3", "4", "5", "6"}, 1};

    engine.addQuestion(q1);
    engine.addQuestion(q2);
    engine.addQuestion(q3);

    // Create users
    PremiumUser premium("John_Doe");
    GuestUser guest("Visitor");

    engine.addUser(&premium);
    engine.addUser(&guest);

    // Menu system
    int choice;
    do {
        std::cout << "\n=== Quiz Engine Menu ===\n";
        std::cout << "1. Display All Questions\n";
        std::cout << "2. Add New Question\n";
        std::cout << "3. Remove Question\n";
        std::cout << "4. Run Quiz Session\n";
        std::cout << "5. Add New User\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                engine.displayAllQuestions();
                break;
                
            case 2: {
                Question newQ;
                std::cout << "Enter question prompt: ";
                std::cin.ignore();
                std::cin.getline(newQ.prompt, 100);
                
                std::cout << "Enter 4 choices:\n";
                for (int i = 0; i < 4; i++) {
                    std::cout << "Choice " << (i+1) << ": ";
                    std::cin.getline(newQ.choices[i], 40);
                }
                
                std::cout << "Enter correct choice index (1-4): ";
                std::cin >> newQ.correctIdx;
                newQ.correctIdx--; // Convert to 0-based index
                
                engine.addQuestion(newQ);
                break;
            }
                
            case 3: {
                int index;
                engine.displayAllQuestions();
                std::cout << "Enter question number to remove: ";
                std::cin >> index;
                engine.removeQuestion(index - 1);
                break;
            }
                
            case 4:
                engine.runQuizSession();
                break;
                
            case 5: {
                char name[50];
                int userType;
                std::cout << "Enter username: ";
                std::cin.ignore();
                std::cin.getline(name, 50);
                
                std::cout << "User type (1=Premium, 2=Guest): ";
                std::cin >> userType;
                
                if (userType == 1) {
                    engine.addUser(new PremiumUser(name));
                } else {
                    engine.addUser(new GuestUser(name));
                }
                break;
            }
        }
    } while (choice != 0);

    return 0;
}