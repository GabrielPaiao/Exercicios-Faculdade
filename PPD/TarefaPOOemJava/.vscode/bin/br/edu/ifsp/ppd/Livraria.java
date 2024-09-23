import java.util.ArrayList;
import java.util.List;

public class Livraria implements IEmprestavel 
{
    private List<Livro> livros = new ArrayList<>();

    public void addLivro(Livro _livro)
    {
        this.livros.add(_livro);
    }

    public List<Livro> getLivros()
    {
        return this.livros;
    }

    public void emprestarLivro(Livro _livro, Membro _membro)
    {
        this.emprestar(_livro, _membro);
    }

    @Override
    public void emprestar(Livro _livro, Membro _membro)
    {
        System.out.println("Emprestando '" + _livro.getTitulo() + "' ao membro " + _membro.getNome());
    }

    @Override
    public void devolver(Livro _livro)
    {
        System.out.println("A livraria esta devolvendo o livro '" + _livro.getTitulo() + "' ao seu fornecedor.");
    }
}
