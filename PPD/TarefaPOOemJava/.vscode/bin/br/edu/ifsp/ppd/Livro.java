public class Livro
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
}
