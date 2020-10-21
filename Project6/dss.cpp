#include "dss.h"

dss::dss() {
    srand(std::time(0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0;; j++) {
            if (j == 7) j = 0;

            if (getSize(i) == 100) {
                break;
            }
            else if (getSize(i) > 100) {
                if (j < 6) {
                    arrayOfW[i][j + rand() % 2]--;
                }
                else {
                    arrayOfW[i][j]--;
                }
                
            }
            else if (getSize(i) < 100) {
                if (j < 6) {
                    arrayOfW[i][j + rand() % 2]++;
                }
                else {
                    arrayOfW[i][j]++;
                }
            }           
        }
    }
}

int dss::getSize(int index) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arrayOfW[index][i];
    }

    return sum;
}

std::pair<int, int> dss::getTrueFalse(int indexInVector) {
  int True = 0;
  int False = 0;
  
  auto veC = answ[indexInVector];

  for (auto iter : veC) {
      if (iter) {
        True++;
      }
      else if (iter == false) {
          False++;
      }
  }

  return std::make_pair(True, False);
}

void dss::study() {
    std::pair<int, int> pairTrueFlase;
     
    for (int counterOfStudy = 0; counterOfStudy < 10; counterOfStudy++) {
        for (int i = 0; i < 5; i++) {
            pairTrueFlase = getTrueFalse(i);
            auto vec = answ[i];

            for (int j = 0; j < N; j++) {
                if (vec[j]) {
                    if (pairTrueFlase.second > 0) {
                        if (arrayOfW[i][j] < 48) {
                            arrayOfW[i][j]++;
                            pairTrueFlase.second--;
                        }
                      
                    }
                }
                else if (vec[j] == false) {
                    if (pairTrueFlase.first > 0) {
                        if (arrayOfW[i][j] > 1) {
                            arrayOfW[i][j]--;
                            pairTrueFlase.first--;
                        }
                        
                    }
                }
            }
        }       
    }
}

bool dss::calc() {
    study();

    bool flagBiges = false;
    int counter = 0;
    int counterAnswT = 0;
    int counterAnswF = 0;
    int tmp = 0;
    auto it = userAnsw.begin();
    std::vector<int> statistic;

    for (auto iter : userAnsw) {
        if (iter) {
            counterAnswT++;
        }
        else if (iter == false) {
            counterAnswF++;
        }

    }

    if (counterAnswT == userAnsw.size()) {
        std::cout << "Введенi вiдповiдi не можуть допомогити в виборi мови програмування" << std::endl;
        std::cout << "Спробуйте знову" << std::endl;
        system("pause");
        system("cls");
        return false;
    }

    if (counterAnswF == userAnsw.size()) {
        std::cout << "Введенi вiдповiдi не можуть допомогити в виборi мови програмування" << std::endl;
        std::cout << "Спробуйте знову" << std::endl;
        system("pause");
        system("cls");
        return false;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            if (userAnsw[j]) {
                counter += arrayOfW[i][j];
            }          
        }
        statistic.push_back(counter);       
        counter = 0;
    }
    
    std::cout << "Оптимальна мова програмування для вас ->" << std::endl;
    std::cout << langs[std::distance(statistic.begin(), std::max_element(statistic.begin(), statistic.end()))] << "\n";
    
    statistic.clear();
    return true;
} 

void dss::input() {
    std::string answ = "";  

    while (true) {
        std::cout << "Введiть вiдповiдь -> ";
        answ = "";
        std::cin >> answ;

        if (answ == "yes" || answ == "y") {
            userAnsw.push_back(true);
            break;
        }
        else if (answ == "no" || answ == "n") {
            userAnsw.push_back(false);
            break;
        }
        else {
            std::cout << "Помилка вводу !!!" << std::endl;
            std::cout << "Введiть : yes|y або no|n" << std::endl;
        }
    }
}

void dss::userInterfase() {    
    std::cout << "Программа для допомоги вибору мови программування" << std::endl;
    for (auto iter : question) {
         std::cout << iter << std::endl;
         input();
    }
}

void dss::clearAnsw() {
    userAnsw.clear();
}