#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
private:
    string nome;
    int idade;
public:
    void setNome(string nome_){nome = nome_;}
    string getNome(){return nome;}
    void setIdade(int idade_){idade = idade_;}
    int getIdade(){ return idade;}
};

class Estudante: public Person
{   
private:
    int matricula;
    string curso;

public:
    void setMatricula(int matricula_){ matricula = matricula_;}
    int getMatricula(){ return matricula;}
    void setCurso( string curso_){ curso = curso_;}
    string getCurso(){ return curso;}
};

class Professor: public Person
{
private:
    float salario;
public:
    void setSalario( float salario_){ salario = salario_;}
    float getSalario(){ return salario;}
    
};

class Turma
{
private:
    string nome;
    string materia;
    Estudante representante;
    vector<Estudante> alunos;
public: 
    void setNome(string nome_){nome = nome_;}
    string getNome(){return nome;}
    void setMateria(string materia_){materia= materia_;}
    string getMateriame(){return materia;}
    void setRepresentante(Estudante representante_){ representante = representante_;}
    Estudante getRepresentante() { return representante;}
    void addAlunos(Estudante novoAluno){ alunos.push_back(novoAluno);}
    
};

int main(int argc, char const *argv[])
{
    Estudante alunoUm, alunoDois;
    Professor professor;
    Turma turma;

    alunoUm.setNome("Joao Carlos");
    alunoUm.setIdade(21);
    alunoUm.setMatricula(666);
    alunoDois.setCurso("GES");
    alunoDois.setNome("Juliana");
    alunoDois.setIdade(19);
    alunoDois.setMatricula(222);
    alunoDois.setCurso("Fono");

    professor.setNome("Marcelo");
    professor.setIdade(34);
    professor.setSalario(4000.00);

   turma.setMateria("Marketing Digital");

   cout << alunoUm.getNome() << endl ;
   cout << alunoDois.getNome() << "\n";
   cout << professor.getNome() << "\n";


    return 0;
}