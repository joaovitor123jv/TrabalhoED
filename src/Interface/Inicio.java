import java.awt.BorderLayout;
import java.awt.GridLayout;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.io.IOException; 


public class Inicio extends JFrame implements ActionListener{
	/**
	 * @param args the command line arguments
	 */
	public JPanel pnDados;
	public JPanel pnBotoes;

	public JLabel lbArquivo;

	public JTextField tfArquivo;

	public JButton btOk;
	public JButton btSair;



	Inicio()
	{
		pnDados = new JPanel();
		pnBotoes = new JPanel();


		this.setLayout(new BorderLayout());

		this.add(pnDados, BorderLayout.NORTH);
		this.add(pnBotoes, BorderLayout.SOUTH);

		pnDados.setLayout(new GridLayout(6, 1));
		pnBotoes.setLayout(new GridLayout(1, 3));

		lbArquivo= new JLabel("Digite o nome do arquivo:");

		tfArquivo = new JTextField(15);

		btOk = new JButton("Ok");
		btSair = new JButton("Sair");

		pnDados.add(lbArquivo); pnDados.add(tfArquivo);

		pnBotoes.add(btOk);
		pnBotoes.add(btSair);

		btOk.addActionListener(this);
		btSair.addActionListener(this);



		this.setSize(300, 300);
		this.setLocationRelativeTo(null);
		this.setTitle("Cadastro de veículos");
		this.setVisible(true);
		this.setDefaultCloseOperation(3);
	}


	public static void main(String[] args) {
		new Inicio();
	}

	@Override
		public void actionPerformed(ActionEvent e) 
		{
			if(e.getSource()== btSair)
				System.exit(0);
			if(e.getSource()==btOk)
			{
				int retorno;
				retorno = botaoOkPressionado();
				if(retorno == TipoRetorno.ERRO)
				{
					JOptionPane.showMessageDialog(null, "Ocorreu um erro durante o procesamento do arquivo\n");
				}
				else if(retorno == TipoRetorno.OK)
				{
					JOptionPane.showMessageDialog(null, "Arquivo testado com sucesso \n");
				}
				else if(retorno == TipoRetorno.ARQUIVO_NAO_EXISTE)
				{
					JOptionPane.showMessageDialog(null, "Arquivo não encontrado, verifique o nome do arquivo, arquivo está nessa pasta, ou tem permissão para abri-lo ? \n");
				}
			}

		}

	public int botaoOkPressionado()
	{
		String comando = "./executavel "+tfArquivo.getText();
		System.out.println("Nome do arquivo = |"+comando+"|");
		System.out.println("Chegou aqui sim");
		try
		{
			System.out.println("Parte 1, OK");
			Runtime run = Runtime.getRuntime();
			Process processo = run.exec(comando);
			try
			{
				processo.waitFor();
			}catch(InterruptedException e){}
			System.out.println("Parte 2, também");
			int retorno;
			retorno = processo.exitValue();
			System.out.println("Retorno = "+retorno);
			return retorno;

		}catch(IOException ex){}
		return TipoRetorno.ERRO;
	}
}

