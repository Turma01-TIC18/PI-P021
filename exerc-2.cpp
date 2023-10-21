#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro {
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

    public:
        Livro(string _titulo,  string _autor, int _copias_disponiveis){
            titulo = _titulo;
            autor = _autor;
            copias_disponiveis = _copias_disponiveis;
        }
            

        string getTitulo() {
            return titulo;
        }
        
        static void adicionarLivro(string titulo, string autor, int copias_disponiveis) {
            livros.push_back(Livro(titulo, autor, copias_disponiveis));
        }

        static bool emprestarLivro(string titulo, string autor, string usuario) {
            for (Livro& livro : livros) {
                if (livro.getTitulo() == titulo && livro.autor == autor && livro.copias_disponiveis > 0) {
                    livro.copias_disponiveis--;
                    emprestimos.push_back({titulo, autor, usuario});
                    return true;
                }
            }
            return false;
        }
        
        static void listarLivros() {
            for (const Livro& livro : livros) {
                cout << "Título: " << livro.titulo << ", Autor: " << livro.autor
                        << ", Copias Disponíveis: " << livro.copias_disponiveis << endl;
            }
        }

        static void listarLivrosEmprestadosPorUsuario(string usuario) {
            for (const auto& emprestimo : emprestimos) {
                if (emprestimo.usuario == usuario) {
                    cout << "Título: " << emprestimo.titulo << ", Autor: " << emprestimo.autor << endl;
                }
            }
        }
};

vector<Livro> Livro::livros;
vector<Livro::Emprestimo> Livro::emprestimos;

class Usuario {
    private:
        string nome;
        static vector<Usuario> usuarios;
        
    public:
        Usuario(string _nome){
            nome = _nome;
        }

    static void registrarUsuario(string nome) {
        usuarios.push_back(Usuario(nome));
    }


};

vector<Usuario> Usuario::usuarios;

int main() {
    //testar funcionalidade testar adicionar livros
    Livro::adicionarLivro("Livro 1", "Autor 1", 3);
    Livro::adicionarLivro("Livro 2", "Autor 2", 2);
    // testar funcionalidade Registrar Usuario
    Usuario::registrarUsuario("Usuario 1");
    Usuario::registrarUsuario("Usuario 2");

    Livro::emprestarLivro("Livro 1", "Autor 1", "Usuário 1");
    Livro::emprestarLivro("Livro 2", "Autor 2", "Usuário 1");

    cout << "Livros disponíveis na biblioteca:\n";
    Livro::listarLivros();

    cout << "\nLivros emprestados por Usuário 1:\n";
    Livro::listarLivrosEmprestadosPorUsuario("Usuário 1");

    

    cout << " " << endl;

    return 0;
}

