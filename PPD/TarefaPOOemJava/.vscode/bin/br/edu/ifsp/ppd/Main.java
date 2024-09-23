public class Main
{
    public static void main(String ... args)
    {
        Autor autor1 = new Autor();
        Livro livro1 = new Livro();
        Livro livro2 = new Livro();
        Membro membro1 = new Membro();
        Membro membro2 = new Membro();
        Livraria livraria1 = new Livraria();
        
        autor1.setNome("George RR Martin");

        livro1.setTitulo("A Guerra dos Tronos : Cap. 1");
        livro1.setAutor(autor1);

        livro2.setTitulo("A Guerra dos Tronos: Cap. 2");
        livro1.setAutor(autor1);

        livraria1.addLivro(livro1);
        livraria1.addLivro(livro2);
        System.out.println("Livros: " + livraria1.getLivros());
        livraria1.emprestarLivro(livro2, membro1);

        membro1.setNome("Douglas");
        membro2.setNome("Pedro");
        membro1.emprestar(livro2, membro2);
        membro1.devolverLivro(livro2);

        livraria1.devolver(livro2);
    }
}
