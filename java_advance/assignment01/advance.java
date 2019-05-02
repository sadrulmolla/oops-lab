import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class QuatoOfTheDay
{
	protected Random generator;
	protected BufferedReader qutoes;

	public int generaterandom(int range)throws IOException
	{
		return generator.nextInt(range)+1;
	}

	public String generateQutoes(int n)throws IOException
	{
		String line=null;
		for(int i=0;i<n;i++)
		{
			line=qutoes.readLine();
			if(line==null)
				return "";
		}
		return line;
	}

}

class QuotoOfTheDayFile extends QuatoOfTheDay
{
	QuotoOfTheDayFile()throws IOException
	{
		Calendar c = Calendar.getInstance();
		generator=new Random(c.get(Calendar.SECOND));
		int hour = c.get(Calendar.HOUR_OF_DAY);
		if(hour>=12)
		{
			qutoes= new BufferedReader(new FileReader("Qutoes.txt"));
		}
		else
		{
			qutoes= new BufferedReader(new FileReader("Qutoes1.txt"));
		}
	}
}

class BlinkLabel extends JLabel
{
	private static final long serialVersionUID = 1L;
	private static final int BLINKING_RATE = 1000; // in ms
	private boolean blinkingOn = true;
  
	public BlinkLabel(String text)
	{
		super(text);
		javax.swing.Timer timer = new javax.swing.Timer( BLINKING_RATE , new TimerListener(this));
    timer.setInitialDelay(0);
    timer.start(); 
	}
  
	public void setBlinking(boolean flag)
	{
		this.blinkingOn = flag;
	}
	public boolean getBlinking(boolean flag)
	{
    	return this.blinkingOn;
	}

  
	private class TimerListener implements ActionListener {
		private BlinkLabel bl;
		private Color bg;
    	private Color fg;
    	private boolean isForeground = true;
    
    	public TimerListener(BlinkLabel bl) {
    	this.bl = bl;
    	fg = bl.getForeground();
    	bg = bl.getBackground();
    }
 
    public void actionPerformed(ActionEvent e) {
    	if (bl.blinkingOn) {
        	if (isForeground) {
        	bl.setForeground(fg);
        }
        else {
        	bl.setForeground(bg);
        }
        isForeground = !isForeground;
      }
      else {
        // here we want to make sure that the label is visible
        // if the blinking is off.
        if (isForeground) {
        	bl.setForeground(fg);
        	isForeground = false;
        }
      }
    }
    
	}
}
 

class test
{
	private JFrame f;
	private JPanel p;
	private JButton b1;
	private BlinkLabel lab;

	test()
	{
		gui();
	}
	public String qutoes()throws IOException
	{
		QuotoOfTheDayFile qotd= new QuotoOfTheDayFile();
		int randomno=qotd.generaterandom(40);
		return qotd.generateQutoes(randomno);
	}
	public void gui()
	{
		f=new JFrame("Advance");
		f.setVisible(true);
		f.setSize(400,600);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		p=new JPanel();
		p.setBackground(Color.YELLOW);
		b1=new JButton("Click Here");
		lab=new BlinkLabel("");
		p.add(b1);
		p.add(lab);
		f.add(p);
		b1.addActionListener(new ActionListener()
		{  
			public void actionPerformed(ActionEvent e)
			{  
				try{
						String str1=qutoes();
						lab.setText(str1); 
					}
				catch(IOException ie){
					System.out.println("Exception Found");
				}
			}  
		}); 
	}
}
public class advance
{
	public static void main(String []args)throws IOException
	{
		new test();
	}
}