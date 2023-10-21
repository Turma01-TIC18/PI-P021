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
    
    static void AdicionarLivro(const string& titulo, const string& autor, int copias_disponiveis) {
        livros.push_back(Livro(titulo, autor, copias_disponiveis));
    }

    static bool EmprestarLivro(const string& titulo, const string& autor, const string& usuario) {
        for (Livro& livro : livros) {
            if (livro.getTitulo() == titulo && livro.autor == autor && livro.copias_disponiveis > 0) {
                livro.copias_disponiveis--;
                emprestimos.push_back({titulo, autor, usuario});
                return true;
            }
        }
        return false;
    }
    
    static void ListarLivros() {
        for (const Livro& livro : livros) {
            cout << "Título: " << livro.titulo << ", Autor: " << livro.autor
                      << ", Copias Disponíveis: " << livro.copias_disponiveis << endl;
        }
    }

 static void ListarLivrosEmprestadosPorUsuario(const string& usuario) {
        for (const auto& emprestimo : emprestimos) {
            if (emprestimo.usuario == usuario) {
                cout << "Título: " << emprestimo.titulo << ", Autor: " << emprestimo.autor << endl;
            }
        }
    }


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
    //testar funcionalidade testar adicionar livros
    Livro::AdicionarLivro("Livro 1", "Autor 1", 3);
    Livro::AdicionarLivro("Livro 2", "Autor 2", 2);
    // testar funcionalidade Registrar Usuario
    Usuario::RegistrarUsuario("Usuario 1");
    Usuario::RegistrarUsuario("Usuario 2");

    Livro::EmprestarLivro("Livro 1", "Autor 1", "Usuário 1");
    Livro::EmprestarLivro("Livro 2", "Autor 2", "Usuário 1");

    cout << "Livros disponíveis na biblioteca:\n";
    Livro::ListarLivros();

    cout << "\nLivros emprestados por Usuário 1:\n";
    Livro::ListarLivrosEmprestadosPorUsuario("Usuário 1");

    

    cout << " " << endl;

    return 0;
}

