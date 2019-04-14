import java.io.*;
import java.util.*;

class QuoteOfTheDayBackend
{
	protected Random generator;
	protected BufferedReader quotes;

	public int generateRandom(int range)
	{
		return generator.nextInt(range)+1;
	}

	public String getNthQuote(int n) throws IOException 
	{
		String line = null;
		for (int i = 0; i < n; ++i)
		{
			line = quotes.readLine();
			if (line == null)
				return "";
		}
		return line;
	}
}

class QuoteOfTheDayFileBackend extends QuoteOfTheDayBackend
{
	QuoteOfTheDayFileBackend() throws FileNotFoundException {
		Calendar c = Calendar.getInstance();
		int hour = c.get(Calendar.HOUR_OF_DAY);
		generator = new Random(c.get(Calendar.SECOND));
		//System.out.println(hour);
		if(hour>12)
		{
			quotes = new BufferedReader(new FileReader("Quotes.txt"));
		}
		else
		{
			quotes=new BufferedReader(new FileReader("Quotes1.txt"));
		}
	}
}

public class quotesd
{
	public static void main(String[] args) throws Exception {
		QuoteOfTheDayFileBackend qotdb = new QuoteOfTheDayFileBackend();
		int randomNo = qotdb.generateRandom(40);
		System.out.println(qotdb.getNthQuote(randomNo));
	}
}