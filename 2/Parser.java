/*
 * Parser.java
 * Joe Smith
 * Algorithms - Spring 2009
 * Erik Linstead
 * Chapman University
 * Released under GPLv2 or later.
 */

import java.io.*;

public class Parser{
	public Parser(String filename){
		BufferedReader in;
		String line = "";
		FiniteStateAutomata FSA = new FiniteStateAutomata();

		try 
		{
			in = new BufferedReader(new FileReader(filename));

			/*
			 * This algorithm (hopefully) doesn't need the list of states
			 */

			line = in.readLine();

                        /*
			 * To find the characters
			 */
			line = in.readLine();
			FSA.Alphabet = parseAlphabet(line);

			while (line != null)
			{
				System.out.println(line);
			}
		}
 		catch (FileNotFoundException e)
 		{
	 		e.printStackTrace();
 		}
 		catch (IOException e) 
 		{
	 		e.printStackTrace();
 		}
	}

	private String[] parseAlphabet(String line)
	{
		String[] alpha = {};
		line = line.replace('{', ' ');
		line = line.replace('}', ' ');
                alpha = line.split("\t");

		for (int i = 0; i < alpha.length; ++i)
		{
			System.out.println(alpha[i]);
		}

		return alpha;
	}

}
