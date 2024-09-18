public class Livro implements IEmprestavel
{
    private String titulo;
    private Autor autor;

    public String getTitulo()
    {
        return this.titulo;
    }

    public void setTitulo(String _titulo)
    {
        this.titulo = _titulo;
    }

    public void setAutor(Autor _autor)
    {
        this.autor = _autor;
    }

    public Autor getAutor()
    {
        return this.autor;
    }

    @Override
    public void emprestar()
    {
        System.out.println("Emprestando esse livro.");
    }

    @Override
    public void devolverLivro()
    {
        System.out.println("Devolvendo esse livro.");
    }
}
