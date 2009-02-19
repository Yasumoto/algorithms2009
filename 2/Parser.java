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

		try 
		{
			in = new BufferedReader(new FileReader(filename));
			while (line != null)
			{
				line = in.readLine();
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
}
