#ifndef EXERCICIOS_IGOR_HPP
#define EXERCICIOS_IGOR_HPP

#include<iostream>
#include<tuple>
#include<string>

using namespace std;

int fatorial(int n);
int fibonacci(int n);

// exemplo útil: 
// ler N numeros e retornar a soma desses números
int exemplo(const char* cstr) {
  int n, count;
  sscanf(cstr, "%d%n", &n, &count); cstr += count;
  //cout << "count=" << count << endl;

  int s = 0;
  while(n--) {
    int v = 0;
    sscanf(cstr, "%d%n", &v, &count); cstr += count;
    s += v;
    //cout << "v=" << v << endl;
  }
  return s;
}

// resolução exercício 0
int exercicio0(const char* cstr) {
  return 0;
}

// resolução exercício 1
int exercicio1(const char* cstr) {
  int a,b;
  sscanf(cstr, "%d %d",&a, &b);
  int s = 0;
  for(int i=a; i<=b; i++)
    s+=i;
  return s;
}

// resolução exercício 2
int exercicio2(const char* cstr) {
  int size, count;
  sscanf(cstr, "%d%n", &size, &count); cstr += count;
  //cout << "count=" << count << endl;

  int candidates = 3;
  int votesByCandidate[candidates + 1] = { 0 }; // Candidates plus null vote

  tuple<int, int> winner = make_tuple(0, 0); // Tuple with Winner candidate id and winner candidate vote count respectively

  while(size--) {
    int vote;
    sscanf(cstr, "%d%n", &vote, &count); cstr += count;

    if(vote >= 0 && vote <= candidates) {
      votesByCandidate[vote] += 1;

      if(votesByCandidate[vote] > get<1>(winner)) {
        winner = make_tuple(vote, votesByCandidate[vote]);
      } else if(votesByCandidate[vote] == get<1>(winner)) { // When it`s a draw, null is the winner
        get<0>(winner) = 0;
      }
    }
  }
  
  return get<0>(winner);
}

// resolução exercício 3
auto exercicio3(const char* cstr) {
  int size, count;
  sscanf(cstr, "%d%n", &size, &count); cstr += count;

  double sum = 0;
  double min;
  double max;

  for(int i = 0; i < size; i++) {
    double number;
    sscanf(cstr, "%lf%n", &number, &count); cstr += count;

    sum+=number;

    if(i == 0) {
      min = number;
      max = number;
      continue;
    }

    if(number < min) {
      min = number;
    }

    if(number > max) {
      max = number;
    }
  }

  return make_tuple(sum, sum/size, max, min); // SUM / AVERAGE / MAX / MIN
}

// resolução exercício 4
int exercicio4(const char* cstr) {
  int size, count;
  sscanf(cstr, "%d%n", &size, &count); cstr += count;

  if(size < 1) {
    size = 1;
  } else if (size > 100) {
    size = 100;
  }

  tuple<double, string> students[size];

  for(int i = 0; i < size; i++) {
    double grade;

    char nameChar[256];
    sscanf(cstr, "%lf%256s%n", &grade, nameChar, &count); cstr += count;
    string name = nameChar;

    if(grade < 0) {
      grade = 0;
    } else if (grade > 10) {
      grade = 10;
    }

    students[i] = make_tuple(grade, name);
  }

  int k;
  sscanf(cstr, "%d", &k);

  if(k < 1) {
    k = 1;
  } else if (k > size) {
      k = size;
  }

  return get<0>(students[k-1]) >= 6.0;
}

// resolução exercício 5
int exercicio5(const char* cstr) {
  int n;
  sscanf(cstr, "%d", &n);
  
  return fatorial(n);
}

int fatorial(int n) {
  if (n == 0) {
    return 1;
  }
  else {
    return (n * fatorial(n - 1));
  }
}

// resolução exercício 6
int exercicio6(const char* cstr) {
  int k;
  sscanf(cstr, "%d", &k);

  return fibonacci(k);
}

int fibonacci(int n) {
  if(n == 0 || n == 1) {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

// resolução exercício 7
char exercicio7(const char* cstr) {
  int n, count;
  sscanf(cstr, "%d%n", &n, &count); cstr += count;

  int winsByUser[3] = { 0 };
  char user[3] = {'X', 'M', 'J'};

  tuple<char, int> winner = make_tuple('X', 0);

  while(n--) {
    char p1;
    char p2;
    sscanf(cstr, " %c %c%n", &p1, &p2, &count); cstr += count;

    int idUser;

    if(p1 == 't' && p2 == 'p' || p1 == 'p' && p2 == 'd' || p1 == 'd' && p2 == 't') {  // Jogador 1 vence
      idUser = 1;
    } else if(p2 == 't' && p1 == 'p' || p2 == 'p' && p1 == 'd' || p2 == 'd' && p1 == 't') { // Jogador 2 vence
      idUser = 2;
    } else {
      idUser = 0; // Empate
    }

    winsByUser[idUser]++;

    if(winsByUser[idUser] > get<1>(winner)) {
      winner = make_tuple(user[idUser], winsByUser[idUser]);
    } else if(winsByUser[idUser] == get<1>(winner)) {
      get<0>(winner) = 'X';
    }
  }

  return get<0>(winner);
}

// resolução exercício 8
auto exercicio8(const char* cstr) {
  int a, b;
  sscanf(cstr, "%d%d", &a, &b);

  int *aux;

  *aux = b;
  b = a;
  a = *aux;

  return make_tuple(a, b);
}

float exercicio9(const char* cstr) {
  int size, count, aux;
  sscanf(cstr, "%d%n", &size, &count); cstr += count;

  int numbers[size];

  for(int i = 0; i < size; i++) {
    sscanf(cstr, "%d%n", &numbers[i], &count); cstr += count;
  }

  for(int i = 0; i < size; i++) {
    for(int j = i + 1; j < size; j++) {
      if(numbers[i] > numbers[j]) {
        int aux = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = aux;
      }
    }
  }

  if(size % 2 == 0) {
    return ((float)numbers[size / 2 - 1] + (float)numbers[size / 2]) / 2;
  }

  return (float)numbers[size/2];
}

#endif // EXERCICIOS_IGOR_HPP