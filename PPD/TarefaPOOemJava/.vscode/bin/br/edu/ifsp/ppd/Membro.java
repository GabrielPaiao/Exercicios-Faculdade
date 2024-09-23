public class Membro implements IEmprestavel 
{
    private String nome;

    public void setNome(String _nome)
    {
        this.nome = _nome;
    }

    public String getNome()
    {
        return this.nome;
    }

    public void devolverLivro(Livro _livro)
    {
        this.devolver(_livro);
    }

    @Override
    public void emprestar(Livro _livro, Membro _membro)
    {
        System.out.println(this.nome + " esta emprestando seu livro ao membro " + _membro.getNome());
    }

    @Override
    public void devolver(Livro _livro)
    {
        System.out.println(this.nome + " - Devolvendo o livro '" + _livro.getTitulo() + "' emprestado.");
    }
}
