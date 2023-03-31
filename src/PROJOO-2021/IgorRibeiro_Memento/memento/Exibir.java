package memento;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class Exibir extends JFrame {
	JPanel jp = new JPanel();
	JTextArea jt = new JTextArea(10,10);
	JTextField tf = new JTextField(10);
	JButton b = new JButton("Enter");
	JButton b2 = new JButton("Desfazer");
	
	public Exibir() {
		setTitle("Teste");
		setVisible(true);
		setSize(600,600);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		jt.setEditable(false);
		jp.add(tf);
		jp.add(b);
		jp.add(b2);
		jp.add(jt);
		add(jp);
		
		Zelador zelador = new Zelador();
		Fonte fonte = new Fonte("", zelador);
		
		
		b.addActionListener((ActionListener) new ActionListener() { 
			  public void actionPerformed(ActionEvent e) { 
			    //System.out.println("botao clicado");
				  String texto;
				  texto = tf.getText().toString();
				  String bckp;
				  bckp = jt.getText().toString();
				  fonte.setTxt(bckp);
				  fonte.createSave(bckp);
				  
				  tf.setText("");
				  jt.setText(texto);
				  
				  
			  } 
			} );
		
		b2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fonte.desfazer();
				String txt = fonte.getTxt();
				System.out.println(txt);
				tf.setText("");
				jt.setText(txt);
			}
		});
	} 
}
