#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro {
public:
    Livro(const string& titulo, const string& autor, int copias_disponiveis)
        : titulo(titulo), autor(autor), copias_disponiveis(copias_disponiveis) {}

    string getTitulo() const {
        return titulo;
    }

    //adicionar livro

    //Emprestar livro

    //Listar livros

    //listar livros por usuário

private:
    string titulo;
    string autor;
    int copias_disponiveis;

    static vector<Livro> livros;
    struct Emprestimo {
        string titulo;
        string autor;
        string usuario;
    };
    static vector<Emprestimo> emprestimos;
};

vector<Livro> Livro::livros;
vector<Livro::Emprestimo> Livro::emprestimos;

class Usuario {
public:
    Usuario(const string& nome) : nome(nome) {}

    static void RegistrarUsuario(const string& nome) {
        usuarios.push_back(Usuario(nome));
    }

private:
    string nome;
    static vector<Usuario> usuarios;
};

vector<Usuario> Usuario::usuarios;

int main() {

    Livro::AdicionarLivro("Livro 1", "Autor 1", 3);
    Livro::AdicionarLivro("Livro 2", "Autor 2", 2);

    Usuario::RegistrarUsuario("Usuario 1");
    Usuario::RegistrarUsuario("Usuario 2");

    Livro::EmprestarLivro("Livro 1", "Autor 1", "Usuario 1");
    Livro::EmprestarLivro("Livro 2", "Autor 2", "Usuario 1");

    cout << "Livros disponiveis na biblioteca:\n";
    Livro::ListarLivros();

    cout << "\nLivros emprestados por Usuario 1:\n";
    Livro::ListarLivrosEmprestadosPorUsuario("Usuario 1");

    cout << " " << endl;

    return 0;
}

