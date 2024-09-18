public class Membro {
    private String nome;

    public void setNome(String _nome)
    {
        this.nome = _nome;
    }
    
    public void pegarLivroEmprestado(Livro _livro)
    {
        _livro.emprestar()
    }

    public void devolverLivro(Livro _livro)
    {
        _livro.devolverLivro();
    }

    @Override
    public void emprestar()
    {
        System.out.println("Emprestando o livro");
    }

    @Override
    public void devolverLivro()
    {
        System.out.println("Devolvendo o livro");
    }
}
