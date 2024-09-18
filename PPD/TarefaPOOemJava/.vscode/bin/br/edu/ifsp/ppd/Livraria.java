import java.util.ArrayList;
import java.util.List;

public class Livraria 
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
}
